/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Header for Exception Class in Parsing
*/

#ifndef EXCEPTIONPARSING_HPP
# define EXCEPTIONPARSING_HPP

# include <iostream>
# include <string>

namespace nts {
	class ExceptionParsing : public std::exception {

		public:

		// Constructor
		ExceptionParsing(const std::string &,
			const std::string & = "Unknown"
		);

		// Destructor
		~ExceptionParsing();

		// Getter
		std::string const &getName() const;

		// What ?
		virtual const char *what() const throw()
		{
			return this->_message.c_str();
		};

		private:
		std::string _message;
		std::string _name;
	};

	class ErrorFile : public ExceptionParsing {
		public:
		ErrorFile(const std::string &, const std::string &);
	};

	class ErrorArgument : public ExceptionParsing {
		public:
		ErrorArgument(const std::string &, const std::string &);
	};

	class ErrorInputValueArg : public ExceptionParsing {
		public:
		ErrorInputValueArg(const std::string &, const std::string &);
	};

	class ErrorInFile : public ExceptionParsing {
		public:
		ErrorInFile(const std::string &, const std::string &);
	};
}

#endif /* EXCEPTIONPARSING_HPP*/
