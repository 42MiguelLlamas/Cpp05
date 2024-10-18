#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5),target("Default")
{
	std::cout << "Presidential constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm",  25, 5), target(target)
{
	std::cout << "Presidential constructed with target." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form("Presidential",  25, 5),target(src.target)
{
	std::cout << "Presidential Copy Constructor called."<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Destroyed: " << this->getName() << "." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm = operator called." << std::endl;
	if (this == &src)
		return *this;
	this->target = src.target;
	return *this;
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& obj)
{
    os <<"Form name: " << obj.getName() << "." << 
	" Form grade to sign: " << obj.getGradeSign() << "." <<
	" Form grade to exec: " << obj.getGradeExec() << "."  <<
	"Signed: " << obj.getSigned() << ".";
    return os;
}

void PresidentialPardonForm::execute(Bureaucrat const &a)
{
	if (a.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSigned())
	{
		std::cout << "Error: Form is not signed." << std::endl;
		return;
	}
	else
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		std::cout << a.getName() << " executed " << this->getName() << std::endl;
	}
}