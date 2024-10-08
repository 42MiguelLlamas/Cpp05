#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat A(11,"A");
	ShrubberyCreationForm B;
	PresidentialPardonForm C;
	RobotomyRequestForm D;
	
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << D << std::endl;

	//AForm E("C", 0, 0); //This will fail because its abstract class;
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
		B.execute(A);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	

	
	return 0;
}