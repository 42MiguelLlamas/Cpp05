#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45),target("Default")
{
	std::cout << "Robotomy constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm",  72, 45), target(target)
{
	std::cout << "Robotomy constructed with target." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm("Robotomy",  72, 45),target(src.target)
{
	std::cout << "Robotomy Copy Constructor called."<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Destroyed: " << this->getName() << "." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm = operator called." << std::endl;
	if (this == &src)
		return *this;
	this->target = src.target;
	return *this;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& obj)
{
    os <<"Form name: " << obj.getName() << "." << 
	" Form grade to sign: " << obj.getGradeSign() << "." <<
	" Form grade to exec: " << obj.getGradeExec() << "."  <<
	"Signed: " << obj.getSigned() << "."<< std::endl;
    return os;
}

void RobotomyRequestForm::execute(Bureaucrat const &a)
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
		std::cout << "*Drill Noises* " << this->target << " has been robotomized, success rate: 50/100." << std::endl;
		std::cout << a.getName() << " executed " << this->getName() << std::endl;
	}
}