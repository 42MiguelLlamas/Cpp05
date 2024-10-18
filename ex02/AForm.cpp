#include "AForm.hpp"

AForm::AForm() : name("Default"), gradeSign(10), gradeExec(10), signature(0)
{ 
	std::cout << "Form constructed." << std::endl;
}

AForm::AForm(const AForm &src): name(src.getName() + ".1")
{
	std::cout << "Form Copy Constructor called."<< std::endl;
	this->gradeSign = src.getGradeSign();
	this->gradeExec = src.getGradeExec();
	this->signature = src.getSigned();
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

AForm::AForm(std::string const nam, int gradeS, int gradeE): name(nam), gradeSign(gradeS), gradeExec(gradeE)
{
	this->signature = 0;
	std::cout << "Form constructed with grade." << std::endl;
	if (gradeS < 1 || gradeE < 1 )
		throw (AForm::GradeTooHighException());
	else if (gradeS > 150 || gradeE > 150 )
		throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{
	std::cout << "Form destroyed." << std::endl;
}

AForm &AForm::operator=(const AForm &src)
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

std::ostream& operator<<(std::ostream& os, AForm const& obj)
{
    os <<"Form name: " << obj.getName() << "." << 
	" Form grade to sign: " << obj.getGradeSign() << "." <<
	" Form grade to exec: " << obj.getGradeExec() << "."  <<
	"Signed: " << obj.getSigned() << ".";
    return os;
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGradeSign() const
{
	return this->gradeSign;
}

int AForm::getGradeExec() const
{
	return this->gradeExec;
}


bool AForm::getSigned() const
{
	return this->signature;
}

void AForm::beSigned(Bureaucrat const &a) 
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

void AForm::execute(Bureaucrat const &executor)
{
	if (!this->signature)
	{
		std::cout << "Form is not signed." << std::endl;
		return;
	}
	std::cout << "No concrete execution type." << std::endl;
	(void)executor;
};

