/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef CD4069UBC_HPP
# define CD4069UBC_HPP

# include "NotGate.hpp"

namespace nts {

	class CD4069UBC : public AbstractComponent {
		public:
		// Ctor, Dtor
		CD4069UBC(const std::string name, nts::TypeOfComponent type = nts::BASE);
		~CD4069UBC();

		CD4069UBC(CD4069UBC &other);
		CD4069UBC &operator=(CD4069UBC &other);
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

#endif /* !CD4069UBC_HPP */
