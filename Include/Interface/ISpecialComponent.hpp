/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef ISPECIALCOMPONENT_HPP
# define ISPECIALCOMPONENT_HPP

namespace nts {
	class ISpecialComponent {
		public:
		virtual ~ISpecialComponent() = default;

		virtual nts::Tristate getValue() const = 0;
	};
}

#endif /* !ISPECIALCOMPONENT_HPP */