/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include "Chipsets.hpp"
#include "Links.hpp"
#include "Parsing.hpp"
#include "ExceptionComponent.hpp"

int main(int ac, char **av)
{
	int ret = 0;

	if (ac < 2)
		std::cout << "USAGE: ./nanotekspice \"filename\"" << std::endl;
	else {
		try {
			nts::Parsing pars(av, ac);
		} catch (nts::ErrorArgument const &error) {
			std::cerr << "/!\\ ERROR on \"" << error.getName()
				<< "\"" << std::endl;
			std::cerr << " +--> " << error.what() << std::endl;
			ret = 84;
		} catch (nts::ErrorInputValueArg const &error) {
			std::cerr << "/!\\ ERROR on \"" << error.getName()
				<< "\"" << std::endl;
			std::cerr << " +--> " << error.what() << std::endl;
			ret = 84;
		} catch (nts::ErrorInFile const &error) {
			std::cerr << "/!\\ ERROR on \"" << error.getName()
				<< "\"" << std::endl;
			std::cerr << " +--> " << error.what() << std::endl;
			ret = 84;
		} catch (nts::SetLinkError const &error) {
			std::cerr << "/!\\ ERROR on " << error.getName()
				<< std::endl;
			std::cerr << " +--> " << error.what() << std::endl;
			ret = 84;
		}
	}
	return (ret);
}