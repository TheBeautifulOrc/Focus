#pragma once

#include <set>

#include "event.hpp"

namespace focus
{
	class EventHandler
	{
	public:
		EventHandler() = default;
		~EventHandler() = default;

		/**
		 * Event callback function.
		 *
		 * Callback function that handles events. Does nothing by default. Can be overridden in subclasses to add custom reactions to events. Can be overloaded in subclasses to add specialised behavior for certain event subtypes.
		 *
		 * @param event Event that this object should react to.
		 */
		virtual inline void event_callback(Event& event) {};

	protected:
		// Addresses of all EngineComponents that shall react on this objects events.
		std::set<EventHandler*> event_recipients;
	};

} // namespace focus
