#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade, std::string const name);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &src);

		void incrementGrade(int increment);
		void decrementGrade(int decrement);
		std::string const getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj);

#endif