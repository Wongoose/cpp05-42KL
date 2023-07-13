/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:30:55 by zwong             #+#    #+#             */
/*   Updated: 2023/07/13 16:30:56 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

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

class Bureaucrat;

class AForm {
	public:
		// Constructors
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &copy);

		// Destructor
		virtual ~AForm();

		// Operators
		AForm &operator=(const AForm &);

		// Getters
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		// Setters

		// Functions
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &bureaucrat) const;

		// Exceptions - must use char *what()
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	protected:
		virtual void execAction(void) const = 0;

	private:
		const std::string name_;
		bool is_signed_;
		const int sign_grade_;
		const int exec_grade_;
};

std::ostream& operator<<(std::ostream &out, const AForm &AForm);

#endif