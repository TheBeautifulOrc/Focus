###
# Top-level SCons script
###

# pylint: skip-file

env = Environment(
	CC = 'g++',
	CCFLAGS = ['-std=c++17']
)

SConscript(
	['engine/core/SConscript'],
	exports = ['env']
)