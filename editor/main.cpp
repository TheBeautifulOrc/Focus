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
	Application app("Focus Editor", VersionNumber(0,1,0));
	auto renderer = app.add_subcomponent(std::make_unique<RendererVulkan>("Vulkan Renderer", app.get_logger(), &app));

	return 0;
}