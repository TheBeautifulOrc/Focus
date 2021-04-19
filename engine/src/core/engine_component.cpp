#include "engine_component.hpp"

namespace focus
{
	EngineComponent::EngineComponent(const std::string& _name, std::shared_ptr<ILogger> _logger) : name{_name}, logger{_logger} {}

	auto EngineComponent::add_subcomponent(std::unique_ptr<EngineComponent> new_comp) -> EngineComponent*
	{
		auto ret_ptr = new_comp.get();
		subcomponents.insert(std::make_pair(new_comp->get_name(), std::move(new_comp)));
		return ret_ptr;
	}

	auto EngineComponent::pop_subcomponent(const std::string& comp_name) -> std::unique_ptr<EngineComponent>
	{
		auto ret_comp = std::move(subcomponents.at(comp_name));
		subcomponents.erase(comp_name);
		return std::move(ret_comp);
	}

} // namespace focus
