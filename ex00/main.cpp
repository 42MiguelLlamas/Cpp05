#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat A(3,"A");
	Bureaucrat B(A);
	Bureaucrat D;
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << D << std::endl;
	try
	{
		A.decrementGrade(100);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << A << std::endl;
	try 
	{
		A.incrementGrade(100);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << A << std::endl;
	try
	{
		A.incrementGrade(10);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}

	
	//Bureaucrat C(0,"C"); //This will fail
	try  //Asi controlamos
	{
		Bureaucrat C(0,"C");
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< "Failed instance: " << e.what()<< std::endl;
	}
	//std::cout << C << std::endl;
	
	
	return 0;
}