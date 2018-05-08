/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include "CreateComponent.hpp"
#include "Read.hpp"

nts::IComponent *nts::CreateComponent::findIComponent(const std::string &name)
{
	nts::IComponent *return_value = nullptr;

	for (std::size_t pos = 0; pos < _component.size(); pos++) {
		if (_component[pos]->getName() == name)
			return_value = _component[pos];
	}
	return return_value;
}

std::string nts::CreateComponent::findType(const std::string &name,
	const Chipsets &chipsets
) const
{
	std::string type;

	for (std::size_t pos = 0; pos < chipsets.getVector().size(); pos++) {
		if (chipsets.getName(pos) == name)
			type = chipsets.getType(pos);
	}
	if (type == "true" || type == "false" || type == "clock")
		type = "input";
	return type;
}

void nts::CreateComponent::setValueIComponent(const IComponent *compo,
	const std::string &type, const Chipsets &chipsets
)
{
	try {
		Tristate value = TRUE;
		for (std::size_t pos = 0;
			pos < chipsets.getVector().size(); pos++) {
			if (chipsets.getName(pos) == compo->getName()) {
				std::string return_value = chipsets.getValue(
					pos);
				if (return_value == "0")
					value = FALSE;
			}
		}
		if (type == "input")
			((nts::Input *)compo)->setValue(value);
		else if (type == "output")
			((nts::Output *)compo)->setValue(value);
		else if (type == "clock")
			((nts::Clock *)compo)->setValue(value);
	} catch (nts::SetValueError const &error) {
		std::cerr << "/!\\ ERROR on " << error.getName() << std::endl;
		std::cerr << " +--> " << error.what() << std::endl;
		exit(84);
	}
}

void nts::CreateComponent::stockOutput(const Chipsets &chipsets)
{
	for (std::size_t pos = 0; pos < _component.size(); pos++) {
		for (std::size_t x = 0; x < chipsets.getVector().size(); x++) {
			if (_component[pos]->getName() == chipsets.getName(x)) {
				if (chipsets.getType(x) == "output")
					_output[_component[pos]->getName()] =
						((nts::Output *)_component[pos]);
			}
		}
	}
}

void nts::CreateComponent::fillLinks(const std::string &name,
	const Links &links, const std::string &type, const Chipsets &chipsets
)
{
	std::size_t pos;
	for (pos = 0; pos < _component.size() &&
		_component[pos]->getName() != name; pos++);
	for (std::size_t x = 0; x < links.getVector().size(); x++) {
		if (links.getName(x) == name) {
			nts::IComponent *tmp = findIComponent(
				links.getNameSecond(x));
			std::string secondType = findType(
				links.getNameSecond(x), chipsets);
			if (type == "output" || secondType == "input") {
				tmp->setLink(std::stoi(links.getValueSecond(x)),
					*_component[pos],
					std::stoi(links.getValue(x)));
			} else
				_component[pos]->setLink(
					std::stoi(links.getValue(x)), *tmp,
					std::stoi(links.getValueSecond(x)));
		}
		setValueIComponent(_component[pos], type, chipsets);
		_component[pos]->resetSimulation();
	}
}

nts::CreateComponent::CreateComponent(const Chipsets &chipsets,
	const Links &links
)
{
	Factory tmp;
	IComponent *it;

	for (std::size_t pos = 0; pos < chipsets.getVector().size(); pos++) {
		it = tmp.createCompo(chipsets.getType(pos));
		it->setName(chipsets.getName(pos));
		_component.push_back(it);
	}
	for (std::size_t pos = 0; pos < chipsets.getVector().size(); pos++) {
		fillLinks(chipsets.getName(pos), links, chipsets.getType(pos),
			chipsets);
	}
	stockOutput(chipsets);
	Read lec(_component, _output);
	lec.readInLine();
}

nts::CreateComponent::~CreateComponent()
{
}