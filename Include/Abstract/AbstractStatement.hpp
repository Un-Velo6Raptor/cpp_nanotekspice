/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Header for Abstract Statement class
*/

#ifndef ABSTRACTSTATEMENT_HPP
# define ABSTRACTSTATEMENT_HPP

# include "IStatement.hpp"

namespace nts {
	class AbstractStatement : public IStatement {
	public:

		//Constructor
		AbstractStatement();

		// Destructor
		virtual ~AbstractStatement() = 0;

		// Getters
		std::string getName(std::size_t) const = 0;
		std::string getValue(std::size_t) const = 0;

	};
}

#endif /* !ABSTRACTSTATEMENT_HPP */
