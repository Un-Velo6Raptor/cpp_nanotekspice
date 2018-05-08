/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Links class
*/

#include "Links.hpp"

nts::Links::Links()
{
}

nts::Links::~Links()
{
}

nts::Links::Links(const std::string &FirstName, const std::string &FirstValue,
	const std::string &SecondName, const std::string &SecondValue
)
{
	_links.push_back(links());
	_links[0]._firstName = FirstName;
	_links[0]._firstValue = FirstValue;
	_links[0]._secondName = SecondName;
	_links[0]._secondValue = SecondValue;
}

nts::Links::Links(const Links &other)
{
	this->_links = other.getVector();
}

nts::Links &nts::Links::operator=(const Links &other)
{
	this->_links = other.getVector();
	return *this;
}

std::vector <nts::Links::links> nts::Links::getVector() const
{
	return this->_links;
}

nts::Links::links nts::Links::getStruct(std::size_t pos) const
{
	return this->_links[pos];
}

std::string nts::Links::getNameSecond(std::size_t pos) const
{
	return this->_links[pos]._secondName;
}

std::string nts::Links::getValueSecond(std::size_t pos) const
{
	return this->_links[pos]._secondValue;
}

void nts::Links::addLink(const std::string &firstName,
	const std::string &firstValue, const std::string &secondName,
	const std::string &secondValue
)
{
	std::size_t size = _links.size();
	_links.push_back(links());
	_links[size]._firstName = firstName;
	_links[size]._firstValue = firstValue;
	_links[size]._secondName = secondName;
	_links[size]._secondValue = secondValue;
}

std::string nts::Links::getName(std::size_t pos) const
{
	return this->_links[pos]._firstName;
}

std::string nts::Links::getValue(std::size_t pos) const
{
	return this->_links[pos]._firstValue;
}