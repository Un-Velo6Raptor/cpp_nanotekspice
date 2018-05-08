/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Input.hpp"
#include "CD4514BC.hpp"

nts::CD4514BC::CD4514BC(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::CHIPSET)
{
	for (int i = 0; i < 25; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}
	this->_pin[0] = new Input(name + ": strobe", nts::PIN);

	this->_pin[1] = new Input(name + ": Pin 2", nts::PIN);
	this->_pin[2] = new Input(name + ": Pin 3", nts::PIN);
	this->_pin[20] = new Input(name + ": Pin 21", nts::PIN);
	this->_pin[21] = new Input(name + ": Pin 22", nts::PIN);

	this->_pin[22] = new Input(name + ": Pin 23 - inhibit", nts::PIN);

	this->_gate = new LatchGate("Gate 4514", this->_pin[1], this->_pin[2],
		this->_pin[20], this->_pin[21]);

	this->_pin[3] = new LittleDecoderGate(name + ": Pin 4", this->_gate, 7,
		this->_pin[22]);
	this->_pin[4] = new LittleDecoderGate(name + ": Pin 5", this->_gate, 6,
		this->_pin[22]);
	this->_pin[5] = new LittleDecoderGate(name + ": Pin 6", this->_gate, 5,
		this->_pin[22]);
	this->_pin[6] = new LittleDecoderGate(name + ": Pin 7", this->_gate, 4,
		this->_pin[22]);
	this->_pin[7] = new LittleDecoderGate(name + ": Pin 8", this->_gate, 3,
		this->_pin[22]);
	this->_pin[8] = new LittleDecoderGate(name + ": Pin 9", this->_gate, 1,
		this->_pin[22]);
	this->_pin[9] = new LittleDecoderGate(name + ": Pin 10", this->_gate, 2,
		this->_pin[22]);
	this->_pin[10] = new LittleDecoderGate(name + ": Pin 11", this->_gate,
		0, this->_pin[22]);

	this->_pin[12] = new LittleDecoderGate(name + ": Pin 13", this->_gate,
		13, this->_pin[22]);
	this->_pin[13] = new LittleDecoderGate(name + ": Pin 14", this->_gate,
		12, this->_pin[22]);
	this->_pin[14] = new LittleDecoderGate(name + ": Pin 15", this->_gate,
		15, this->_pin[22]);
	this->_pin[15] = new LittleDecoderGate(name + ": Pin 16", this->_gate,
		14, this->_pin[22]);
	this->_pin[16] = new LittleDecoderGate(name + ": Pin 17", this->_gate,
		9, this->_pin[22]);
	this->_pin[17] = new LittleDecoderGate(name + ": Pin 18", this->_gate,
		8, this->_pin[22]);
	this->_pin[18] = new LittleDecoderGate(name + ": Pin 19", this->_gate,
		11, this->_pin[22]);
	this->_pin[19] = new LittleDecoderGate(name + ": Pin 20", this->_gate,
		10, this->_pin[22]);
}

nts::CD4514BC::~CD4514BC()
{
}

nts::CD4514BC::CD4514BC(CD4514BC &other) : AbstractComponent(other._name,
	nts::BASE, nts::CHIPSET)
{
	for (int i = 0; i < 25; ++i) {
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
	this->_pin[7] = other._pin[7];
	this->_pin[8] = other._pin[8];
	this->_pin[9] = other._pin[9];
	this->_pin[10] = other._pin[10];

	this->_pin[12] = other._pin[12];
	this->_pin[13] = other._pin[13];
	this->_pin[14] = other._pin[14];
	this->_pin[15] = other._pin[15];
	this->_pin[16] = other._pin[16];
	this->_pin[17] = other._pin[17];
	this->_pin[18] = other._pin[18];
	this->_pin[19] = other._pin[19];
	this->_pin[20] = other._pin[20];
	this->_pin[21] = other._pin[21];
	this->_pin[22] = other._pin[22];

	this->_gate = other._gate;
}

nts::CD4514BC &nts::CD4514BC::operator=(CD4514BC &other)
{
	for (int i = 0; i < 25; ++i) {
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
	this->_pin[7] = other._pin[7];
	this->_pin[8] = other._pin[8];
	this->_pin[9] = other._pin[9];
	this->_pin[10] = other._pin[10];

	this->_pin[12] = other._pin[12];
	this->_pin[13] = other._pin[13];
	this->_pin[14] = other._pin[14];
	this->_pin[15] = other._pin[15];
	this->_pin[16] = other._pin[16];
	this->_pin[17] = other._pin[17];
	this->_pin[18] = other._pin[18];
	this->_pin[19] = other._pin[19];
	this->_pin[20] = other._pin[20];
	this->_pin[21] = other._pin[21];
	this->_pin[22] = other._pin[22];

	this->_gate = other._gate;
	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::CD4514BC::Copy()
{
	return new CD4514BC(*this);
}

void nts::CD4514BC::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 25 && this->_pin[pin - 1] &&
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

void nts::CD4514BC::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 25 && this->_pin[pin - 1] &&
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

nts::Tristate nts::CD4514BC::compute(std::size_t pin __attribute__((unused)))
{
	throw ComputeError("ComputeError: Can't compute this component",
		this->getName());
}

nts::IComponent *nts::CD4514BC::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::CD4514BC::getPinLink() const
{
	return this->_pinLink;
}

void nts::CD4514BC::resetSimulation()
{
	for (int i = 0; i < 25; ++i) {
		if (this->_pin[i] != nullptr)
			this->_pin[i]->resetSimulation();
	}
	if (this->_gate)
		this->_gate->resetSimulation();
}