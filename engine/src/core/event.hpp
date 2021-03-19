#pragma once

#include <string>

namespace focus
{
	class Event
	{
	protected:
		std::string name;
	public:
		Event(const std::string& _name="event");
		~Event() = default;
	};

	class EventDispatcher
	{
	protected:

	public:
		EventDispatcher();
		~EventDispatcher();
	};

	class InputEvent : public Event
	{
	protected:

	public:
		InputEvent(const std::string& _name="input_event");
		~InputEvent() = default;
	};

} // namespace focus
