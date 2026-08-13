#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unnamed"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Constructor called" << std::endl;
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->isSigned = src.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecGrade() const
{
	return this->execGrade;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form : "<<f.getName() << " | isSigned : " << f.getIsSigned() << " | sign grade : " << f.getSignGrade() << " | exec grade : " << f.getExecGrade();
	return os;
}