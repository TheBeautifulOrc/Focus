###
# Top-level SCons script
###

# pylint: skip-file

import os
from os.path import join

# Get all folders inside the project
def getSubdirs(path):
	lst = [join(path, name) for name in os.listdir(path) if os.path.isdir(join(path, name)) and name[0] != '.']
	append_list = []
	for subpath in lst:
		append_list.extend(getSubdirs(subpath))
	lst.extend(append_list)
	return lst

folders = sorted(getSubdirs('.'))

# Find relevant files and locations
sconscripts = []
includePaths = []
for folder in folders:
	sconscripts.extend(Glob(join(folder, 'SConscript')))
	if any([f.endswith(('.h', '.hpp')) for f in os.listdir(folder)]):
		includePaths.append('#'+folder)

# Environment settings
env = Environment(
	CC='g++',
	CCFLAGS=['-std=c++17'],
	CPPPATH=includePaths,
	LIBPATH=['#/build/lib']
)

# Binary destination
buildPath = '#build'
libPath = join(buildPath, 'lib')

# Execute SConscripts
SConscript(
	sconscripts,
	exports = ['env', 'buildPath', 'libPath']
)