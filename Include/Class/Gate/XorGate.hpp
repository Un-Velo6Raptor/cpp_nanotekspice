/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#ifndef XORGATE_HPP
# define XORGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class XorGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		XorGate(const std::string &name, nts::IComponent *firstPin, nts::IComponent *secondPin);
		~XorGate();

		// Copy constructor / operator
		XorGate(XorGate &other);
		XorGate &operator=(XorGate &other);
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

		protected:

		private:
		nts::Tristate _value;

		IComponent *_pin[2];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !XORGATE_HPP */
