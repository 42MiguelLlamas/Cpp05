#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string name;
		int gradeSign;
		int gradeExec;
		bool signature;
	public:
		AForm();
		AForm(const AForm &src);
		AForm(std::string const name, int gradeS, int gradeE);
		~AForm();

		AForm &operator=(const AForm &src);

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;

		void beSigned(Bureaucrat const &a);
		virtual void execute(Bureaucrat const &executor) = 0;

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

std::ostream& operator<<(std::ostream& os, AForm const& obj);

#endif