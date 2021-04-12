#pragma once

#include <string>

namespace focus
{
	/**
	 * @brief Events that signal certain incidents within an application.
	 */
	class IEvent
	{
	public:
		IEvent(const std::string& _name="event", const uint8_t _priority=0) : name{_name}, priority{_priority} {}
		virtual ~IEvent() = default;

		/**
		 * @brief Get the priority of this event.
		 *
		 * @return The priority of this event. Events with higher priorities will be handled earlier. (0 - lowest; 254 - highest, non interrupt; 255 - interrupt)
		 */
		inline virtual auto get_priority() const -> uint8_t { return priority; }

	protected:
		std::string name;
		uint8_t priority = 0;
	};

} // namespace focus
