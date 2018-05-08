/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef MC14040B_HPP
# define MC14040B_HPP

# include "CounterGate.hpp"

namespace nts {

	class MC14040B : public AbstractComponent {
		public:
		// Ctor, Dtor
		MC14040B(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~MC14040B();

		MC14040B(MC14040B &other);
		MC14040B &operator=(MC14040B &other);
		IComponent *Copy();

		// IComponent Function
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		// Abstract Function
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		void resetSimulation();

		protected:

		private:
		nts::Tristate _value;

		IComponent *_pin[17];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !HCF4081B_HPP */
