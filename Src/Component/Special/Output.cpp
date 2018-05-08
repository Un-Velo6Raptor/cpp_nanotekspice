/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Output.hpp"

nts::Output::Output(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::OUTPUT)
{
	this->_value = nts::UNDEFINED;
	this->_pinLink.insert({0, 0});
	this->_pin[0] = nullptr;
}

nts::Output::~Output()
{
}

nts::Output::Output(Output &other) : AbstractComponent(other._name, other._type,
	other._tChipset)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];
}

nts::Output &nts::Output::operator=(Output &other)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];

	this->_name = other._name;
	this->_tChipset = other._tChipset;
	this->_type = other._type;

	return *this;
}

nts::IComponent *nts::Output::Copy()
{
	return new Output(*this);
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	if (pin - 1 != 0)
		throw ComputeError("ComputeError: Can't access to this pin",
			this->getName());
	if (this->_pin[0] == nullptr)
		throw ComputeError("ComputeError: Pin not set",
			this->getName());
	if (!this->_simul)
		this->_value = this->_pin[0]->compute(this->_pinLink[0]);
	return this->_value;
}

void nts::Output::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link an output to an another components",
		this->getName());
}

void nts::Output::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 == 0) {
		if (this->_pin[0] != nullptr)
			throw SetLinkError(
				"SetLinkError: This pin is already set",
				this->getName());
		this->_pin[0] = &other;
		this->_pinLink[0] = otherPin;
	} else
		throw SetLinkError("SetLinkError: Can't access to this pin",
			this->getName());
}

void nts::Output::setValue(const nts::Tristate &value)
{
	this->_value = value;
}

nts::IComponent *nts::Output::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::Output::getPinLink() const
{
	return this->_pinLink;
}

nts::Tristate nts::Output::getValue() const
{
	return this->_value;
}

void nts::Output::display() const
{
	if (this->_value == nts::Tristate::UNDEFINED)
		std::cout << this->getName() << "=U" << std::endl;
	else
		std::cout << this->getName() << "=" << this->_value << std::endl;
}