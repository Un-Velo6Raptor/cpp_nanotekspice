/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef COUNTERGATE_HPP
# define COUNTERGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class CounterGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		CounterGate(const std::string &name, nts::IComponent *firstGate,
			nts::IComponent *nextGate, nts::IComponent *Reset,
			nts::IComponent *Clock = nullptr);
		~CounterGate();

		// Copy constructor / operator
		CounterGate(CounterGate &other);
		CounterGate &operator=(CounterGate &other);
		IComponent *Copy();

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		nts::Tristate truthTableExec(nts::Tristate, nts::Tristate);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		void updateCounterLink(nts::Tristate update = nts::UNDEFINED);
		void setFirstCounter(IComponent *first);
		void resetCounterGateList(void);

		protected:
		nts::Tristate _lastClock;
		nts::Tristate _value;

		private:
		IComponent *_next;

		IComponent *_pin[3];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !COUNTERGATE_HPP */
