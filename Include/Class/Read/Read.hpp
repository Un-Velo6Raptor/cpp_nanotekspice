/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Header for the read in 0
*/

#ifndef READ_HPP
# define READ_HPP

# include <iostream>
# include <string>
# include "CreateComponent.hpp"

namespace nts {

	class Read {
		public:
		Read(const std::vector<nts::IComponent *> &,
			const std::map<std::string, nts::Output *> &
		);

		~Read();

		void readInLine();

		// Command line
		int exitCommand(void);

		int displayCommand(void);

		int simulateCommand(void);

		int dumpCommand(void);

		int loopCommand(void);

		// Make ";"
		void readCommands(const std::string &);

		// Reset simulation
		void resetAllComponent(void);

		void AssignLineCommand(std::string name, int value);

		int tryToAssignLine(std::string line);

		private:

		std::vector<nts::IComponent *> _component;
		std::map<std::string, nts::Output *> _output;
		std::vector <std::string> _commands;
	};
}

#endif /* !READ_HPP*/
