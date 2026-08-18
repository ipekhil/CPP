#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Unnamed"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->isSigned = src.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecGrade() const
{
	return this->execGrade;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form : "<<f.getName() << " | isSigned : " << f.getIsSigned() << " | sign grade : " << f.getSignGrade() << " | exec grade : " << f.getExecGrade();
	return os;
}