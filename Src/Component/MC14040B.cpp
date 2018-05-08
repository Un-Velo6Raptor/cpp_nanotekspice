/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "Input.hpp"
#include "MC14040B.hpp"

nts::MC14040B::MC14040B(const std::string name, nts::TypeOfComponent type)
	: AbstractComponent(name, type, nts::CHIPSET)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}
	this->_pin[10] = new Input(name + ": Reset", nts::PIN);
	this->_pin[9] = new Input(name + ": Clock", nts::PIN);

	this->_pin[0] = new CounterGate(name + ": COUNTER 1", nullptr, nullptr, this->_pin[10]);
	this->_pin[14] = new CounterGate(name + ": COUNTER 15", nullptr, this->_pin[0], this->_pin[10]);
	this->_pin[13] = new CounterGate(name + ": COUNTER 14", nullptr, this->_pin[14], this->_pin[10]);
	this->_pin[11] = new CounterGate(name + ": COUNTER 12", nullptr, this->_pin[13], this->_pin[10]);
	this->_pin[12] = new CounterGate(name + ": COUNTER 13", nullptr, this->_pin[11], this->_pin[10]);
	this->_pin[3] = new CounterGate(name + ": COUNTER 4", nullptr, this->_pin[12], this->_pin[10]);
	this->_pin[1] = new CounterGate(name + ": COUNTER 2", nullptr, this->_pin[3], this->_pin[10]);
	this->_pin[2] = new CounterGate(name + ": COUNTER 3", nullptr, this->_pin[1], this->_pin[10]);
	this->_pin[4] = new CounterGate(name + ": COUNTER 5", nullptr, this->_pin[2], this->_pin[10]);
	this->_pin[5] = new CounterGate(name + ": COUNTER 6", nullptr, this->_pin[4], this->_pin[10]);
	this->_pin[6] = new CounterGate(name + ": COUNTER 7", nullptr, this->_pin[5], this->_pin[10]);
	this->_pin[8] = new CounterGate(name + ": COUNTER 9", nullptr, this->_pin[6], this->_pin[10], this->_pin[9]);


	((CounterGate * )(this->_pin[8]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[6]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[5]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[4]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[2]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[1]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[3]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[12]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[11]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[13]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[14]))->setFirstCounter(this->_pin[8]);
	((CounterGate * )(this->_pin[0]))->setFirstCounter(this->_pin[8]);
}

nts::MC14040B::~MC14040B()
{
}

nts::MC14040B::MC14040B(MC14040B &other) : AbstractComponent(other._name,
	nts::BASE, nts::CHIPSET)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[10] = other._pin[10];
	this->_pin[9] = other._pin[9];
	this->_pin[8] = other._pin[8];
	this->_pin[6] = other._pin[6];
	this->_pin[5] = other._pin[5];
	this->_pin[4] = other._pin[4];
	this->_pin[2] = other._pin[2];
	this->_pin[1] = other._pin[1];
	this->_pin[3] = other._pin[3];
	this->_pin[12] = other._pin[12];
	this->_pin[11] = other._pin[11];
	this->_pin[13] = other._pin[13];
	this->_pin[14] = other._pin[14];
	this->_pin[0] = other._pin[0];
}

nts::MC14040B &nts::MC14040B::operator=(MC14040B &other)
{
	for (int i = 0; i < 17; ++i) {
		this->_pin[i] = nullptr;
		this->_pinLink.insert({i + 1, 0});
	}

	this->_pin[10] = other._pin[10];
	this->_pin[9] = other._pin[9];
	this->_pin[8] = other._pin[8];
	this->_pin[6] = other._pin[6];
	this->_pin[5] = other._pin[5];
	this->_pin[4] = other._pin[4];
	this->_pin[2] = other._pin[2];
	this->_pin[1] = other._pin[1];
	this->_pin[3] = other._pin[3];
	this->_pin[12] = other._pin[12];
	this->_pin[11] = other._pin[11];
	this->_pin[13] = other._pin[13];
	this->_pin[14] = other._pin[14];
	this->_pin[0] = other._pin[0];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::MC14040B::Copy()
{
	return new MC14040B(*this);
}

void nts::MC14040B::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 17 && this->_pin[pin - 1] &&
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

void nts::MC14040B::DefineLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
{
	if (pin - 1 < 17 && this->_pin[pin - 1] &&
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

nts::Tristate nts::MC14040B::compute(std::size_t pin __attribute__((unused)))
{
	throw ComputeError("ComputeError: Can't compute this component",
		this->getName());
}

nts::IComponent *nts::MC14040B::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::MC14040B::getPinLink() const
{
	return this->_pinLink;
}

void nts::MC14040B::resetSimulation()
{
	for (int i = 0; i < 17; ++i) {
		if (this->_pin[i] != nullptr)
			this->_pin[i]->resetSimulation();
	}
}