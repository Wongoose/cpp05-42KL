/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:05 by zwong             #+#    #+#             */
/*   Updated: 2023/07/18 16:33:40 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << GREY << "Intern: Default constructor called" << std::endl << RESET;
}

// no attribute to copy
Intern::Intern(const Intern &copy) {
	std::cout << GREY << "Intern: Copy constructor called" << std::endl << RESET;
    (void)copy;
}

Intern::~Intern() { std::cout << GREY << "Intern: Default destructor called" << std::endl << RESET; }

Intern &Intern::operator=(const Intern &other) {
	std::cout << GREY << "Intern: copy assignment operator called" << std::endl << RESET;
    (void)other;
	return (*this);
}

static AForm *createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

const char *Intern::InvalidFormName::what(void) const throw() {
    return ("Invalid form name!");
}

AForm *Intern::makeForm(std::string name, std::string target) {
    AForm *newForm = NULL;

    AForm *(*functions[3])(std::string const &target) = {
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&createShrubberyCreationForm,
	};

	std::string formList[3] = {"presidential", "robotomy", "shrubbery"};

    for (int i = 0; i < 3; i++) {
        if (name == formList[i]) {
            newForm = functions[i](target);
            std::cout << GREEN << "Intern creates " << name << std::endl << RESET;
            return (newForm);
        }
    }

    std::cout << RED << "Intern failed to create form with name: " << (name.length() == 0 ? "(null)" : name) << std::endl << RESET;
    throw Intern::InvalidFormName();
}