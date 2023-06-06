#include "AForm.hpp"

AForm::AForm() : name_(""), is_signed_(false), sign_grade_(1), exec_grade_(1) {}

// ALL use constructor const initialize
AForm::AForm(std::string name, int sign_grade, int exec_grade)
	: name_(name),  is_signed_(false), sign_grade_(sign_grade), exec_grade_(exec_grade) {

	if (this->sign_grade_ > 150 || this->exec_grade_ > 150) {
		this->~AForm();
		throw GradeTooLowException();
	} 
	if (this->sign_grade_ < 1 || this->exec_grade_ < 1) {
		this->~AForm();
		throw GradeTooHighException();
	}
}

AForm::AForm(const AForm &copy)
	: name_(copy.getName()), is_signed_(copy.getIsSigned()), sign_grade_(copy.getSignGrade()), exec_grade_(copy.getExecGrade()) {}

AForm::~AForm() { std::cout << "AForm: Default destructor called" << std::endl; }


AForm &AForm::operator=(const AForm &)
{
	std::cout << "AForm: copy assignment operator called" << std::endl;
	return (*this);
}

// Getters
std::string AForm::getName(void) const { return (this->name_); }
bool AForm::getIsSigned(void) const { return (this->is_signed_); }
int AForm::getSignGrade(void) const { return (this->sign_grade_); }
int AForm::getExecGrade(void) const { return (this->exec_grade_); }

// Functions
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->sign_grade_ < bureaucrat.getGrade()) throw GradeTooLowException();
	this->is_signed_ = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Nope, grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Nope, grade too low!";
}

// NEXT
std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << GREY << " ["
		<< "Signed: " << (AForm.getIsSigned() == 0 ? "false" : "true") << " | "
		<< "Grade to sign: " << AForm.getSignGrade() << " | "
		<< "Grade to execute: " << AForm.getExecGrade() << "]" << GREEN;
	return (out);
}