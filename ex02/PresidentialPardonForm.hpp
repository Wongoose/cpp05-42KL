#ifndef PRESIDENTIAL_H
#define PRESIDENTIAL_H

#include <string>
#include <iostream>
#include <iomanip>
#include "AForm.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class PresidentialPardonForm : AForm {
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		void swap(PresidentialPardonForm &first, PresidentialPardonForm &second);

		// Getters

		// Setters

		// Functions
		virtual void run(Bureaucrat const &bureaucrat) const;

	private:
};
#endif