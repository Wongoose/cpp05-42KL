/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:16:00 by zwong             #+#    #+#             */
/*   Updated: 2023/09/25 14:54:34 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Learn how to compare attributes of 2 classes and call for signage in Bureaucrat and Form.
int main(void) {
	std::cout << RED << "----- TESTS INVALID FORM CREATION-----" << std::endl << std::endl;
	try {
		Form f1("Something", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f2("Something", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << GREEN << "----- TESTS TO SIGN FORMS -----" << std::endl << std::endl;
	
	Bureaucrat abby("Abby", 75);
	
	Form state_form("State form", 75, 150);
	Form presidential_form("Presidential form", 74, 150);
	// show copy
	Form kuala_lumpur(state_form);
	Form united_states(presidential_form);

	std::cout << std::endl << YELLOW << "----- FORM STATUSES w COPIED -----" << std::endl << std::endl;
	std::cout << state_form << std::endl;
	std::cout << presidential_form << std::endl;
	std::cout << kuala_lumpur << std::endl;
	std::cout << united_states << std::endl;

	std::cout << std::endl;
	
	abby.signForm(state_form);
	abby.signForm(presidential_form);

	std::cout << std::endl << MAGENTA << "----- FORM STATUSES w COPIED -----" << std::endl << std::endl;
	// shows that the forms are deep copies
	std::cout << state_form << std::endl;
	std::cout << presidential_form << std::endl;
	std::cout << kuala_lumpur << std::endl;
	std::cout << united_states << std::endl;
	
	std::cout << std::endl << GREEN << "----- PROMOTE ABBY TRY AGAIN -----" << std::endl << std::endl;
	abby.promoteGrade();
	
	try {
		presidential_form.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	abby.signForm(kuala_lumpur);
	abby.signForm(united_states);

	try {
		united_states.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN << "----- FROM STATUSES -----" << std::endl << std::endl;
	std::cout << state_form << std::endl
		<< presidential_form << std::endl
		<< kuala_lumpur << std::endl
		<< united_states << std::endl;

	std::cout << std::endl;
}
