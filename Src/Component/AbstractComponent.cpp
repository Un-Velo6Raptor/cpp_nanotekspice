/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "AbstractComponent.hpp"

nts::AbstractComponent::AbstractComponent(const std::string name,
	nts::TypeOfComponent type, nts::TypeOfChipset t_chipset
) : _simul(false), _name(name), _type(type), _tChipset(t_chipset)
{
}

nts::AbstractComponent::AbstractComponent(const AbstractComponent &other)
{
	this->_name = other.getName();
}

nts::AbstractComponent &nts::AbstractComponent::operator=(
	const AbstractComponent &other
)
{
	this->_name = other.getName();

	return *this;
}

nts::AbstractComponent::~AbstractComponent()
{
}

std::string nts::AbstractComponent::getName() const
{
	return this->_name;
}

nts::TypeOfComponent nts::AbstractComponent::getType() const
{
	return this->_type;
}

void nts::AbstractComponent::dump() const
{
	std::cout << "Dump ABSTRACT: " << this->_name << std::endl;
}

void nts::AbstractComponent::resetSimulation()
{
	this->_simul = false;
}

nts::TypeOfChipset nts::AbstractComponent::getTypeChipset() const
{
	return this->_tChipset;
}

void nts::AbstractComponent::setType(nts::TypeOfComponent type)
{
	this->_type = type;
}

void nts::AbstractComponent::setTypeChipset(nts::TypeOfChipset chipset)
{
	this->_tChipset = chipset;
}

void nts::AbstractComponent::setName(const std::string &name)
{
	this->_name = name;
}
