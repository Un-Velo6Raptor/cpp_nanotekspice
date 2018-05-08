/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef SUMGATE_HPP
# define SUMGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class SumGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		SumGate(const std::string &name, nts::IComponent *Carry, nts::IComponent *firstPin, nts::IComponent *secondPin, int place);
		~SumGate();

		// Copy constructor / operator
		SumGate(SumGate &other);
		SumGate &operator=(SumGate &other);
		IComponent *Copy();

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		nts::Tristate truthTableExec(nts::Tristate, nts::Tristate, nts::Tristate);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		// Getter
		nts::Tristate getCarry() const;

		protected:
		int _pos;
		nts::Tristate _carry;

		private:
		nts::Tristate _value;

		IComponent *_pin[3];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !SUMGATE_HPP */
