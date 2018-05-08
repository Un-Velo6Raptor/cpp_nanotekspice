/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

# include "Parsing.hpp"
# include "CreateComponent.hpp"

nts::Parsing::Parsing(char **value, int size)
{
	_file = value[1];
	struct argv tmp;
	for (int x = 2; x < size; x++) {
		tmp = makeArgs(value[x]);
		_arguments.push_back(tmp);
	}
	readFile();
}

nts::Parsing::~Parsing()
{
}

std::string nts::Parsing::getFile() const
{
	return _file;
}

nts::Parsing::argv nts::Parsing::makeArgs(const std::string &arg)
{
	struct argv return_struct;
	std::size_t found = arg.find("=");
	std::size_t secondFound = arg.find("=", found + 1);
	std::istringstream iss(arg);
	std::string tmp;
	std::getline(iss, tmp, '=');
	return_struct._nameComponent = tmp;
	std::getline(iss, tmp, '=');
	return_struct._valueComponent = tmp;
	if (return_struct._valueComponent == "" || found == std::string::npos ||
		secondFound < std::string::npos) {
		throw ErrorArgument("Error with the argument : \"" + arg +
				"\". It's \"input_name=input_value\"",
			"nts::Parsing::makeArgs");
	} else if (return_struct._valueComponent != "0" &&
		return_struct._valueComponent != "1") {
		throw ErrorInputValueArg("Error with the input value argument."
			"\n The value it's only 0 or 1",
			"nts::Parsing::makeArgs");
	}
	return return_struct;
}

std::vector <nts::Parsing::argv> nts::Parsing::getArgv() const
{
	return this->_arguments;
}

nts::Parsing::Parsing(const Parsing &other)
{
	this->_arguments = other.getArgv();
	this->_file = other.getFile();
}

nts::Parsing &nts::Parsing::operator=(const Parsing &other)
{
	this->_arguments = other.getArgv();
	this->_file = other.getFile();
	return *this;
}

void nts::Parsing::readFile()
{
	std::vector <std::string> inFile;
	std::string line;
	std::size_t found;

	std::ifstream file(getFile().c_str(), std::ios::in);
	if (file) {
		while (std::getline(file, line)) {
			line = removeSpace(line);
			if (line != "" && ((found = line.find("#", 0)) != 0))
				inFile.push_back(line);
		}
		file.close();
		fillVector(inFile);
	} else {
		throw ErrorInFile("The file \"" + getFile() +
				"\" doesn't exist", "nts::Parsing::readFile");
	}
}

std::string nts::Parsing::removeSpace(std::string line)
{
	std::size_t pos = line.find("#");
	if (pos != std::string::npos)
		line.erase(pos, line.size() - pos);
	pos = line.find("\t");
	while (pos != std::string::npos) {
		line.replace(pos, 1, " ");
		pos = line.find("\t", pos);
	}
	pos = line.find("  ");
	while (pos != std::string::npos) {
		line.replace(pos, 2, " ");
		pos = line.find("  ", pos);
	}
	for (std::size_t found = line.find(' ', 0);
		found == 0; found = line.find(' ', 0))
		line.erase(0, 1);
	std::size_t found = line.find_last_of(' ');
	if (line != "" && (found == (line.size() - 1)))
		line.erase((line.size() - 1), 1);
	return line;
}

void nts::Parsing::fillVector(std::vector <std::string> inFile)
{
	for (std::size_t pos = 0; pos < inFile.size(); pos++) {
		std::size_t found = inFile[pos].find(' ');
		found = inFile[pos].find(' ', found + 1);
		if (found != std::string::npos) {
			throw ErrorInFile("The line : \"" + inFile[pos] +
				"\" is incorrect.", "nts::Parsing::fillVector");
		}
	}
	inFile = fillChipsets(inFile);
	fillLinks(inFile);
	std::size_t posChip;
	std::size_t posLink;
	for (posChip = 0; posChip < _chipsets.getVector().size(); posChip++);
	for (posLink = 0; posLink < _links.getVector().size(); posLink++);
	if (posChip == 0 || posLink == 0) {
		throw ErrorInFile("No .chipsets or .links section.",
			"nts::Parsing::fillVector");
	}
	verifOutput();
	nts::CreateComponent(_chipsets, _links);
}

void nts::Parsing::verifOutput()
{
	for (std::size_t pos = 0; pos < _chipsets.getVector().size(); pos++) {
		bool verifValue = false;
		if (_chipsets.getType(pos) == "output") {
			for (std::size_t posLink = 0; posLink <
				_links.getVector().size(); posLink++) {
				_links.getName(posLink);
				if (_links.getName(posLink) ==
					_chipsets.getName(pos))
					verifValue = true;
				else if (_links.getNameSecond(posLink) ==
					_chipsets.getName(pos))
					verifValue = true;
			}
			if (!verifValue)
				throw ErrorInFile(
					"Output \"" + _chipsets.getName(pos) +
						"\" is not "
							"linked to anything.",
					"nts::Parsing::verifOutput");
		}
	}
}

std::vector <std::string> nts::Parsing::fillChipsets(
	std::vector <std::string> inFile
)
{
	bool isChipsets = false;

	for (std::size_t pos = 0; pos < inFile.size(); pos++) {
		if (inFile[pos] == ".links:")
			isChipsets = false;
		else if (isChipsets) {
			stockChipsets(inFile[pos]);
			inFile.erase(inFile.begin() + pos--);
		} else if (inFile[pos] == ".chipsets:") {
			inFile.erase(inFile.begin() + pos--);
			isChipsets = true;
		}
	}
	fillWithArg();
	verifInput();
	return inFile;
}

void nts::Parsing::verifInput()
{
	for (std::size_t pos = 0; pos < _chipsets.getVector().size(); pos++) {
		std::string type = _chipsets.getType(pos);
		std::string value = _chipsets.getValue(pos);
		if (type == "input" || type == "clock") {
			if (value == "undefined") {
				throw ErrorInFile(
					"The input type need a value.",
					"nts::Parsing::verifInput");
			}
		}
	}
}

void nts::Parsing::fillWithArg()
{
	for (std::size_t pos = 0; pos < _arguments.size(); pos++) {
		bool checkArg = false;
		for (size_t i = 0; i < _chipsets.getVector().size(); i++) {
			if ((_chipsets.getName(i) ==
				_arguments[pos]._nameComponent) && (
				(_chipsets.getType(i) == "input")
			 || _chipsets.getType(i) == "clock")) {
				checkArg = true;
				_chipsets.setValue(
					_arguments[pos]._nameComponent,
					_arguments[pos]._valueComponent);
			}
		}
		if (!checkArg) {
			throw ErrorInFile("The argument input name \"" +
					_arguments[pos]._nameComponent +
					"\" doesn't exist",
				"nts::Parsing::fillWithArg");
		}
	}
}

void nts::Parsing::fillLinks(std::vector <std::string> inFile)
{
	for (std::size_t pos = 0; pos < inFile.size(); pos++) {
		if (inFile[pos] != ".links:")
			stockLinks(inFile[pos]);
		inFile.erase(inFile.begin() + pos--);
	}
}

void nts::Parsing::stockChipsets(const std::string &line)
{
	std::string type;
	std::string name;

	std::istringstream iss(line);
	std::getline(iss, type, ' ');
	std::getline(iss, name, ' ');
	if (name == "") {
		throw ErrorInFile("The line : \"" + line +
				"\" is incorrect. You need \"componentType "
					"componentName(componentValue)\".",
			"nts::Parsing::fillVector");
	}
	std::vector <std::string> value;
	value = findValue(name, type);
	verifType(type);
	verifName(value[0]);
	_chipsets.addValue(type, value[0], value[1]);
}

void nts::Parsing::stockLinks(const std::string &line)
{
	std::string firstName;
	std::string secondName;

	std::istringstream iss(line);
	std::getline(iss, firstName, ' ');
	std::getline(iss, secondName, ' ');
	verifLink(firstName);
	verifLink(secondName);
	std::string nameOne;
	std::string firstPin;
	std::string nameTwo;
	std::string secondPin;
	std::istringstream css(firstName);
	std::getline(css, nameOne, ':');
	std::getline(css, firstPin, ':');
	std::istringstream oss(secondName);
	std::getline(oss, nameTwo, ':');
	std::getline(oss, secondPin, ':');
	_links.addLink(nameOne, firstPin, nameTwo, secondPin);
}

void nts::Parsing::verifLink(const std::string &link)
{
	std::string name;
	std::string pin;

	std::istringstream iss(link);
	std::getline(iss, name, ':');
	std::getline(iss, pin, ':');
	if (pin == "")
		throw ErrorInFile("The link \"" + link + "\" is false. "
			"You need \"name:pin\".", "nts::Parsing::verifLink");
	verifNameLink(name);
	verifPinLink(pin, name);
}

void nts::Parsing::verifNameLink(const std::string &name)
{
	bool findName = false;
	for (std::size_t pos = 0;
		pos < _chipsets.getVector().size() && !findName; pos++) {
		if (_chipsets.getName(pos) == name)
			findName = true;
	}
	if (!findName)
		throw ErrorInFile("The name \"" + name + "\" doesn't exist",
			"nts::Parsing::verifNameLink");
}

void nts::Parsing::verifPinLink(const std::string &pin, const std::string &name)
{
	std::string type;
	for (std::size_t pos = 0; pos < _chipsets.getVector().size(); pos++) {
		if (_chipsets.getName(pos) == name)
			type = _chipsets.getType(pos);
	}
	if (type == "input" || type == "true" || type == "false" ||
		type == "clock" || type == "output") {
		if (pin != "1") {
			throw ErrorInFile("The name \"" + name +
					"\" need a pin with the value \"1\".",
				"nts::Parsing::verifPinLink");
		}
	}
}

void nts::Parsing::verifType(const std::string &type)
{
	std::vector <std::string> _allType{"input", "true", "false", "clock",
		"output", "2716", "4001", "4008", "4011", "4013", "4017",
		"4030", "4040", "4069", "4071", "4081", "4094", "4503", "4512",
		"4514", "i4004", "mk4801"};
	std::vector<std::string>::iterator it;

	it = find(_allType.begin(), _allType.end(), type);
	if (it == _allType.end()) {
		throw ErrorInFile("The type \"" + type + "\" doesn't exist.",
			"nts::Parsing::verifType");
	}
}

void nts::Parsing::verifName(const std::string &name)
{
	std::vector <nts::Chipsets::chipsets> _allName = _chipsets.getVector();

	for (std::size_t pos = 0; pos < _allName.size(); pos++) {
		if (_allName[pos]._name == name) {
			throw ErrorInFile("The name \"" + name + "\" "
				"already exist.", "nts::Parsing::verifName");
		}
	}
}

std::vector <std::string> nts::Parsing::findValue(std::string &name,
	std::string &type
)
{
	std::vector <std::string> return_value = {name, "undefined"};
	std::size_t found = name.find("(");
	if (found != std::string::npos) {
		std::size_t secFound = name.find(")");
		if (secFound < found || secFound + 1 < name.size() ||
			secFound == std::string::npos) {
			throw ErrorInFile("The name : \"" + name + "\" is "
					"incorrect.","nts::Parsing::findValue");
		}
		return_value[1] = name.substr(found + 1, secFound - found - 1);
		return_value[0] = name.substr(0, found);
		if ((return_value[1] != "0" && return_value[1] != "1") &&
			(type == "input" || type == "true" ||
				type == "false" || type == "clock")) {
			throw ErrorInFile("For the type : \"" + type + "\" is "
				"only '0' or '1'", "nts::Parsing::findValue");
		}
		else if (return_value[1] != "undefined" && type == "output")
			throw ErrorInFile("The output doesn't have a value.",
				"nts::Parsing::findValue");
	}
	return_value[1] = checkType(type, return_value[1]);
	return (return_value);
}

std::string nts::Parsing::checkType(const std::string &type, std::string &value) const
{
	if (type == "true")
		value = "1";
	else if (type == "false")
		value = "0";
	else if (type == "output")
		value = "UNDEF";
	return (value);
}