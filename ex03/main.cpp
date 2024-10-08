#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat A(11,"A");
	Intern B;
	Form *C = B.makeForm("No existe", "Here"); //Me devuelve un nulo.
	Form *D = B.makeForm("ShrubberyCreationForm", "Rubbber");
	Form *E = B.makeForm("RobotomyRequestForm", "Robot");
	Form *F = B.makeForm("PresidentialPardonForm", "Trump");
	
	std::cout << "\n---------Initial values--------"<< std::endl;
	std::cout << A;
	std::cout << *D;
	std::cout << *E;
	std::cout << *F;

	std::cout << "\n---------Signing Forms--------"<< std::endl;

	try
	{
		D->beSigned(A);
		E->beSigned(A);
		F->beSigned(A);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << "\n---------After Signing--------"<< std::endl;
	std::cout << *D;
	std::cout << *E;
	std::cout << *F;
	std::cout << "\n---------Signing from Bureaucrat--------"<< std::endl;
	try 
	{
		A.signForm(*D);
		A.signForm(*E);
		A.signForm(*F);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << "\n---------After Signing from Bureaucrat--------"<< std::endl;
	std::cout << *D;
	std::cout << *E;
	std::cout << *F;

	std::cout << "\n---------Executing D--------"<< std::endl;
	try
	{
		D->execute(A);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << "\n---------Executing E--------"<< std::endl;
	try
	{
		E->execute(A);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << "\n---------Executing F--------"<< std::endl;
	try
	{
		E->execute(A);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< A.getName() << " - Failed: " << e.what()<< std::endl;
	}
	std::cout << "\n---------Final values--------"<< std::endl;
	std::cout << *D;
	std::cout << *E;
	std::cout << *F;

	std::cout << "\n--------- Destructors--------"<< std::endl;
	delete C; //No hace falta, es para que no salte unused error.
	delete D;
	delete E;
	delete F;

	return 0;
}