#pragma once

#include <string>

namespace focus
{
	class IEvent
	{
	public:
		IEvent(const std::string& _name="event", const uint8_t _priority=0) : name{_name}, priority{_priority} {}
		virtual ~IEvent() = default;

		inline virtual auto get_priority() const -> uint8_t { return priority; }

	protected:
		std::string name;
		uint8_t priority = 0;
	};

	class InputEvent : public IEvent
	{
	public:
		InputEvent(const std::string& _name="input_event");
		~InputEvent() = default;
	};

} // namespace focus
