#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137),target("Default")
{
	std::cout << "Shrubbery constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Shrubbery constructed with target." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form("Shrubbery", 145, 137),target(src.target)
{
	std::cout << "Shrubbery Copy Constructor called."<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Destroyed: " << this->getName() << "." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm = operator called." << std::endl;
	if (this == &src)
		return *this;
	this->target = src.target;
	return *this;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& obj)
{
    os <<"Form name: " << obj.getName() << "." << 
	" Form grade to sign: " << obj.getGradeSign() << "." <<
	" Form grade to exec: " << obj.getGradeExec() << "."  <<
	"Signed: " << obj.getSigned() << ".";
    return os;
}

void ShrubberyCreationForm::execute(Bureaucrat const &a)
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
		std::ofstream outfile (this->target.append("_shrubbery").c_str());
		outfile << "├── bin\n"
				"├── boot\n"
				"│   └── grub\n"
				"│       ├── fonts\n"
				"│       └── locale\n"
				"├── cdrom\n"
				"└── dev\n"
				"    ├── block\n"
				"    ├── bsg\n"
				"    └── bus\n"
				"        └── usb\n"
				"            ├── 001\n"
				"            └── 002\n" << 
				std::endl;
		std::cout << a.getName() << " executed " << this->getName() << std::endl;
		outfile.close();
	}
}