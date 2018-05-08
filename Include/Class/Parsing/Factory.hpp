/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <map>
# include <iostream>
# include <functional>
# include <iterator>
# include "IComponent.hpp"
# include "HCF4081B.hpp"
# include "HEF4001B.hpp"
# include "HEF4071B.hpp"
# include "CD4011B.hpp"
# include "CD4030C.hpp"
# include "Input.hpp"
# include "Output.hpp"
# include "Clock.hpp"
# include "True.hpp"
# include "False.hpp"
# include "CD4069UBC.hpp"
# include "CD4514BC.hpp"
# include "CD4008BMS.hpp"
# include "MC14040B.hpp"
# include "ExceptionParsing.hpp"

namespace nts {
	class Factory {
		public:
		Factory();

		~Factory();

		void createMap();

		nts::IComponent *createCompo(const std::string &) const;

		private:
		std::map<std::string, nts::IComponent *> _map;
	};
}

#endif /* FACTORY_HPP */
