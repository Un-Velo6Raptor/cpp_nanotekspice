/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef HEF4001B_HPP
# define HEF4001B_HPP

# include "NorGate.hpp"

namespace nts {

	class HEF4001B : public AbstractComponent {
		public:
		// Ctor, Dtor
		HEF4001B(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~HEF4001B();

		// Copy constructor / operator constructor
		HEF4001B(HEF4001B &other);
		HEF4001B &operator=(HEF4001B &other);
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

		IComponent *_pin[14];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !HEF4001B_HPP */
