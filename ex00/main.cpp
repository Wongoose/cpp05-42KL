/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:16:00 by zwong             #+#    #+#             */
/*   Updated: 2023/09/25 11:52:59 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// OBJECTIVE: Learn how to use CatchExceptions aka. error
// Learn to use Try/Catch for clear error handling
int main(void) {
	std::cout << GREEN << "-----INTANTIATE OUT OF BOUNDS-----" << std::endl << RESET;
	try {
		Bureaucrat maxBob = Bureaucrat("MaxBob", 0);
		Bureaucrat minBob = Bureaucrat("MinBob", 151);		
	}
	catch(const std::exception &err) {
		std::cerr << RED << err.what() << std::endl << RESET;
	}
	std::cout << std::endl;
	
	std::cout << MAGENTA << "-----TEST PROMOTE/DEMOTE-----" << std::endl << RESET;
	Bureaucrat abby("Abby", 2);
	Bureaucrat ben("Ben", 149);
	std::cout << abby << std::endl;
	std::cout << ben << GREEN << std::endl;

	abby.promoteGrade(); // abby is now at 1
	
	try {
		abby.promoteGrade();
	}
	catch (Bureaucrat::GradeTooHighException &err) {
		std::cerr << RED << err.what() << std::endl << RESET;
	} 
	
	ben.demoteGrade(); // ben is now at 150

	try {
		ben.demoteGrade();
	}
	catch (Bureaucrat::GradeTooLowException &err) {
		std::cerr << RED << err.what() << std::endl << RESET;
	}
	std::cout << std::endl;
	
	std::cout << MAGENTA << "-----STATUS OF ABBY AND BEN-----" << std::endl << RESET;
	// check overload operator output format
	// check grade did not promote/demote if catch exception
	std::cout << abby << std::endl;
	std::cout << ben << std::endl;
}
