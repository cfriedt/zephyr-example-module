#!/usr/bin/env python3

import argparse
import datetime
import os
import re
import sys

class BootStrap(object):

    @staticmethod
    def id_valid(s):
        # user and project can both be verified using the same regex
        # - reference: https://github.com/shinnn/github-username-regex
        # - no spaces
        # - no special characters other than dash ('-')
        # - lowercase
        # - dashes are only allowed internally
        # - must start with letter
        return True

    @staticmethod
    def check(dir, map):
        if not BootStrap.id_valid(map['user']):
            raise ValueError('Invalid user id "{}"'.format(map['user']))

        if len(map['name']) == 0:
            raise ValueError('Invalid name "{}"'.format(map['name']))

        if not BootStrap.id_valid(map['project']):
            raise ValueError('Invalid project id "{}"'.format(map['project']))

        if len(map['module']) == 0:
            raise ValueError('Invalid module name "{}"'.format(map['module']))

    def __init__(self, args):
        from_map = {}
        # TODO: extract "from" values from a .bootstrap file or something along those lines
        # That way, it would be possible to use this tool over and over again for other
        # repositories.
        from_map['user'] = 'cfriedt'
        from_map['name'] = 'Friedt Professional Engineering Services, Inc'
        from_map['project'] = 'zephyr-example-module'
        from_map['uscore'] = from_map['project'].replace('-', '_')
        from_map['module'] = 'Zephyr Example Module'
        from_map['year'] = '2020'

        to_map = {}
        to_map['user'] = args.user.strip()
        to_map['name'] = args.name.strip()
        to_map['project'] = args.project.strip()
        to_map['uscore'] = to_map['project'].replace('-', '_')
        to_map['module'] = args.module.strip()
        to_map['year'] = '{}'.format(datetime.datetime.now().year)

        BootStrap.check(args.dir, to_map)

        self._dir = os.path.abspath(args.dir)
        self._from = from_map
        self._to = to_map

    @staticmethod
    def fsubst(path, fro, to):
        if fro == to:
            return
        for root, dirs, files in os.walk(path):
            for d in dirs:
                if d == '.' or d == '..' or d == '.git':
                    continue
                BootStrap.fsubst(os.path.join(path, d), fro, to)
            for fn in files:
                if fn == 'bootstrap.py':
                    continue
                content = None
                with open(os.path.join(path, fn), 'r') as f:
                    content = f.read()
                if content.find(fro) == -1:
                    continue
                content = content.replace(fro, to)
                with open(os.path.join(path, fn), 'w') as f:
                    f.write(content)
            break

    @staticmethod
    def frename(path, fro, to):
        if fro == to:
            return
        for root, dirs, files in os.walk(path):
            for d in dirs:
                if d == '.' or d == '..' or d == '.git':
                    continue
                BootStrap.frename(os.path.join(path, d), fro, to)
                if fro not in d:
                    continue
                d2 = d.replace(fro, to)
                if os.path.exists(os.path.join(path, d2)):
                    raise ValueError('path {} already exists!'.format(os.path.join(path, d2)))
                os.rename(os.path.join(path, d), os.path.join(path, d2))
            for fn in files:
                if fro not in fn:
                    continue
                fn2 = fn.replace(fro, to)
                if os.path.exists(os.path.join(path, fn2)):
                    raise ValueError('path {} already exists!'.format(os.path.join(path, fn2)))
                os.rename(os.path.join(path, fn), os.path.join(path, fn2))
            break

    @staticmethod
    def recursive_remove(path):
        for root, dirs, files in os.walk(path):
            for d in dirs:
                recursive_remove(os.path.join(path, d))
            for f in files:
                os.remove(os.path.join(path, f))
            os.remove(root)
            break

    def run(self):

        # rename files whose names include  self._from['project'] or self._from['uscore']
        BootStrap.frename(self._dir, self._from['project'], self._to['project']);
        BootStrap.frename(self._dir, self._from['uscore'], self._to['uscore']);

        # next, we're looking at file content
        # We'll be doing string substitution for
        # user, name, project, uscore, module, and year
        for key in ['user', 'name', 'project', 'uscore', 'module', 'year']:
            BootStrap.fsubst(self._dir, self._from[key], self._to[key])

        # TODO (probably best to use shutil and pygit for this stuff)
        # recursive_remove(os.path.join(self._dir, '.git'))
        # git init -b zephyr in new dir
        # git remote add origin 'git@github.com:{}/{}.git'.format(user, project)
        # os.rename(self._dir, parent(self._dir) + '/' + project)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-u', '--user', help='GitHub user id (e.g. adent)', required=True)
    parser.add_argument('-n', '--name', help='Name of copyright holder (e.g. "Arthur Dent")', required=True)
    parser.add_argument('-p', '--project', help='GitHub project name (e.g. babelfish-driver)', required=True)
    parser.add_argument('-m', '--module', help='Module name (e.g. "Babelfish Driver")', required=True)
    parser.add_argument('dir', help='the root directory of the project')

    try:
        args = parser.parse_args()
        bs = BootStrap(args)
        bs.run()
    except Exception as e:
        raise

    sys.exit(0)
