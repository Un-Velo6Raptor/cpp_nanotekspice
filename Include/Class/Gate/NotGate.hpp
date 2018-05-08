/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef NOTGATE_HPP
# define NOTGATE_HPP

# include "AbstractComponent.hpp"

namespace nts {

	class NotGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		NotGate(const std::string &name, nts::IComponent *firstPin);
		~NotGate();

		// Copy constructor / operator
		NotGate(NotGate &other);
		NotGate &operator=(NotGate &other);
		IComponent *Copy();

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		nts::Tristate truthTableExec(nts::Tristate);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		protected:

		private:
		nts::Tristate _value;

		IComponent *_pin[1];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !NOTGATE_HPP */
