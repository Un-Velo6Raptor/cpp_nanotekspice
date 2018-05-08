/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "LittleDecoderGate.hpp"

nts::LittleDecoderGate::LittleDecoderGate(const std::string &name,
	LatchGate *Latch, int OutputNumber, nts::IComponent *Inhibit
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = Inhibit;
	this->_pinLink.insert({1, 1});
	this->_gate = Latch;
	this->_outputNumber = OutputNumber;
}

nts::LittleDecoderGate::~LittleDecoderGate()
{
}

nts::LittleDecoderGate::LittleDecoderGate(LittleDecoderGate &other)
	: AbstractComponent(other._name, nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pinLink[1] = other._pinLink[1];
	this->_gate = other._gate;
	this->_outputNumber = other._outputNumber;
}

nts::LittleDecoderGate &nts::LittleDecoderGate::operator=(
	LittleDecoderGate &other
)
{
	this->_pin[0] = other._pin[0];
	this->_pinLink[1] = other._pinLink[1];
	this->_gate = other._gate;
	this->_outputNumber = other._outputNumber;

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::LittleDecoderGate::Copy()
{
	return new LittleDecoderGate(*this);
}

void nts::LittleDecoderGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::LittleDecoderGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

static nts::Tristate truthTableExec(nts::Tristate first, nts::LatchGate *gate,
	int OutputNumber
)
{
	nts::Tristate tmp = gate->compute();
	int WhichOutput = gate->GetSelectedOutput();
	nts::Tristate value = nts::UNDEFINED;

	if (first)
		value = nts::FALSE;
	else if (tmp == nts::UNDEFINED)
		value = nts::UNDEFINED;
	else if (WhichOutput == OutputNumber)
		value = nts::TRUE;
	else
		value = nts::FALSE;

	return value;
}

nts::Tristate nts::LittleDecoderGate::compute(
	std::size_t pin __attribute__((unused)))
{
	nts::Tristate first = nts::UNDEFINED;

	if (this->_simul)
		return (this->_value);
	try {
		first = this->_pin[0]->compute();
	} catch (ComputeError &error) {
		first = nts::UNDEFINED;
	}
	this->_simul = true;
	this->_value = truthTableExec(first, this->_gate, this->_outputNumber);
	return this->_value;
}

nts::IComponent *nts::LittleDecoderGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::LittleDecoderGate::getPinLink() const
{
	return this->_pinLink;
}
