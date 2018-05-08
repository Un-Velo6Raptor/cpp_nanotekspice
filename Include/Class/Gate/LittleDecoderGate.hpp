/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef LITTLEDECODERGATE_HPP
# define LITTLEDECODERGATE_HPP

# include "LatchGate.hpp"
# include "AbstractComponent.hpp"

namespace nts {

	class LittleDecoderGate : public AbstractComponent {
		public:
		// Constructor, Destructor
		LittleDecoderGate(const std::string &name, LatchGate *Latch, int OutputNumber, nts::IComponent *Inhibit);
		~LittleDecoderGate();

		// Copy constructor / operator
		LittleDecoderGate(LittleDecoderGate &other);
		LittleDecoderGate &operator=(LittleDecoderGate &other);
		IComponent *Copy();

		// IComponent functions
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

		// Abstract functions
		IComponent *getPin();
		std::unordered_map<std::size_t, std::size_t> getPinLink() const;

		protected:

		private:
		nts::Tristate _value;

		LatchGate *_gate;
		int _outputNumber;

		IComponent *_pin[1];
		std::unordered_map<std::size_t, std::size_t> _pinLink;

	};

}

#endif /* !LITTLEDECODERGATE_HPP */
