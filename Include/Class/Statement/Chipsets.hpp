/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Chipsets class
*/

#ifndef CHIPSETS_HPP
# define CHIPSETS_HPP

# include "AbstractStatement.hpp"

namespace nts {
	class Chipsets : public AbstractStatement {
		public:

		// Structure
		struct chipsets {
			std::string _type;
			std::string _name;
			std::string _value;
		};

		// Destructor
		~Chipsets();

		// Constructor
		Chipsets();

		Chipsets(const std::string &, const std::string &,
			const std::string & = "undefined"
		);

		// Copy constructor && operator=
		Chipsets(const Chipsets &);

		Chipsets &operator=(const Chipsets &);

		// New getters
		nts::Chipsets::chipsets getStruct(std::size_t) const;

		std::string getType(std::size_t) const;

		std::vector <nts::Chipsets::chipsets> getVector() const;

		bool findName(const std::string &) const;

		void addValue(const std::string &, const std::string &,
			const std::string & = "undefined"
		);

		// New setters
		void setValue(const std::string &, const std::string &);

		// Getters from abstract class
		std::string getName(std::size_t) const;

		std::string getValue(std::size_t) const;

		private:
		std::vector <chipsets> _chipsets;
	};
}

#endif /* !CHIPSETS_HPP */
