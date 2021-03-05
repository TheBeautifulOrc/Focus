# pylint: skip-file

env = Environment(
	CC = 'g++',
	CCFLAGS = ['-std=c++17']
)

SConscript(
	['engine/SConscript'],
	exports = ['env']
)