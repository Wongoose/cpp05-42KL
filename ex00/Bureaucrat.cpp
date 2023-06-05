/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:15:56 by zwong             #+#    #+#             */
/*   Updated: 2023/06/05 13:42:49 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

// name_ is set this way due to it being const
Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	std::cout << "Bureaucrat: Name constructor called" << std::endl;
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	this->grade_ = grade;
}

// name_ is set this way due to it being const
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.getName()) {
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	this->grade_ = copy.getGrade();
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat: Default destructor called" << std::endl; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat other) {
	std::cout << "Bureaucrat: copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

void Bureaucrat::promoteGrade() {
	if (this->grade_ == 1) throw GradeTooHighException();	
	this->grade_--;
	std::cout << this->name_ << " was promoted to grade " << this->grade_ << std::endl;
}

void Bureaucrat::demoteGrade() {
	if (this->grade_ == 150) throw GradeTooLowException();
	this->grade_++;
	std::cout << this->name_ << " was demoted to grade " << this->grade_ << std::endl;
}

std::string Bureaucrat::getName(void) const {
	return (this->name_);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade_);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Nope, grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Nope, grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return out;
}
