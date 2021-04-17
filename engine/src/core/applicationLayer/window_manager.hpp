// window.hpp

#pragma once

#include "../engine_component.hpp"

namespace focus
{
	class Logger;

	/**
	 * Manager of application windows.
	 *
	 * This class is meant as an abstraction level and interface between the Focus Engine and any external window library it may use. At the moment only GLFW is supported but this may change in the future. Each application written with the Focus Engine typically has one WindowManager object associated with it.
	 */
	class WindowManager : public EngineComponent
	{
	public:
		/**
		 * WindowManager constructor.
		 *
		 * @param _name Name of this object.
		 * @param _logger Logger this object should use.
		 */
		WindowManager(
			std::string _name,
			std::shared_ptr<ILogger> _logger
		);
		~WindowManager();

	private:
		/**
		 * Callback function for GLFW.
		 *
		 * Provides a callback for any error GLFW might encounter. Not to be called manually.
		 *
		 * @param error GLFW error code.
		 * @param error_description GLFW error message.
		 */
		static void _glfw_error_callback(int error, const char* error_description);
	};

} // namespace focus
