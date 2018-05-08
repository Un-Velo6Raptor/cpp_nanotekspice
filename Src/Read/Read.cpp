/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <csignal>
#include "Read.hpp"

std::sig_atomic_t gSignalStatus = 0;

nts::Read::Read(const std::vector<nts::IComponent *> &compenent,
	const std::map<std::string, nts::Output *> &output
)
{
	_component = compenent;
	_output = output;
}

nts::Read::~Read()
{
}

int nts::Read::displayCommand(void)
{
	for (auto it = _output.begin(); it != _output.end(); ++it) {
		it->second->display();
	}
	return 0;
}

int nts::Read::exitCommand(void)
{
	return -1;
}

void nts::Read::resetAllComponent(void)
{
	for (auto it = this->_component.begin();
		it != this->_component.end(); ++it) {
		(*it)->resetSimulation();
	}
}

int nts::Read::simulateCommand(void)
{
	for (auto it = _output.begin(); it != _output.end(); ++it) {
		it->second->compute();
	}
	resetAllComponent();
	return 0;
}

int nts::Read::dumpCommand(void)
{
	for (auto it = this->_component.begin();
		it != this->_component.end(); ++it) {
		(*it)->dump();
	}
	return 0;
}

static void signal_handler(int signal)
{
	gSignalStatus = signal;
}

int nts::Read::loopCommand(void)
{
	std::signal(SIGINT, signal_handler);

	while (gSignalStatus != 2)
		simulateCommand();
	gSignalStatus = 0;
	std::cout << std::endl;
	return 0;
}

void nts::Read::AssignLineCommand(std::string name, int value)
{
	bool checkSet = false;

	for (auto it = this->_component.begin();
		it != this->_component.end(); ++it) {
		if ((*it)->getName() == name) {
			checkSet = true;
			if ((*it)->getTypeChipset() == nts::INPUT)
				((Input *)(*it))->setValue((nts::Tristate)value);
			else
				std::cerr << "Can't set the value of this chipset" << std::endl;
			break;
		}
	}
	if (!checkSet)
		std::cerr << name << ": doesn't exist" << std::endl;
}

int nts::Read::tryToAssignLine(std::string line)
{
	std::string::size_type i = 0;

	for (; i < line.size() && (line[i] == ' ' || line[i] == '\t'); ++i);
	if (i == line.size())
		return (0);

	std::stringstream ss(line);
	std::string token;
	unsigned int index = 0;

	std::string name = "";
	int value = 0;

	while (std::getline(ss, token, '=')) {
		if (!index)
			name = token;
		else
			value = std::stoi(token);
		index++;
	}
	if (index == 2 && (value == 0 || value == 1))
		AssignLineCommand(name, value);
	else
		std::cerr << "'" << line << "' is not a valid command"
			<< std::endl;
	return 0;
}

void nts::Read::readCommands(const std::string &line)
{
	_commands.erase(_commands.begin(), _commands.end());

	std::stringstream ss(line);
	std::string token;

	while (std::getline(ss, token, ';')) {
		token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
		token.erase(std::remove(token.begin(), token.end(), '\t'), token.end());
		_commands.push_back(token);
	}
}

void nts::Read::readInLine()
{
	typedef int(nts::Read::*func)(void);
	std::map <std::string, func> listCommand;
	int ret = 1;

	listCommand.insert({"exit", &nts::Read::exitCommand});
	listCommand.insert({"display", &nts::Read::displayCommand});
	listCommand.insert({"simulate", &nts::Read::simulateCommand});
	listCommand.insert({"dump", &nts::Read::dumpCommand});
	listCommand.insert({"loop", &nts::Read::loopCommand});

	this->simulateCommand();
	this->displayCommand();

	std::cout << "> ";
	for (std::string line; std::getline(std::cin, line);) {
		ret = 1;
		readCommands(line);
		for (auto itCom = _commands.begin(); itCom != _commands.end();
			itCom++) {
			for (auto it = listCommand.begin();
				it != listCommand.end(); ++it) {
				if (!it->first.compare(*itCom)) {
					ret = (*this.*it->second)();
					break;
				}
			}
			if (ret == -1)
				return;
			if (ret)
				tryToAssignLine(*itCom);
		}
		std::cout << "> ";
	}
}