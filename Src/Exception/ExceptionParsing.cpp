/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include "ExceptionParsing.hpp"

nts::ExceptionParsing::ExceptionParsing(const std::string &message,
	const std::string &name
) : _message(message), _name(name)
{
}

nts::ExceptionParsing::~ExceptionParsing()
{
}

const std::string &nts::ExceptionParsing::getName() const
{
	return this->_name;
}

nts::ErrorArgument::ErrorArgument(const std::string &message,
	const std::string &name
) : ExceptionParsing(message, name)
{
}

nts::ErrorInputValueArg::ErrorInputValueArg(const std::string &message,
	const std::string &name
) : ExceptionParsing(message, name)
{
}

nts::ErrorInFile::ErrorInFile(const std::string &message,
	const std::string &name
) : ExceptionParsing(message, name)
{
}