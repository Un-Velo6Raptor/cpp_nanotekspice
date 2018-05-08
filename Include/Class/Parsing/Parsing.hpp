/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Header for Parsing clasd
*/

#ifndef PARSING_HPP
# define PARSING_HPP

# include <iostream>
# include <map>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <sstream>
# include <string>
# include <fstream>

# include "ExceptionParsing.hpp"
# include "Chipsets.hpp"
# include "Links.hpp"

namespace nts {
	class Parsing {
		public:
		// Constructor
		Parsing(char **, int);

		// Copy constructor && =operator
		Parsing(const Parsing &);

		Parsing &operator=(const Parsing &);

		// Destructor
		~Parsing();

		// Struct for arugments in command line
		struct argv {
			std::string _nameComponent;
			std::string _valueComponent;
		};

		// Getters
		std::vector <nts::Parsing::argv> getArgv() const;

		std::string getFile() const;

		nts::Parsing::argv makeArgs(const std::string &);

		// Function members
		void readFile();

		std::string removeSpace(std::string);

		void fillVector(std::vector <std::string>);

		std::vector <std::string> fillChipsets(std::vector <std::string>
		);

		void fillLinks(std::vector <std::string>);

		void fillWithArg();

		void stockChipsets(const std::string &);

		void stockLinks(const std::string &);

		void verifType(const std::string &);

		void verifName(const std::string &);

		void verifInput();

		void verifLink(const std::string &);

		void verifNameLink(const std::string &);

		void verifPinLink(const std::string &, const std::string &);

		void verifOutput();

		std::vector <std::string> findValue(std::string &, std::string &
		);

		std::string checkType(const std::string &, std::string &) const;

		private:
		std::string _file;
		std::vector <argv> _arguments;
		Chipsets _chipsets;
		Links _links;
		std::map <std::string, std::string> _verifComponent;
	};
}

#endif /* !PARSING_HPP */
