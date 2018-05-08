/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Input.hpp"
#include "HEF4001B.hpp"

nts::HEF4001B::HEF4001B(const std::string name, nts::TypeOfComponent type
) : AbstractComponent(name, type, nts::CHIPSET)
{
	for (int i = 0; i < 14; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}
	this->_pin[0] = new Input(name + ": Pin 1", nts::PIN);
	this->_pin[1] = new Input(name + ": Pin 2", nts::PIN);
	this->_pin[2] = new NorGate(name + ": Gate 3 (2, 1)", this->_pin[0],
		this->_pin[1]);

	this->_pin[4] = new Input(name + ": Pin 5", nts::PIN);
	this->_pin[5] = new Input(name + ": Pin 6", nts::PIN);
	this->_pin[3] = new NorGate(name + ": Gate 4 (5, 6)", this->_pin[4],
		this->_pin[5]);

	this->_pin[7] = new Input(name + ": Pin 8", nts::PIN);
	this->_pin[8] = new Input(name + ": Pin 9", nts::PIN);
	this->_pin[9] = new NorGate(name + ": Gate 10 (8, 9)", this->_pin[7],
		this->_pin[8]);

	this->_pin[11] = new Input(name + ": Pin 12", nts::PIN);
	this->_pin[12] = new Input(name + ": Pin 13", nts::PIN);
	this->_pin[10] = new NorGate(name + ": Gate 11 (12, 13)",
		this->_pin[11], this->_pin[12]);
}

nts::HEF4001B::~HEF4001B()
{
}

nts::HEF4001B::HEF4001B(HEF4001B &other) : AbstractComponent(other._name,
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

nts::HEF4001B &nts::HEF4001B::operator=(HEF4001B &other)
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

nts::IComponent* nts::HEF4001B::Copy()
{
	return new HEF4001B(*this);
}

void nts::HEF4001B::setLink(std::size_t pin, nts::IComponent &other,
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

void nts::HEF4001B::DefineLink(std::size_t pin, nts::IComponent &other,
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
			throw SetLinkError(
				"SetLinkError: Can't define this pin",
				this->getName());
		}
	} else
		throw SetLinkError("SetLinkError: Can't access to this pin",
			this->getName());
}

nts::Tristate nts::HEF4001B::compute(std::size_t pin __attribute__((unused)))
{
	throw ComputeError("ComputeError: Can't compute this component",
		this->getName());
}

nts::IComponent *nts::HEF4001B::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::HEF4001B::getPinLink() const
{
	return this->_pinLink;
}

void nts::HEF4001B::resetSimulation()
{
	for (int i = 0; i < 14; ++i) {
		if (this->_pin[i] != nullptr)
			this->_pin[i]->resetSimulation();
	}
}