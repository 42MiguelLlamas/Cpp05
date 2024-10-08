#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern Constructor called." << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called." << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string form, const std::string target)
{
	int i = 0;
	std::string forms[] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};

	Form *(*all_forms[])(const std::string target) = {&makeShrubbery, &makePresident, &makeRobot};

	while (i < 3)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << " now." << std::endl;
			return (all_forms[i](target));
		}
		i++;
	}
	std::cout << "Intern can not create a form type: " << form << "." << std::endl;
	return (NULL);
}