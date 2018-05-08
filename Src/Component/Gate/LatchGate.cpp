/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "LatchGate.hpp"

nts::LatchGate::LatchGate(const std::string &name, nts::IComponent *firstPin,
	nts::IComponent *secondPin, nts::IComponent *thirdPin,
	nts::IComponent *fourthPin
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = firstPin;
	this->_pin[1] = secondPin;
	this->_pin[2] = thirdPin;
	this->_pin[3] = fourthPin;
	this->_pinLink.insert({1, 1});
	this->_pinLink.insert({2, 1});
	this->_pinLink.insert({3, 1});
	this->_pinLink.insert({4, 1});

	this->_selectedOutput = -1;
}

nts::LatchGate::~LatchGate()
{
}

nts::LatchGate::LatchGate(LatchGate &other) : AbstractComponent(other._name,
	nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pin[3] = other._pin[3];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];
	this->_pinLink[3] = other._pinLink[3];
	this->_pinLink[4] = other._pinLink[4];

	this->_selectedOutput = other._selectedOutput;
}

nts::LatchGate &nts::LatchGate::operator=(LatchGate &other)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pin[3] = other._pin[3];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];
	this->_pinLink[3] = other._pinLink[3];
	this->_pinLink[4] = other._pinLink[4];

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;

	this->_selectedOutput = other._selectedOutput;

	return *this;
}

nts::IComponent *nts::LatchGate::Copy()
{
	return new LatchGate(*this);
}

void nts::LatchGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::LatchGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

static int truthTableExec(std::string dataInputs)
{
	int result = 0;

	for (size_t count = 0; count < dataInputs.length(); ++count) {
		result *= 2;
		result += dataInputs[count] == '1' ? 1 : 0;
	}
	return result;
}

nts::Tristate nts::LatchGate::computePin(int index)
{
	nts::Tristate value = nts::UNDEFINED;

	try {
		value = this->_pin[index]->compute();
	} catch (ComputeError &error) {
		value = nts::UNDEFINED;
	}
	return value;
}

nts::Tristate nts::LatchGate::compute(std::size_t pin __attribute__((unused)))
{
	if (this->_simul)
		return (this->_value);

	int first = computePin(0);
	int second = computePin(1);
	int third = computePin(2);
	int fourth = computePin(3);

	std::string data = std::to_string(fourth) + std::to_string(third) +
		std::to_string(second) + std::to_string(first);

	this->_simul = true;
	if (first != UNDEFINED && second != UNDEFINED && third != UNDEFINED &&
		fourth != UNDEFINED) {
		this->_value = TRUE;
		this->_selectedOutput = truthTableExec(data);
	} else
		this->_value = nts::UNDEFINED;
	return this->_value;
}

nts::IComponent *nts::LatchGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::LatchGate::getPinLink() const
{
	return this->_pinLink;
}

int nts::LatchGate::GetSelectedOutput() const
{
	return this->_selectedOutput;
}