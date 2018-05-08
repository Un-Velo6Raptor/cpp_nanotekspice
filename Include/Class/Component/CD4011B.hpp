/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#ifndef CD4011B_HPP
 #define CD4011B_HPP

# include "NandGate.hpp"

namespace nts {
	class CD4011B : public AbstractComponent {
		public:
		// Ctor, Dtor
		CD4011B(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~CD4011B();

		CD4011B(CD4011B &other);
		CD4011B &operator=(CD4011B &other);
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

#endif /* !CD4011B_HPP */
