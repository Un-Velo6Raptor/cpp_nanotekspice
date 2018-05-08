/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef NORGATE_HPP
# define NORGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class NorGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		NorGate(const std::string &name, nts::IComponent *firstPin, nts::IComponent *secondPin);
		~NorGate();

		// Copy constructor / operator
		NorGate(NorGate &other);
		NorGate &operator=(NorGate &other);
		IComponent *Copy();

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1) override;

		nts::Tristate truthTableExec(nts::Tristate, nts::Tristate);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		protected:

		private:
		nts::Tristate _value;

		IComponent *_pin[2];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !NORGATE_HPP */
