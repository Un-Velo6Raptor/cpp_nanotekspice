/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#ifndef CREATECOMPONENT_HPP
# define CREATECOMPONENT_HPP

#include <map>
#include <iostream>
#include <functional>
# include "AbstractComponent.hpp"
# include "Parsing.hpp"
# include "Factory.hpp"

namespace nts {
	class CreateComponent {
		public:
		CreateComponent(const Chipsets &, const Links &);

		~CreateComponent();

		void fillLinks(const std::string &, const Links &,
			const std::string &, const Chipsets &
		);

		std::string findType(const std::string &, const Chipsets &
		) const;

		void setValueIComponent(const IComponent *, const std::string &,
			const Chipsets &
		);

		nts::IComponent *findIComponent(const std::string &);

		void stockOutput(const Chipsets &);

		private:
		std::vector<nts::IComponent *> _component;
		std::map<std::string, nts::Output *> _output;
	};
}

#endif /* CREATECOMPONENT_HPP */
