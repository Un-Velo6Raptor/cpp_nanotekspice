/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Header for Links class
*/

#ifndef LINKS_HPP
# define LINKS_HPP

# include "AbstractStatement.hpp"

namespace nts {
	class Links : public AbstractStatement {

		public :

		//Structure
		struct links {
			std::string _firstName;
			std::string _firstValue;
			std::string _secondName;
			std::string _secondValue;
		};

		// Constructors
		Links(const std::string &, const std::string &,
			const std::string &, const std::string &
		);

		Links();

		// Destructors
		~Links();

		// Copy constructor && operator=
		Links(const Links &);

		Links &operator=(const Links &);

		// New getters
		std::vector <nts::Links::links> getVector() const;

		nts::Links::links getStruct(std::size_t) const;

		std::string getNameSecond(std::size_t) const;

		std::string getValueSecond(std::size_t) const;

		void addLink(const std::string &, const std::string &,
			const std::string &, const std::string &
		);

		// Getters from abstract class
		std::string getName(std::size_t) const;

		std::string getValue(std::size_t) const;

		private:
		std::vector <links> _links;
	};
}

#endif /* !LINKS_HPP */
