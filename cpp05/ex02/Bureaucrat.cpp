#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
  std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &src)
  {
    this->grade = src.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
