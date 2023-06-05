/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:15:54 by zwong             #+#    #+#             */
/*   Updated: 2023/06/05 17:38:06 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Form.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Form;

class Bureaucrat {
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat &operator=(Bureaucrat other);

		// Getters
		std::string getName(void) const;
		int getGrade(void) const;

		// Setters
		void promoteGrade();
		void demoteGrade();

		// Functions
		void signForm(Form &form);

		// Exceptions - must use char *what()
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string name_;
		int grade_;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif