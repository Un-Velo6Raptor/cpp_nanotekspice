/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Input.hpp"
#include "CD4008BMS.hpp"

nts::CD4008BMS::CD4008BMS(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::CHIPSET)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}
	this->_pin[0] = new Input(name + ": Pin 1", nts::PIN);
	this->_pin[1] = new Input(name + ": Pin 2", nts::PIN);
	this->_pin[2] = new Input(name + ": Pin 3", nts::PIN);
	this->_pin[3] = new Input(name + ": Pin 4", nts::PIN);
	this->_pin[4] = new Input(name + ": Pin 5", nts::PIN);
	this->_pin[5] = new Input(name + ": Pin 6", nts::PIN);
	this->_pin[6] = new Input(name + ": Pin 7", nts::PIN);
	this->_pin[14] = new Input(name + ": Pin 15", nts::PIN);
	this->_pin[8] = new Input(name + ": Pin 9 - Carry input", nts::GATE);

	this->_pin[9] = new Input(name + ": 10 gate", nts::GATE);
	this->_pin[10] = new Input(name + ": 11 gate", nts::GATE);
	this->_pin[11] = new Input(name + ": 12 gate", nts::GATE);
	this->_pin[12] = new Input(name + ": 13 gate", nts::GATE);
	this->_pin[13] = new Input(name + ": 14 gate - Carry out", nts::GATE);


	this->_gate[0] = new SumGate(name + "SUM 1", this->_pin[8], this->_pin[6], this->_pin[5], -1);
	this->_gate[1] = new SumGate(name + "SUM 2", this->_gate[0], this->_pin[4], this->_pin[3], 0);
	this->_gate[2] = new SumGate(name + "SUM 3", this->_gate[1], this->_pin[2], this->_pin[1], 0);
	this->_gate[3] = new SumGate(name + "SUM 4", this->_gate[2], this->_pin[0], this->_pin[14], 1);


	this->_pin[9]->DefineLink(1, *this->_gate[0], 1);
	this->_pin[10]->DefineLink(1, *this->_gate[1], 1);
	this->_pin[11]->DefineLink(1, *this->_gate[2], 1);
	this->_pin[12]->DefineLink(1, *this->_gate[3], 1);
	this->_pin[13]->DefineLink(1, *this->_gate[3], 0);
}

nts::CD4008BMS::~CD4008BMS()
{
}

nts::CD4008BMS::CD4008BMS(CD4008BMS &other) : AbstractComponent(other._name,
	nts::BASE, nts::CHIPSET)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pin[3] = other._pin[3];
	this->_pin[4] = other._pin[4];
	this->_pin[5] = other._pin[5];
	this->_pin[6] = other._pin[6];
	this->_pin[14] = other._pin[14];
	this->_pin[8] = other._pin[8];

	this->_pin[9] = other._pin[9];
	this->_pin[10] = other._pin[10];
	this->_pin[11] = other._pin[11];
	this->_pin[12] = other._pin[12];
	this->_pin[13] = other._pin[13];

	this->_gate[0] = other._gate[0];
	this->_gate[1] = other._gate[1];
	this->_gate[2] = other._gate[2];
	this->_gate[3] = other._gate[3];
}

nts::CD4008BMS &nts::CD4008BMS::operator=(CD4008BMS &other)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pin[3] = other._pin[3];
	this->_pin[4] = other._pin[4];
	this->_pin[5] = other._pin[5];
	this->_pin[6] = other._pin[6];
	this->_pin[14] = other._pin[14];
	this->_pin[8] = other._pin[8];

	this->_pin[9] = other._pin[9];
	this->_pin[10] = other._pin[10];
	this->_pin[11] = other._pin[11];
	this->_pin[12] = other._pin[12];
	this->_pin[13] = other._pin[13];

	this->_gate[0] = other._gate[0];
	this->_gate[1] = other._gate[1];
	this->_gate[2] = other._gate[2];
	this->_gate[3] = other._gate[3];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::CD4008BMS::Copy()
{
	return new CD4008BMS(*this);
}

void nts::CD4008BMS::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
//	std::cout << "NAME other: " << other.getName() << " on " << pin << " pin. " << nts::GATE << " == " << this->_pin[pin - 1]->getType() << std::endl;
//	std::cout << "NAME 14: " << this->_pin[14 - 1]->getName() << std::endl;
	if (pin - 1 < 17 && this->_pin[pin - 1] &&
		this->_pin[pin - 1]->getType() == nts::GATE) {
		try {
			other.DefineLink(otherPin, *this->_pin[pin - 1], 1);
			this->_pinLink[pin] = otherPin;
		} catch (SetLinkError &error) {
			std::cerr << "ERROR: " << error.getName() << std::endl;
			std::cerr << "+--> " << error.what() << std::endl;
			throw SetLinkError(
				"SetLinkError: Can't define this pin",
				this->getName());
		}
	} else
		throw SetLinkError("oooo SetLinkError: Can't access to this pin",
			this->getName());
}

void nts::CD4008BMS::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 17 && this->_pin[pin - 1] &&
		(this->_pin[pin - 1]->getType() == nts::PIN || pin == 9)) {
		try {
			this->_pin[pin - 1]->DefineLink(1, other, otherPin);
			this->_pinLink[pin] = otherPin;
		} catch (SetLinkError &error) {
			std::cerr << "ERROR: " << error.getName() << std::endl;
			std::cerr << "+--> " << error.what() << std::endl;
		}
	} else
		throw SetLinkError("--- SetLinkError: Can't access to this pin",
			this->getName());
}

nts::Tristate nts::CD4008BMS::compute(std::size_t pin __attribute__((unused)))
{
	throw ComputeError("ComputeError: Can't compute this component",
		this->getName());
}

nts::IComponent *nts::CD4008BMS::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::CD4008BMS::getPinLink() const
{
	return this->_pinLink;
}

void nts::CD4008BMS::resetSimulation()
{
	for (int i = 0; i < 17; ++i) {
		if (this->_pin[i] != nullptr)
			this->_pin[i]->resetSimulation();
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_gate[i] != nullptr)
			this->_gate[i]->resetSimulation();
	}
}