#ifndef SHRUBBERY_H
#define SHRUBBERY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
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

class ShrubberyCreationForm : public AForm {
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		// Destructor
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Getters

		// Setters

		// Functions
		void execAction(void) const;

	private:
		std::string target_;
		static std::string const shrubbery_;
};
#endif