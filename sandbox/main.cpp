#include <iostream>
#include "engine/core.hpp"

using std::cout, std::endl;
using namespace focus;

int main(int argc, char** argv)
{
	Application app("Sandbox Game");
	app.info("Hello Game");
	auto win_man = app.add_subcomponent(std::make_unique<WindowManager>("Window Manager", app.get_logger()));
	win_man->info("Window Manager active");

	return 0;
}