// window.hpp

#pragma once

#include "../core_component.hpp"

namespace focus
{
	class Logger;
	class WindowManager : public CoreComponent
	{
	private:
		static void error_callback(int error, const char* error_description);

	public:
		WindowManager(std::string _name="WindowManager");
		~WindowManager();
	};

} // namespace focus
