#pragma once

#include <memory>
#include <queue>
#include <set>
#include <vector>
#include <functional>

#include "core/event_system/event.hpp"

namespace focus
{
	/**
	 * @brief Handler that dispatches and reacts to events.
	 *
	 * Can dispatch events and subscribe to other IEventHandlers to receive events dispatched by them. Will react to events it receives. Events with maximum priority will be processed immediately others will be stored in a queue and processed later, beginning with the highest-priority one.
	 */
	class IEventHandler
	{
		using EventComperator = std::function<bool(const std::shared_ptr<const IEvent>&, const std::shared_ptr<const IEvent>&)>;
		using EventQueue = std::priority_queue<std::shared_ptr<const IEvent>, std::vector<std::shared_ptr<const IEvent>>, EventComperator>;

	protected:
		IEventHandler() = default;

	public:
		virtual ~IEventHandler();

		/**
		 * @brief Event callback function.
		 *
		 * Callback function that handles events. Does nothing by default. Can be overridden in subclasses to add custom reactions to events. Can be overloaded in subclasses to add specialised behavior for certain event subtypes.
		 *
		 * @param event Event that this object should react to.
		 */
		virtual inline void process_event(std::shared_ptr<const IEvent> event) {};

		/**
		 * @brief Invokes 'process_event' fuction on event at the top of the event queue.
		 */
		virtual void process_queue_top();

		/**
		 * @brief Push event to the event targets, so that they may react to them.
		 *
		 * @param event Event to dispatch to the targets.
		 */
		virtual void dispatch_event(std::shared_ptr<const IEvent> event);

		/**
		 * @brief Subscribe to the events of another EventHandler.
		 *
		 * @param handler Handler to subscribe to.
		 */
		virtual void subscribe(IEventHandler* handler);

		/**
		 * @brief Unsubscribe from the events of another EventHandler.
		 *
		 * @param handler Handler to unsubscribe from.
		 */
		virtual void unsubscribe(IEventHandler* handler);

		/**
		 * @brief Get number of unprocessed events in event queue.
		 */
		virtual inline auto get_queue_size() const -> size_t { return event_queue.size(); }

	private:
		/* Connections to other event handlers: */

		// Addresses of all EngineComponents that shall react on this objects events.
		std::set<IEventHandler*> event_targets;

		// Addressed of all EngineComponents whose event will be processed by this one.
		std::set<IEventHandler*> event_sources;

		/* Event queueing: */

		// Function to sort queued events by priority.
		EventComperator sort_events_by_priority =
			[](const std::shared_ptr<const IEvent>& lhs, const std::shared_ptr<const IEvent>& rhs)
		{
			return lhs->get_priority() < rhs->get_priority();
		};

		// Queue for all buffered events.
		EventQueue event_queue = EventQueue(sort_events_by_priority);
	};

} // namespace focus
