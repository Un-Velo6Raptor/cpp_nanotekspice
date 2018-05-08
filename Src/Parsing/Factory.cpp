/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
	createMap();
}

nts::Factory::~Factory()
{
}

nts::IComponent *nts::Factory::createCompo(const std::string &value) const
{
	nts::IComponent *tmp;

	std::map<std::string, nts::IComponent *>::const_iterator it = _map.find(
		value);
	if (it != _map.end())
		tmp = ((*it).second)->Copy();
	else {
		throw ErrorInFile(
			"The component : \"" + value + "\" doesn't exist.",
			"nts::Factory::createCompo");
	}
	return tmp;
}

void nts::Factory::createMap()
{
	_map["input"] = new nts::Input("");
	_map["output"] = new nts::Output("");
	_map["clock"] = new nts::Clock("");
	_map["true"] = new nts::True("");
	_map["false"] = new nts::False("");
	_map["4081"] = new nts::HCF4081B("");
	_map["4001"] = new nts::HEF4001B("");
	_map["4071"] = new nts::HEF4071B("");
	_map["4011"] = new nts::CD4011B("");
	_map["4030"] = new nts::CD4030C("");
	_map["4069"] = new nts::CD4069UBC("");
	_map["4514"] = new nts::CD4514BC("");
	_map["4008"] = new nts::CD4008BMS("");
	_map["4040"] = new nts::MC14040B("");
}