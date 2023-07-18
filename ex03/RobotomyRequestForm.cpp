/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:09 by zwong             #+#    #+#             */
/*   Updated: 2023/07/18 16:06:48 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("Uknown") {
	std::cout << GREY << "RobotomyRequestForm: Default constructor called" << std::endl << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::cout << GREY << "RobotomyRequestForm: Target constructor called" << std::endl << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :AForm(copy) {
	std::cout << GREY << "RobotomyRequestForm: Copy constructor called" << std::endl << RESET;
	this->target_ = copy.target_;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm: Default destructor called" << std::endl; }


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << GREY << "RobotomyRequestForm: copy assignment operator called" << std::endl << RESET;
	this->target_ = other.target_;
	return (*this);
}

void RobotomyRequestForm::execAction() const {
	// Check executor grade
	std::cout << "RobotomyRequestForm: Making some driling noise..." << std::endl;
	if (std::rand() % 2)
		std::cout << "RobotomyRequestForm: " << this->target_ << " robotomization SUCCESSFULL!" << std::endl;
	else
		std::cout << "RobotomyRequestForm: " << this->target_ << " robotomization FAILED!" << std::endl;
}
