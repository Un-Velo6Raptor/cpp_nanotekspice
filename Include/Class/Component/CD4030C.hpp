/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#ifndef CD4030C_HPP
# define CD4030C_HPP

# include "XorGate.hpp"

namespace nts {
	class CD4030C : public AbstractComponent {
		public:
		// Ctor, Dtor
		CD4030C(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~CD4030C();

		CD4030C(CD4030C &other);
		CD4030C &operator=(CD4030C &other);
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

#endif /* !CD4030C_HPP */
