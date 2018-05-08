/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by martin.januario@epitech.eu,
*/

#ifndef EXCEPTIONCOMPONENT_HPP
# define EXCEPTIONCOMPONENT_HPP

# include <iostream>
# include <string>

namespace nts {

	class ExceptionComponent : public std::exception {
		public:
		ExceptionComponent(std::string const &message,
			std::string const &name = "Unknown"
		);

		// Member Functions
		std::string const &getName() const;

		virtual const char *what() const throw()
		{
			return this->_message.c_str();
		};

		private:
		std::string _message;
		std::string _name;
	};

	class LinkError : public ExceptionComponent {
		public:
		LinkError(const std::string &message, const std::string &name);
	};

	class ComputeError : public ExceptionComponent {
		public:
		ComputeError(const std::string &message,
			const std::string &name
		);
	};

	class SetLinkError : public ExceptionComponent {
		public:
		SetLinkError(const std::string &message,
			const std::string &name
		);
	};

	class SetValueError : public ExceptionComponent {
		public:
		SetValueError(const std::string &message,
			const std::string &name
		);
	};
}

#endif /* !EXCEPTIONCOMPONENT_HPP */
