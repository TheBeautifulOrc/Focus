#include "event.hpp"

namespace focus
{
	Event::Event(const std::string& _name) : name{_name}
	{
	}

	InputEvent::InputEvent(const std::string& _name) : Event(_name)
	{
	}

} // namespace focus
