/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef LATCHGATE_HPP
# define LATCHGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class LatchGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		LatchGate(const std::string &name, nts::IComponent *firstPin, nts::IComponent *secondPin, nts::IComponent *thirdPin, nts::IComponent *fourthPin);
		~LatchGate();

		// Copy constructor / operator
		LatchGate(LatchGate &other);
		LatchGate &operator=(LatchGate &other);
		IComponent *Copy();

		nts::Tristate computePin(int index);

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		// Getter
		int GetSelectedOutput() const;

		protected:

		private:
		nts::Tristate _value;
		int _selectedOutput;

		IComponent *_pin[5];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !LATCHGATE_HPP */
