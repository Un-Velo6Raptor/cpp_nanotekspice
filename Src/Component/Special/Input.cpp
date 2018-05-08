/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Input.hpp"

nts::Input::Input(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::INPUT)
{
	this->_value = nts::UNDEFINED;
	this->_pinLink.insert({0, 0});
	this->_pin[0] = nullptr;
}

nts::Input::~Input()
{
}

nts::Input &nts::Input::operator=(Input &other)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];

	this->_name = other._name;
	this->_tChipset = other._tChipset;
	this->_type = other._type;

	return *this;
}

nts::IComponent *nts::Input::Copy()
{
	return new Input(*this);
}

nts::Input::Input(nts::Input &other) : AbstractComponent(other._name,
	other._type, other._tChipset)
{
	this->_value = other._value;
	this->_pinLink.insert({0, other._pinLink[0]});
	this->_pin[0] = other._pin[0];
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
	if (this->getType() == nts::TERMINAL)
		return this->_value;
	if (pin - 1 != 0)
		throw ComputeError("ComputeError: Can't access to this pin " + this->_name + " to " + std::to_string(pin),
			this->getName());
	if (this->_pin[0] == nullptr)
		throw ComputeError("ComputeError: Pin not set",
			this->getName());
	if (this->_simul)
		return (this->_value);
	this->_value = this->_pin[0]->compute(this->_pinLink[0]);
	this->_simul = true;
	return this->_value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (this->getType() == nts::PIN) {
		throw SetLinkError(
			"SetLinkError: Can't linked a pin of a component",
			this->getName());
	} else if (pin - 1 == 0) {
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

void nts::Input::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (this->getType() == nts::TERMINAL)
		throw SetLinkError("SetLinkError: Can't define a link TERM",
			this->getName());
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

void nts::Input::setValue(const nts::Tristate &value)
{
	this->_value = value;
}

nts::IComponent *nts::Input::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::Input::getPinLink() const
{
	return this->_pinLink;
}

nts::Tristate nts::Input::getValue() const
{
	return this->_value;
}
