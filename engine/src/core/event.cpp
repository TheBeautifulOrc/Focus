#include "event.hpp"

namespace focus
{
	Event::Event(const std::string& _name) : name{_name}
	{
	}

	EventDispatcher::EventDispatcher()
	{
	}

	EventDispatcher::~EventDispatcher()
	{
	}

	InputEvent::InputEvent(const std::string& _name) : Event(_name)
	{
	}

} // namespace focus
