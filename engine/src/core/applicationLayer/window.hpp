// window.hpp

#pragma once

#include "../engine_component.hpp"

namespace focus
{
	class Logger;
	class WindowManager : public EngineComponent
	{
	private:
		static void error_callback(int error, const char* error_description);

	public:
		WindowManager(std::string _name="WindowManager");
		~WindowManager();
	};

} // namespace focus
