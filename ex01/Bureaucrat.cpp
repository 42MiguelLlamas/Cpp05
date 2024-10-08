#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1)
{ 
	std::cout << "Bureaucrat constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName() + ".1")
{
	this->grade = src.getGrade();
	std::cout << "Bureaucrat Copy Constructor called."<< std::endl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Bureaucrat::Bureaucrat(int g, std::string const nam): name(nam), grade(g)
{
	if (g > 150)
		throw GradeTooLowException();
	else if (g < 1)
		throw GradeTooHighException();
	else
		this->grade = g;
	
	std::cout << "Bureaucrat constructed with grade." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat = operator called." << std::endl;
	if (this == &src)
		return *this;

	this->grade = src.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return os;
}

std::string const Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade(int increment)
{
	if ((this->grade - increment) < 0)
		throw GradeTooHighException();
	this->grade =  this->grade - increment;
}

void Bureaucrat::decrementGrade(int decrement)
{
	if ((this->grade + decrement) > 150)
		throw GradeTooLowException();
	this->grade =  this->grade - decrement;
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}