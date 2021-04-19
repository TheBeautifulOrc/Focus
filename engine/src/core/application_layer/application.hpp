#pragma once

#include <memory>
#include "core/engine_component.hpp"
#include "core/logging_system/spdlogger.hpp"

namespace focus
{
	class WindowManager;

	/**
	 * @brief Base class for applications created with the Focus Engine.
	 *
	 * This class serves as a starting point for all applications (games and other) that shall be created with the help of the Focus Engine.
	 */
	class Application : public IEngineComponent
	{
	public:
		/**
		 * @brief Application constructor.
		 *
		 * @param _name Name of this object. Defaults to "app".
		 * @param _logger Logger instance that this object shall use for its logging. If unspecified a new (default) instance of Logger will be created.
		 */
		Application(
			std::string _name,
			std::shared_ptr<ILogger> _logger = std::make_shared<SPDLogger>()
		);
		~Application() = default;

	protected:
	};

} // namespace focus
