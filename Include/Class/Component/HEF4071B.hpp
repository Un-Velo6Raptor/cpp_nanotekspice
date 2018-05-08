/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef HEF4071B_HPP
# define HEF4071B_HPP

# include "OrGate.hpp"

namespace nts {

	class HEF4071B : public AbstractComponent {
		public:
		// Ctor, Dtor
		HEF4071B(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~HEF4071B();

		// copy constructor / operator
		HEF4071B(HEF4071B &other);
		HEF4071B &operator=(HEF4071B &other);
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

#endif /* !HEF4071B_HPP */
