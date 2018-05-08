/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef ICOMPONENT_HPP
# define ICOMPONENT_HPP

# include "ExceptionComponent.hpp"

namespace nts {

	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	enum TypeOfComponent {
		BASE, // Cant set and Define a link
		TERMINAL, // Can set a link but can't define
		GATE, // Like Terminal
		PIN, // Can't set a link but he can define
	};

	enum TypeOfChipset {
		UNKNOWN, // Don't know the type of the chipset
		INPUT, // This chipset is an INPUT
		OUTPUT, // This chipset is an OUTPUT
		CLOCK,
		CHIPSET // This chipset is an chipset
	};

	class IComponent {
		public :
		// Destructor
		virtual ~IComponent() = default;

		virtual nts::Tristate compute(std::size_t pin = 1) = 0;

		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin
		) = 0;

		virtual void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin
		) = 0;

		virtual void dump() const = 0;

		virtual void resetSimulation() = 0;

		virtual IComponent *Copy() = 0;

		virtual nts::TypeOfComponent getType() const = 0;

		virtual nts::TypeOfChipset getTypeChipset() const = 0;

		virtual std::string getName() const = 0;

		virtual void setType(nts::TypeOfComponent type) = 0;

		virtual void setTypeChipset(nts::TypeOfChipset chipset) = 0;

		virtual void setName(const std::string &name) = 0;
	};
}

#endif /* !ICOMPONENT_HPP */
