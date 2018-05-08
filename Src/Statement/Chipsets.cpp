/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Chipsets class
*/

#include "Chipsets.hpp"

nts::Chipsets::Chipsets(const std::string &type, const std::string &name,
	const std::string &value
)
{
	_chipsets.push_back(chipsets());
	_chipsets[0]._name = name;
	_chipsets[0]._type = type;
	_chipsets[0]._value = value;
}

nts::Chipsets::Chipsets()
{
}

nts::Chipsets::~Chipsets()
{
	_chipsets.push_back(chipsets());
}

std::vector <nts::Chipsets::chipsets> nts::Chipsets::getVector() const
{
	return this->_chipsets;
}

nts::Chipsets::Chipsets(const Chipsets &other)
{
	_chipsets = other.getVector();
}

nts::Chipsets &nts::Chipsets::operator=(const Chipsets &other)
{
	this->_chipsets = other.getVector();
	return *this;
}

std::string nts::Chipsets::getName(std::size_t pos) const
{
	return this->_chipsets[pos]._name;
}

std::string nts::Chipsets::getType(std::size_t pos) const
{
	return this->_chipsets[pos]._type;
}

std::string nts::Chipsets::getValue(std::size_t pos) const
{
	return this->_chipsets[pos]._value;
}

bool nts::Chipsets::findName(const std::string &name) const
{
	bool return_value = false;

	for (std::size_t x = 0; x < _chipsets.size() && !return_value; x++) {
		if (_chipsets[x]._name == name)
			return_value = true;
	}
	return return_value;
}

void nts::Chipsets::addValue(const std::string &type, const std::string &name,
	const std::string &value
)
{
	std::size_t size = _chipsets.size();
	_chipsets.push_back(chipsets());
	_chipsets[size]._name = name;
	_chipsets[size]._type = type;
	_chipsets[size]._value = value;
}

nts::Chipsets::chipsets nts::Chipsets::getStruct(std::size_t pos) const
{
	return this->_chipsets[pos];
}

void nts::Chipsets::setValue(const std::string &name, const std::string &value)
{
	for (std::size_t pos = 0; pos < _chipsets.size(); pos++) {
		if (_chipsets[pos]._name == name) {
			_chipsets[pos]._value = value;
		}
	}
}