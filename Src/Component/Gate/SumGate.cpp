/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "SumGate.hpp"

nts::SumGate::SumGate(const std::string &name, nts::IComponent *Carry,
	nts::IComponent *firstPin, nts::IComponent *secondPin, int place
) : AbstractComponent(name, nts::GATE)
{
	this->_pin[0] = Carry;
	this->_pin[1] = firstPin;
	this->_pin[2] = secondPin;
	this->_pinLink.insert({1, 1});
	this->_pinLink.insert({2, 1});
	this->_pinLink.insert({3, 1});

	this->_pos = place;
	this->_carry = nts::FALSE;
}

nts::SumGate::~SumGate()
{
}

nts::SumGate::SumGate(SumGate &other) : AbstractComponent(other._name,
	nts::GATE)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];
	this->_pinLink[3] = other._pinLink[3];

	this->_carry = other._carry;
	this->_pos = other._pos;
}

nts::SumGate &nts::SumGate::operator=(SumGate &other)
{
	this->_pin[0] = other._pin[0];
	this->_pin[1] = other._pin[1];
	this->_pin[2] = other._pin[2];
	this->_pinLink[1] = other._pinLink[1];
	this->_pinLink[2] = other._pinLink[2];
	this->_pinLink[3] = other._pinLink[3];

	this->_carry = other._carry;
	this->_pos = other._pos;
	this->_name = other._name;
	this->_type = other._type;
	this->_tChipset = other._tChipset;
	return *this;
}

nts::IComponent *nts::SumGate::Copy()
{
	return new SumGate(*this);
}

void nts::SumGate::setLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't link a Gate to an another components",
		this->getName());
}

void nts::SumGate::DefineLink(std::size_t pin __attribute__((unused)),
	nts::IComponent &other __attribute__((unused)),
	std::size_t otherPin __attribute__((unused)))
{
	throw SetLinkError(
		"SetLinkError: Can't define a Gate to an another components",
		this->getName());
}

nts::Tristate nts::SumGate::truthTableExec(nts::Tristate first,
	nts::Tristate second, nts::Tristate CarryInput
)
{
	nts::Tristate value = nts::UNDEFINED;
	int tmp = 0;

	if (first == nts::UNDEFINED || second == nts::UNDEFINED ||
		CarryInput == nts::UNDEFINED)
		return value;

	tmp = (int)first + (int)second + (int)CarryInput;
	if (tmp > 2) {
		value = nts::TRUE;
		this->_carry = nts::TRUE;
	} else if (tmp == 2) {
		value = nts::FALSE;
		this->_carry = nts::TRUE;
	} else {
		this->_carry = nts::FALSE;
		value = (!tmp) ? nts::FALSE : nts::TRUE;
	}
	return value;
}

nts::Tristate nts::SumGate::compute(std::size_t pin)
{
	nts::Tristate first = nts::UNDEFINED;
	nts::Tristate second = nts::UNDEFINED;
	nts::Tristate CarryInput = nts::UNDEFINED;

	if (this->_simul)
		return ((this->_pos == 1 && !pin) ? this->_carry :
			this->_value);
	try {
		first = this->_pin[1]->compute();
	} catch (ComputeError &error) {
		first = nts::UNDEFINED;
	}
	try {
		second = this->_pin[2]->compute();
	} catch (ComputeError &error) {
		second = nts::UNDEFINED;
	}
	try {
		CarryInput = this->_pin[0]->compute();
		if (this->_pos != -1)
			CarryInput = ((SumGate * )(this->_pin[0]))->getCarry();
	} catch (ComputeError &error) {
		CarryInput = nts::UNDEFINED;
	}
	this->_simul = true;
	this->_value = truthTableExec(first, second, CarryInput);
	return ((this->_pos == 1 && !pin) ? this->_carry : this->_value);
}

nts::IComponent *nts::SumGate::getPin()
{
	return *this->_pin;
}

std::unordered_map <std::size_t, std::size_t> nts::SumGate::getPinLink() const
{
	return this->_pinLink;
}

nts::Tristate nts::SumGate::getCarry() const
{
	return this->_carry;
}