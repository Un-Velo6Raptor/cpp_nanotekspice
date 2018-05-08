/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Interface for statement
*/
#ifndef ISTATEMENT_HPP
# define ISTATEMENT_HPP

# include <iostream>
# include <map>
# include <vector>
# include <stdexcept>
# include <algorithm>

namespace nts {
	class IStatement {
		public:

		// Destructor
		virtual ~IStatement() = default;

		// Getters
		virtual std::string getName(std::size_t) const = 0;

		virtual std::string getValue(std::size_t) const = 0;
	};
}

#endif /* !ISTATEMENT_HPP */
