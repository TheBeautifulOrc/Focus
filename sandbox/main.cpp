#include <iostream>
#include "engine/core.hpp"

using std::cout, std::endl;
using namespace focus;

template<typename T>
void print_type(const T& thing)
{
	cout << typeid(thing).name() << endl;
}

int main(int argc, char** argv)
{
	Application app("Sandbox Game");
	app.info("Hello Game");
	auto& win_man = app.add_subcomponent(
		std::make_unique<WindowManager>("Window Manager", app.get_logger())
	);
	win_man->info("Active");

	return 0;
}