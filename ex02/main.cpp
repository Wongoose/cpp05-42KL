/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:55:14 by zwong             #+#    #+#             */
/*   Updated: 2023/09/25 15:12:46 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Creating Derived Forms from AForm. Execution checking done in AForm.
// Difference is that each type of Form has an execution
// Note
// - Now we have added execution grade for each for form
// - Each form has it's own result if executed successfully
int	main(void)
{
	std::cout << GREEN << "----- BUREAUCRATS CREATION-----" << RESET << std::endl << std::endl;

	Bureaucrat	noob = Bureaucrat("Noob Nathan", 142);
	Bureaucrat	average = Bureaucrat("Average Andy", 65);
	Bureaucrat	pro = Bureaucrat("Pro Peter", 6);

	std::cout << std::endl << "Three bureaucrats created:\n"
			"\t1) " << noob << "\n"
			"\t2) " << average << "\n"
			"\t3) " << pro << std::endl << std::endl;

	std::cout << RED << "----- FORMS CREATION-----" << RESET << std::endl << std::endl;
	
	ShrubberyCreationForm	shrubForm = ShrubberyCreationForm("Forest");
	RobotomyRequestForm		robotomyForm("RobotForm");
	PresidentialPardonForm	pardonForm("PardonForm");

	std::cout << std::endl << "Three forms created:\n"
			"\t1) " << shrubForm << "\n"
			"\t2) " << robotomyForm << "\n"
			"\t3) " << pardonForm << std::endl << std::endl;

	std::cout << YELLOW << "----- SIGNING AND EXECUTING SHRUBBERY FORM-----" << RESET << std::endl << std::endl;

	noob.signForm(shrubForm);
	noob.executeForm(shrubForm);
	average.executeForm(shrubForm);
	std::cout << std::endl;

	std::cout << GREEN << "----- SIGNING AND EXECUTING ROBOTOMY REQUEST FORM-----" << RESET << std::endl << std::endl;
	average.executeForm(robotomyForm);
	average.signForm(robotomyForm);
	average.executeForm(robotomyForm);
	
	pro.executeForm(robotomyForm);
	std::cout << std::endl;
	
	std::cout << MAGENTA << "----- SIGNING AND EXECUTING PRESIDENTIAL PARDON FORM-----" << RESET << std::endl << std::endl;
	pro.executeForm(pardonForm);
	pro.signForm(pardonForm);
	pro.executeForm(pardonForm);
	pro.promoteGrade();
	pro.executeForm(pardonForm);

	std::cout << std::endl;
	return (0);
}
