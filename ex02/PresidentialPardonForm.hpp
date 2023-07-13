/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:07 by zwong             #+#    #+#             */
/*   Updated: 2023/07/13 16:31:08 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_H
#define PRESIDENTIAL_H

#include <string>
#include <iostream>
#include <iomanip>
#include "AForm.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class PresidentialPardonForm : public AForm {
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		// Getters

		// Setters

		// Functions
		void execAction(void) const;

	private:
		std::string target_;
};
#endif