/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:16:00 by zwong             #+#    #+#             */
/*   Updated: 2023/06/05 13:21:55 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// OBJECTIVE: Learn how to use CatchExceptions aka. error
// Learn to use Try catch for clear error handling
int main(void) {
	Bureaucrat abby("Abby", 2);
	Bureaucrat ben("Ben", 149);
	std::cout << abby << std::endl;
	std::cout << ben << GREEN << std::endl;
	abby.promoteGrade();
	
	try {
		abby.promoteGrade();
	}
	catch (Bureaucrat::GradeTooHighException &err) {
		std::cout << err.what() << std::endl;
	} 
	
	ben.demoteGrade();

	try {
		ben.demoteGrade();
	}
	catch (Bureaucrat::GradeTooLowException &err) {
		std::cout << err.what() << std::endl;
	}

	std::cout << DEFAULT << abby << std::endl;
	std::cout << ben << std::endl;
}
