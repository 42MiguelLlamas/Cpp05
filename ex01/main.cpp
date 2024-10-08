#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat A(11,"A");
	Form B("formulario", 10, 10);
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	try
	{
		B.beSigned(A);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << A << std::endl;
	try 
	{
		A.signForm(B);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << A << std::endl;
	try
	{
		A.incrementGrade(5);
		A.signForm(B);
		std::cout << B << std::endl;
		A.signForm(B);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	
	/*
	Form C("C", "0", "0"); This will fail
	try  Asi controlamos
	{
		Bureaucrat C(0,"C");
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << C << std::endl;
	*/
	return 0;
}