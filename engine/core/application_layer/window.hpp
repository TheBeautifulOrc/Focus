// window.hpp

#pragma once

namespace focus
{
	class InstanceGLFW
	{
	private:
		static void errorCallback(int error, const char* errorDescription);

	public:
		InstanceGLFW();
		~InstanceGLFW();

		InstanceGLFW(const InstanceGLFW&) = delete;
		void operator=(const InstanceGLFW&) = delete;
	};

	auto getInstanceGLFW() -> InstanceGLFW&;
	
} // namespace focus
