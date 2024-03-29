/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:15 by zwong             #+#    #+#             */
/*   Updated: 2023/07/18 16:07:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target_("Uknown") {
	std::cout << GREY << "ShrubberyCreationForm: Default constructor called" << std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
	std::cout << GREY << "ShrubberyCreationForm: Target constructor called" << std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	std::cout << GREY << "ShrubberyCreationForm: Copy constructor called" << std::endl << RESET;
	this->target_ = copy.target_;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm: Default destructor called" << std::endl; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << GREY << "ShrubberyCreationForm: copy assignment operator called" << std::endl << RESET;
	this->target_ = other.target_;
	return (*this);
}

void ShrubberyCreationForm::execAction() const {
	// NEXT: Check executors grade
	std::ofstream ofs;

	ofs.open((this->target_ + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::shrubbery_;
		std::cout << "ShrubberyCreationForm: Planted at "
				<< this->target_ << "_shrubbery." << std::endl;
		ofs.close();
	}
}

std::string const ShrubberyCreationForm::shrubbery_ =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";