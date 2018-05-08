/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef ABSTRACTCOMPONENT_HPP
# define ABSTRACTCOMPONENT_HPP

# include <iostream>
# include <string>
# include <unordered_map>
# include "IComponent.hpp"

namespace nts {

	class AbstractComponent : public IComponent {
	public:
		// Constructor + Copy Constructor + Operator Copy
		AbstractComponent(const std::string name,
			nts::TypeOfComponent type = nts::BASE,
			nts::TypeOfChipset t_chipset = nts::UNKNOWN
		);

		AbstractComponent(const AbstractComponent &other);

		AbstractComponent &operator=(const AbstractComponent &other);

		// Destructor
		virtual ~AbstractComponent() = 0;

		// Required Functions
		void dump() const;

		// Setter
		virtual void resetSimulation();

		void setType(nts::TypeOfComponent type);

		void setTypeChipset(nts::TypeOfChipset chipset);

		void setName(const std::string &name);

		// Getter
		std::string getName() const;

		nts::TypeOfComponent getType() const;

		nts::TypeOfChipset getTypeChipset() const;

		// Virtual functions
		virtual IComponent *getPin() = 0;

		virtual std::unordered_map <std::size_t, std::size_t> getPinLink() const = 0;

	protected:
		bool _simul; // Check if this component has already compute in this simulation, true: already compute

		std::string _name;
		nts::TypeOfComponent _type;
		nts::TypeOfChipset _tChipset;
	};
}

#endif /* !ABSTRACTCOMPONENT_HPP */
