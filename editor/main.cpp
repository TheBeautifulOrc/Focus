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
	auto renderer = app.add_subcomponent(std::make_unique<RendererVulkan>("Vulkan Renderer", &app, app.get_logger()));
	auto window = app.add_subcomponent(std::make_unique<WindowGLFW>("GLFW Window", "Focus Engine Editor", glm::u16vec2(1280, 720), app.get_logger()));

	std::cin.get();

	return 0;
}