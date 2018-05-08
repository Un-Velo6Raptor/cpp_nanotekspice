/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef INPUT_HPP
# define INPUT_HPP

# include "AbstractComponent.hpp"
# include "ISpecialComponent.hpp"

namespace nts {

	class Input : public AbstractComponent, public ISpecialComponent {
		public:
		// Ctor --> type is for the input create via the file
		Input(const std::string name,
			nts::TypeOfComponent type = nts::TERMINAL);
		~Input();

		// Copy operator and copy constructor
		Input(Input &other);
		Input &operator=(Input &other);
		IComponent *Copy();

		void setValue(const nts::Tristate &value);
		nts::Tristate getValue() const;

		// IComponent Function
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin
		);
		void DefineLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin
		);
		nts::Tristate compute(std::size_t pin = 1);

		// Abstract Function
		IComponent *getPin();
		std::unordered_map <std::size_t, std::size_t> getPinLink() const;

		protected:

		private:
		nts::Tristate _value;

		IComponent *_pin[1];
		std::unordered_map <std::size_t, std::size_t> _pinLink;
	};
}

#endif /* !INPUT_HPP */
