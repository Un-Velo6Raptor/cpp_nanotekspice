/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef HCF4081B_HPP
# define HCF4081B_HPP

# include "AndGate.hpp"

namespace nts {

	class HCF4081B : public AbstractComponent {
		public:
		// Ctor, Dtor
		HCF4081B(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~HCF4081B();

		HCF4081B(HCF4081B &other);
		HCF4081B &operator=(HCF4081B &other);
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

#endif /* !HCF4081B_HPP */
