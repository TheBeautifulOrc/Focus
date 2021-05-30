#pragma once

#include <memory>

#include "common.hpp"
#include "core/engine_component.hpp"
#include "core/logging_system/spdlogger.hpp"

namespace focus
{
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
		 * @param _name Name of this application.
		 * @param _version Version number of this application.
		 * @param _logger Logger instance that this application shall use for its logging. If unspecified a new (default) instance of Logger will be created.
		 */
		Application(
			const std::string& _name,
			VersionNumber _version,
			std::shared_ptr<ILogger> _logger = std::make_shared<LoggerSPD>()
		);
		~Application() = default;

		/**
		 * @brief Version number getter.
		 *
		 * @return Version number of this application.
		 */
		inline auto get_version() const -> const VersionNumber& { return version; }

	private:
		const VersionNumber version;
	};

} // namespace focus
