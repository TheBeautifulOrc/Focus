#include "engine_component.hpp"

namespace focus
{
	EngineComponent::EngineComponent(
		const std::string& _name,
		std::shared_ptr<ILogger> _logger
	) : name{_name}, logger{_logger} {}

	auto EngineComponent::pop_subcomponent(const std::string& comp_name) -> std::unique_ptr<EngineComponent>
	{
		auto ret_comp = std::move(subcomponents.at(comp_name));
		remove_subcomponent(comp_name);
		return std::move(ret_comp);
	}

} // namespace focus
