#include <iostream>
#include "engine/core.hpp"

using std::cout, std::endl, std::boolalpha;
using namespace focus;

int main(int argc, char** argv)
{
	Application app{"Sandbox Game"};
	app.get_logger().info("Hello Game");
	return 0;
}