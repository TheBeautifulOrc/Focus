#include "event_handler.hpp"

#include "event.hpp"

namespace focus
{
	IEventHandler::~IEventHandler()
	{
		/* Disconnect from other EventHandlers */

		// Remove self from source list of all targets
		for (auto target : event_targets)
		{
			target->event_sources.erase(this);
		}
		// Remove self from target list of all sources
		for (auto source : event_sources)
		{
			source->event_targets.erase(this);
		}
	}

	void IEventHandler::subscribe(IEventHandler* handler)
	{
		event_sources.insert(handler);
		handler->event_targets.insert(this);
	}

	void IEventHandler::unsubscribe(IEventHandler* handler)
	{
		event_sources.erase(handler);
		handler->event_targets.erase(this);
	}

	void IEventHandler::dispatch_event(EventPtr event)
	{
		if (event->get_priority() < 255)
		{
			for (auto& target : event_targets)
			{
				target->event_queue.push(event);
			}
		}
		else	// Priority at max. level.
		{
			for (auto target : event_targets)
			{
				target->process_event(event);
			}
		}
	}

	void IEventHandler::process_queue_top()
	{
		process_event(event_queue.top());
		event_queue.pop();
	}

} // namespace focus
