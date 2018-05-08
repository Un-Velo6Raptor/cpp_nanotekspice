/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef CD4514BC_HPP
# define CD4514BC_HPP

# include "LatchGate.hpp"
# include "LittleDecoderGate.hpp"

namespace nts {

	class CD4514BC : public AbstractComponent {
		public:
		// Ctor, Dtor
		CD4514BC(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~CD4514BC();

		CD4514BC(CD4514BC &other);
		CD4514BC &operator=(CD4514BC &other);
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
		LatchGate *_gate;

		private:
		nts::Tristate _value;

		IComponent *_pin[25];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !CD4514BC_HPP */
