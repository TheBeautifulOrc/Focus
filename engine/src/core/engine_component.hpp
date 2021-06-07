#pragma once

#include <string>
#include <memory>
#include <functional>
#include <set>
#include <map>

#include "core/event_system/event_handler.hpp"
#include "core/logging_system/logger.hpp"
#include "core/basics/hierarchy.hpp"

namespace focus
{
	class IEngineComponent;
	template<typename C>
	concept EngineComponentSubtype = requires(C comp)
	{
		std::is_base_of<IEngineComponent, C>();
	};

	/**
	 * @brief Basic component of the Focus Engine.
	 *
	 * Every other class that makes up the Focus Engine should (if possible) be a subclass of this. This class provides basic functionalities like logging and integration into the event system.
	 */
	class IEngineComponent : public IEventHandler, public IHierarchyElement<IEngineComponent>
	{
	public:
		/**
		 * @brief Returns logger of this object.
		 *
		 * @return Logger of this object. Can be taken partial ownership of.
		 */
		inline auto get_logger() const -> std::shared_ptr<ILogger> { return logger; }

		/**
		 * @brief Logs info-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void info(const std::string& msg) const override { logger->info(name, msg); }

		/**
		 * @brief Logs warning-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void warning(const std::string& msg) const override { logger->warning(name, msg); }

		/**
		 * @brief Logs error-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void error(const std::string& msg) const override { logger->error(name, msg); }

		/**
		 * @brief Returns name of this object.
		 *
		 * @return Name of this object.
		 */
		inline auto get_name() const -> const std::string& { return name; }

		/**
		 * @brief Template specialization for adding subcomponents based on this class.
		 *
		 * @param new_comp New component to add
		 */
		template<EngineComponentSubtype C>
		inline auto add_subcomponent(std::shared_ptr<C> new_comp) -> std::shared_ptr<C>
		{
			auto key = new_comp->get_name();
			subcomponents.insert({ key, new_comp });
			return get_subcomponent<C>(key);
		}

	private:
		// Name of this object.
		std::string name;
		// Instance of the logger this object uses to log its messages.
		std::shared_ptr<ILogger> logger;

	protected:
		/**
		 * Engine component constructor. Not to be called directly.
		 *
		 * @param _name Name of this object.
		 * @param _logger Logger instance that this object shall use for its logging.
		 */
		IEngineComponent(
			const std::string& _name,
			std::shared_ptr<ILogger> _logger
		);

	public:
		virtual ~IEngineComponent() = default;
	};

} // namespace focus