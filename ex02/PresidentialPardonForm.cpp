/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:05 by zwong             #+#    #+#             */
/*   Updated: 2023/07/13 16:31:06 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target_("Unkown") {
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target_(target) {
	std::cout << "PresidentialPardonForm: Target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	this->target_ = copy.target_;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm: Default destructor called" << std::endl; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm: copy assignment operator called" << std::endl;
	this->target_ = other.target_;
	return (*this);
}

void PresidentialPardonForm::execAction() const {
	// Check executor grade
	std::cout << "PresidentialPardonForm: " << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
