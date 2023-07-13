#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("Uknown") {
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::cout << "RobotomyRequestForm: Target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :AForm(copy) {
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	this->target_ = copy.target_;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm: Default destructor called" << std::endl; }


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm: copy assignment operator called" << std::endl;
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
