/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Clock.hpp"

nts::Clock::Clock(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::CLOCK)
{
	this->_value = nts::UNDEFINED;
	this->_pinLink.insert({0, 0});
	this->_pin[0] = nullptr;
}

nts::Clock::~Clock()
{
}

nts::Clock::Clock(Clock &other) : AbstractComponent(other._name, other._type,
	other._tChipset)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];
}

nts::Clock &nts::Clock::operator=(Clock &other)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];

	this->_name = other._name;
	this->_tChipset = other._tChipset;
	this->_type = other._type;

	return *this;
}

nts::IComponent *nts::Clock::Copy()
{
	return new Clock(*this);
}

nts::Tristate nts::Clock::compute(std::size_t pin __attribute__((unused)))
{
	nts::Tristate value = this->_value;

	if (this->_value == nts::UNDEFINED)
		throw ComputeError(
			"ComputeError: This component need to be initialize",
			this->getName());
	if (this->_simul)
		return (this->_value);
	this->_simul = true;
	this->_value = (this->_value == nts::FALSE) ? nts::TRUE : nts::FALSE;
	return value;
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other,
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

void nts::Clock::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError("SetLinkError: Can't define a link a term component",
		this->getName());
}

void nts::Clock::setValue(const nts::Tristate &value)
{
	this->_value = value;
}

nts::IComponent *nts::Clock::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::Clock::getPinLink() const
{
	return this->_pinLink;
}

nts::Tristate nts::Clock::getValue() const
{
	return this->_value;
}
