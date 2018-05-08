/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#include "ExceptionComponent.hpp"

nts::ExceptionComponent::ExceptionComponent(const std::string &message,
	const std::string &name) : _message(message), _name(name)
{
}

const std::string &nts::ExceptionComponent::getName() const
{
	return this->_name;
}

nts::LinkError::LinkError(const std::string &message, const std::string &name)
	: ExceptionComponent(message, name)
{
}

nts::ComputeError::ComputeError(const std::string &message,
	const std::string &name) : ExceptionComponent(message, name)
{
}

nts::SetLinkError::SetLinkError(const std::string &message,
	const std::string &name) : ExceptionComponent(message, name)
{
}

nts::SetValueError::SetValueError(const std::string &message,
	const std::string &name) : ExceptionComponent(message, name)
{
}
