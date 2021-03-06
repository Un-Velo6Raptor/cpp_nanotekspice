/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "False.hpp"

nts::False::False(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::INPUT)
{
	this->_value = nts::FALSE;
	this->_pinLink.insert({0, 0});
	this->_pin[0] = nullptr;
}

nts::False::~False()
{
}

nts::False::False(False &other) : AbstractComponent(other._name, other._type,
	other._tChipset)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];
}

nts::False &nts::False::operator=(False &other)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];

	this->_name = other._name;
	this->_tChipset = other._tChipset;
	this->_type = other._type;

	return *this;
}

nts::IComponent *nts::False::Copy()
{
	return new False(*this);
}

nts::Tristate nts::False::compute(std::size_t pin __attribute__((unused)))
{
	return (nts::FALSE);
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 == 0) {
		try {
			other.DefineLink(otherPin, *this, pin);
		} catch (SetLinkError &error) {
			std::cerr << "ERROR: " << error.getName() << std::endl;
			std::cerr << "+--> " << error.what() << std::endl;
			throw SetLinkError(
				"SetLinkError: Can't define this pin",
				this->getName());
		}
	} else
		throw SetLinkError("SetLinkError: Can't access to this pin",
			this->getName());
}

void nts::False::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError("SetLinkError: Can't define a link TERM",
		this->getName());
}

void nts::False::setValue(const nts::Tristate &value __attribute__((unused)))
{
	throw SetValueError("setValue: Can't set a value of false component",
		this->getName());
}

nts::IComponent *nts::False::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::False::getPinLink() const
{
	return this->_pinLink;
}

nts::Tristate nts::False::getValue() const
{
	return this->_value;
}
