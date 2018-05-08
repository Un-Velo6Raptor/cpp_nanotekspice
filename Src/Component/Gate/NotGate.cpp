/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "NotGate.hpp"

nts::NotGate::NotGate(const std::string &name, nts::IComponent *firstPin
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = firstPin;
	this->_pinLink.insert({1, 1});
}

nts::NotGate::~NotGate()
{
}

nts::NotGate::NotGate(NotGate &other) : AbstractComponent(other._name,
	nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pinLink[1] = other._pinLink[1];
}

nts::NotGate &nts::NotGate::operator=(NotGate &other)
{
	this->_pin[0] = other._pin[0];
	this->_pinLink[1] = other._pinLink[1];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::NotGate::Copy()
{
	return new NotGate(*this);
}

void nts::NotGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::NotGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

nts::Tristate nts::NotGate::truthTableExec(nts::Tristate first)
{
	nts::Tristate value = nts::UNDEFINED;

	if (first == nts::Tristate::TRUE)
		value = nts::Tristate::FALSE;
	else if (first == nts::Tristate::FALSE)
		value = nts::Tristate::TRUE;

	return value;
}

nts::Tristate nts::NotGate::compute(std::size_t pin __attribute__((unused)))
{
	nts::Tristate first = nts::UNDEFINED;

	if (this->_simul)
		return (this->_value);
	try {
		first = this->_pin[0]->compute();
	} catch (ComputeError &error) {
		first = nts::UNDEFINED;
	}
	this->_simul = true;
	this->_value = truthTableExec(first);
	return this->_value;
}

nts::IComponent *nts::NotGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::NotGate::getPinLink() const
{
	return this->_pinLink;
}
