/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:30:35 by zwong             #+#    #+#             */
/*   Updated: 2023/07/13 16:30:36 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_(""), is_signed_(false), sign_grade_(1), exec_grade_(1) {}

// ALL use constructor const initialize
Form::Form(std::string name, int sign_grade, int exec_grade)
	: name_(name),  is_signed_(false), sign_grade_(sign_grade), exec_grade_(exec_grade) {

	if (this->sign_grade_ > 150 || this->exec_grade_ > 150) {
		this->~Form();
		throw GradeTooLowException();
	} 
	if (this->sign_grade_ < 1 || this->exec_grade_ < 1) {
		this->~Form();
		throw GradeTooHighException();
	}
}

Form::Form(const Form &copy)
	: name_(copy.getName()), is_signed_(copy.getIsSigned()), sign_grade_(copy.getSignGrade()), exec_grade_(copy.getExecGrade()) {}

Form::~Form() { std::cout << "Form: Default destructor called" << std::endl; }

void Form::swap(Form &first, Form &second)
{
	std::swap(first.is_signed_, second.is_signed_);
}

Form &Form::operator=(Form other)
{
	std::cout << "Form: copy assignment operator called" << std::endl;
	Form::swap(*this, other);
	return (*this);
}

// Getters
std::string Form::getName(void) const { return (this->name_); }
bool Form::getIsSigned(void) const { return (this->is_signed_); }
int Form::getSignGrade(void) const { return (this->sign_grade_); }
int Form::getExecGrade(void) const { return (this->exec_grade_); }

// Functions
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (this->sign_grade_ < bureaucrat.getGrade()) throw GradeTooLowException();
	this->is_signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Nope, grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Nope, grade too low!";
}

// NEXT
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << GREY << " ["
		<< "Signed: " << (form.getIsSigned() == 0 ? "false" : "true") << " | "
		<< "Grade to sign: " << form.getSignGrade() << " | "
		<< "Grade to execute: " << form.getExecGrade() << "]" << GREEN;
	return (out);
}