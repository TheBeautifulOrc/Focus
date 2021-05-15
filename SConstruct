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

# Find all SConscript files
sconscripts = []
for folder in folders:
	sconscripts.extend(Glob(join(folder, 'SConscript')))

# Environment settings
env = Environment(
	CC='g++',
	CCFLAGS=['-std=c++20', '-g', '-fdiagnostics-color=always'],
	CPPPATH=['#engine/include', '#engine/src'],
	LIBPATH=['#engine/shared']
)

# Execute SConscripts
SConscript(
	sconscripts,
	exports = ['env']
)