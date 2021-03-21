#pragma once

#include <string>

namespace focus
{
	class Event
	{
	public:
		Event(const std::string& _name="event");
		~Event() = default;

	protected:
		std::string name;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher();
		~EventDispatcher();
	};

	class InputEvent : public Event
	{
	public:
		InputEvent(const std::string& _name="input_event");
		~InputEvent() = default;
	};

} // namespace focus
