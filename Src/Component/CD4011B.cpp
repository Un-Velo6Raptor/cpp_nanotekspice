/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include "Input.hpp"
#include "CD4011B.hpp"

nts::CD4011B::CD4011B(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::CHIPSET)
{
	for (int i = 0; i < 14; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}
	this->_pin[0] = new Input(name + ": Pin 1", nts::PIN);
	this->_pin[1] = new Input(name + ": Pin 2", nts::PIN);

	this->_pin[2] = new NandGate(name + ": Gate 3 (2, 1)", this->_pin[0],
		this->_pin[1]);

	this->_pin[4] = new Input(name + ": Pin 5", nts::PIN);
	this->_pin[5] = new Input(name + ": Pin 6", nts::PIN);
	this->_pin[3] = new NandGate(name + ": Gate 4 (5, 6)", this->_pin[4],
		this->_pin[5]);

	this->_pin[7] = new Input(name + ": Pin 8", nts::PIN);
	this->_pin[8] = new Input(name + ": Pin 9", nts::PIN);
	this->_pin[9] = new NandGate(name + ": Gate 10 (8, 9)", this->_pin[7],
		this->_pin[8]);

	this->_pin[11] = new Input(name + ": Pin 12", nts::PIN);
	this->_pin[12] = new Input(name + ": Pin 13", nts::PIN);
	this->_pin[10] = new NandGate(name + ": Gate 11 (12, 13)",
		this->_pin[11], this->_pin[12]);
}

nts::CD4011B::~CD4011B()
{
}

nts::CD4011B::CD4011B(CD4011B &other) : AbstractComponent(other._name,
	nts::BASE, nts::CHIPSET)
{
	for (int i = 0; i < 14; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];

	this->_pin[4] = other._pin[4];
	this->_pin[5] = other._pin[5];
	this->_pin[3] = other._pin[3];

	this->_pin[7] = other._pin[7];
	this->_pin[8] = other._pin[8];
	this->_pin[9] = other._pin[9];

	this->_pin[11] = other._pin[11];
	this->_pin[12] = other._pin[12];
	this->_pin[10] = other._pin[10];
}

nts::CD4011B &nts::CD4011B::operator=(CD4011B &other)
{
	for (int i = 0; i < 14; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];

	this->_pin[4] = other._pin[4];
	this->_pin[5] = other._pin[5];
	this->_pin[3] = other._pin[3];

	this->_pin[7] = other._pin[7];
	this->_pin[8] = other._pin[8];
	this->_pin[9] = other._pin[9];

	this->_pin[11] = other._pin[11];
	this->_pin[12] = other._pin[12];
	this->_pin[10] = other._pin[10];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::CD4011B::Copy()
{
	return new CD4011B(*this);
}

void nts::CD4011B::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 14 && this->_pin[pin - 1] &&
		this->_pin[pin - 1]->getType() == nts::GATE) {
		try {
			other.DefineLink(otherPin, *this->_pin[pin - 1], pin);
			this->_pinLink[pin] = otherPin;
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

void nts::CD4011B::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 14 && this->_pin[pin - 1] &&
		this->_pin[pin - 1]->getType() == nts::PIN) {
		try {
			this->_pin[pin - 1]->DefineLink(1, other, otherPin);
			this->_pinLink[pin] = otherPin;
		} catch (SetLinkError &error) {
			std::cerr << "ERROR: " << error.getName() << std::endl;
			std::cerr << "+--> " << error.what() << std::endl;
		}
	} else
		throw SetLinkError("SetLinkError: Can't access to this pin",
			this->getName());
}

nts::Tristate nts::CD4011B::compute(std::size_t pin __attribute__((unused)))
{
	throw ComputeError("ComputeError: Can't compute this component",
		this->getName());
}

nts::IComponent *nts::CD4011B::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::CD4011B::getPinLink() const
{
	return this->_pinLink;
}

void nts::CD4011B::resetSimulation()
{
	for (int i = 0; i < 14; ++i) {
		if (this->_pin[i] != nullptr)
			this->_pin[i]->resetSimulation();
	}
}