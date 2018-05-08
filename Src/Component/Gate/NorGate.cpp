/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "NorGate.hpp"

nts::NorGate::NorGate(const std::string &name, nts::IComponent *firstPin,
	nts::IComponent *secondPin
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = firstPin;
	this->_pin[1] = secondPin;
	this->_pinLink.insert({1, 1});
	this->_pinLink.insert({2, 1});
}

nts::NorGate::~NorGate()
{
}

nts::NorGate::NorGate(NorGate &other) : AbstractComponent(other._name,
	nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];
}

nts::NorGate &nts::NorGate::operator=(NorGate &other)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::NorGate::Copy()
{
	return new NorGate(*this);
}

void nts::NorGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::NorGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

nts::Tristate nts::NorGate::truthTableExec(nts::Tristate first, nts::Tristate second)
{
	nts::Tristate value = nts::UNDEFINED;

	if (first == nts::TRUE || second == nts::TRUE)
		value = nts::FALSE;
	else if (first == nts::UNDEFINED || second == nts::UNDEFINED)
		value = nts::UNDEFINED;
	else
		value = nts::TRUE;
	return value;
}

nts::Tristate nts::NorGate::compute(std::size_t pin __attribute__((unused)))
{
	nts::Tristate first = nts::UNDEFINED;
	nts::Tristate second = nts::UNDEFINED;

	if (this->_simul)
		return (this->_value);
	try {
		first = this->_pin[0]->compute();
	} catch (ComputeError &error) {
		first = nts::UNDEFINED;
	}
	try {
		second = this->_pin[1]->compute();
	} catch (ComputeError &error) {
		second = nts::UNDEFINED;
	}
	this->_simul = true;
	this->_value = truthTableExec(first, second);
	return this->_value;
}

nts::IComponent *nts::NorGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::NorGate::getPinLink() const
{
	return this->_pinLink;
}
