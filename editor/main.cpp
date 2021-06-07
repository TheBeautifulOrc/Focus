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
	// Create application
	Application app("Focus Editor", VersionNumber(0,1,0));

	// Intialize Vulkan renderer
	auto renderer = std::make_shared<RendererVulkan>("Vulkan Renderer", &app, app.get_logger());
	app.add_subcomponent(renderer);

	// Initialize GLFW application window
	auto window = std::make_shared<WindowGLFW>("GLFW Window", "Focus Engine Editor", glm::u16vec2(1280, 720), renderer, app.get_logger());
	app.add_subcomponent(window);

	return 0;
}