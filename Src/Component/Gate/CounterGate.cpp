/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "CounterGate.hpp"

nts::CounterGate::CounterGate(const std::string &name,
	nts::IComponent *firstGate, nts::IComponent *nextGate,
	nts::IComponent *Reset, nts::IComponent *Clock
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = firstGate;
	this->_pin[1] = Reset;
	this->_pin[2] = Clock;
	this->_next = nextGate;
	this->_lastClock = nts::UNDEFINED;
	this->_value = nts::FALSE;

	this->_pinLink.insert({1, 1});
}

nts::CounterGate::~CounterGate()
{
}

nts::CounterGate::CounterGate(CounterGate &other) : AbstractComponent(
	other._name, nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];

	this->_next = other._next;
	this->_lastClock = other._lastClock;
	this->_value = other._value;

	this->_pinLink[1] = other._pinLink[1];
}

nts::CounterGate &nts::CounterGate::operator=(CounterGate &other)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];

	this->_pinLink[1] = other._pinLink[1];
	this->_next = other._next;
	this->_lastClock = other._lastClock;
	this->_value = other._value;

	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::CounterGate::Copy()
{
	return new CounterGate(*this);
}

void nts::CounterGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::CounterGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

nts::Tristate nts::CounterGate::compute(std::size_t pin __attribute__((unused)))
{
	nts::Tristate reset = nts::UNDEFINED;

	if (this->_simul)
		return this->_value;
	try {
		reset = this->_pin[1]->compute();
	} catch (ComputeError &error) {
	}
	if (reset == nts::TRUE)
		((CounterGate * )(this->_pin[0]))->resetCounterGateList();
	else if (this->_pin[0])
		((CounterGate * )(this->_pin[0]))->updateCounterLink();
	else
		this->updateCounterLink();
	this->_lastClock = reset;
	this->_simul = true;
	return this->_value;
}

nts::IComponent *nts::CounterGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::CounterGate::getPinLink() const
{
	return this->_pinLink;
}

void nts::CounterGate::updateCounterLink(nts::Tristate update)
{
	nts::Tristate tmp = nts::UNDEFINED;

	if (this->_simul)
		return;
	this->_simul = true;
	tmp = this->_value;
	if (this->_pin[2] != nullptr) {
		try {
			tmp = this->_pin[2]->compute();
		} catch (ComputeError &error) {
		}
		tmp = (tmp == nts::TRUE) ? nts::FALSE : nts::TRUE;
		if (tmp == nts::FALSE || this->_lastClock == nts::UNDEFINED) {
			this->_lastClock = tmp;
			return;
		}
		this->_lastClock = tmp;
		this->_value = (this->_value == nts::TRUE) ? nts::FALSE : nts::TRUE;
	} else if (update != nts::UNDEFINED) {
		if (update == nts::TRUE)
			this->_value = (this->_value == nts::TRUE) ? nts::FALSE : nts::TRUE;
	}
	if (this->_next)
		((CounterGate * )(this->_next))->updateCounterLink((tmp == nts::TRUE && this->_value == nts::FALSE) ? nts::TRUE : nts::FALSE);
}

void nts::CounterGate::setFirstCounter(IComponent *first)
{
	this->_pin[0] = first;
}

void nts::CounterGate::resetCounterGateList(void)
{
	this->_value = nts::FALSE;
	if (this->_next)
		((CounterGate * )(this->_next))->resetCounterGateList();
}