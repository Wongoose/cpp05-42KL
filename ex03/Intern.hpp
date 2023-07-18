/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:32:19 by zwong             #+#    #+#             */
/*   Updated: 2023/07/18 16:01:55 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include <iomanip>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET	"\e[0m"
#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Intern {
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);

		// Destructor
		~Intern();

		// Operators
		Intern &operator=(const Intern &other);

		// Getters

		// Setters

		// Functions
        AForm *makeForm(std::string name, std::string target);

        // Exceptions - must use char *what()
		class InvalidFormName : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif