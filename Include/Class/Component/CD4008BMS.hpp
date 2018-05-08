/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef CD4008BMS_HPP
# define CD4008BMS_HPP

# include "SumGate.hpp"

namespace nts {

	class CD4008BMS : public AbstractComponent {
	public:
		// Ctor, Dtor
		CD4008BMS(const std::string name,
			nts::TypeOfComponent type = nts::BASE
		);

		~CD4008BMS();

		CD4008BMS(CD4008BMS &other);

		CD4008BMS &operator=(CD4008BMS &other);

		IComponent *Copy();

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

		void resetSimulation();

	private:
		nts::Tristate _value;

		IComponent *_gate[4];

		IComponent *_pin[17];
		std::unordered_map <std::size_t, std::size_t> _pinLink;
	};
}

#endif /* !CD4008BMS_HPP */
