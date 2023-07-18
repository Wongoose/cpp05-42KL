/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:55:14 by zwong             #+#    #+#             */
/*   Updated: 2023/07/18 16:40:41 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void sign_and_exec(AForm *form) {
	Bureaucrat highPriest = Bureaucrat("High priest", 1);

	highPriest.signForm(*form);
	highPriest.executeForm(*form);
}

// Creating Derived Forms from AForm. Execution checking done in AForm.
int	main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "----- INTERN CREATE GOOD FORMS-----" << RESET << std::endl << std::endl;

	Intern bob = Intern();
	AForm *form;

	form = bob.makeForm("presidential", "forgive jacob");
	sign_and_exec(form);
	std::cout << std::endl;
	form = bob.makeForm("robotomy", "create terminator 2");
	sign_and_exec(form);
	std::cout << std::endl;
	form = bob.makeForm("shrubbery", "amazon");
	sign_and_exec(form);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << RED << "----- INTERN CREATE BAD FORMS-----" << RESET << std::endl << std::endl;
	try {
		form = bob.makeForm("presidential", ""); // can create but without target will be ""
		sign_and_exec(form);
		std::cout << std::endl;
		form = bob.makeForm("", "noname target"); // cannot create with "" no form name
		sign_and_exec(form);
		std::cout << std::endl;
		form = bob.makeForm("notarealform", ""); // cannot create with invalid form name
		sign_and_exec(form);
		std::cout << std::endl;
	} catch (std::exception &err) {
		std::cout << "Failed with catch err: " << err.what() << std::endl;
	}
	return (0);
}
