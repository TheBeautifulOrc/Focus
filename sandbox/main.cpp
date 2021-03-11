#include <iostream>
#include "engine/core.hpp"

//Debug
#include "spdlog/sinks/basic_file_sink.h"

using std::cout, std::endl, std::boolalpha;
using namespace focus;

int main(int argc, char** argv)
{
	Application app;
	Logger logger(Logger::Type::Console, "Main");

	return 0;
}