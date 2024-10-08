#include "Form.hpp"

Form::Form() : name("Default"), gradeSign(10), gradeExec(10), signature(0)
{ 
	std::cout << "Form constructed." << std::endl;
}

Form::Form(const Form &src): name(src.getName() + ".1")
{
	std::cout << "Form Copy Constructor called."<< std::endl;
	this->gradeSign = src.getGradeSign();
	this->gradeExec = src.getGradeExec();
	this->signature = src.getSigned();
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Form::Form(std::string const nam, int gradeS, int gradeE): name(nam), gradeSign(gradeS), gradeExec(gradeE)
{
	this->signature = 0;
	std::cout << "Form constructed with grade." << std::endl;
	if (gradeS < 1 || gradeE < 1 )
		throw (Form::GradeTooHighException());
	else if (gradeS > 150 || gradeE > 150 )
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form = operator called." << std::endl;
	if (this == &src)
		return *this;
	this->name = src.getName();
	this->gradeSign = src.getGradeSign();
	this->gradeExec = src.getGradeExec();
	this->signature = src.getSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& os, Form const& obj)
{
    os <<"Form name: " << obj.getName() << "." << 
	" Form grade to sign: " << obj.getGradeSign() << "." <<
	" Form grade to exec: " << obj.getGradeExec() << "."  <<
	"Signed: " << obj.getSigned() << "."<< std::endl;
    return os;
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGradeSign() const
{
	return this->gradeSign;
}

int Form::getGradeExec() const
{
	return this->gradeExec;
}


bool Form::getSigned() const
{
	return this->signature;
}

void Form::beSigned(Bureaucrat const &a) 
{
	if (a.getGrade() > this->getGradeSign())
	{
		std::cerr << "Bureaucrat: " << a.getName() << 
		", couldn't sign form " << this->getName() << ", because: "; 
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (a.getGrade() < this->getGradeSign() && this->getSigned() == 1)
	{
		std::cout << "Form: " << this->getName() <<
		", is already signed." << std::endl;
	}
	else
	{
		this->signature = 1;
		std::cout << "Bureaucrat: " << a.getName() << 
		", signed form: " << this->getName() << "." << std::endl; 
	}

};

void Form::execute(Bureaucrat const &executor)
{
	if (!this->signature)
	{
		std::cout << "Form is not signed." << std::endl;
		return;
	}
	std::cout << "No concrete execution type." << std::endl;
	(void)executor;
};

