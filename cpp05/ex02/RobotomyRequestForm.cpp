#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	this->target = src.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const//AForm nesnesinin içindeki hiçbir değeri değiştirmeyeceğimizi garanti eder
{
	if (!this->getIsSigned())//form imzalı mı
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > this->getExecGrade())//imza yetkisi var mı
		throw AForm::GradeTooLowException();

	std::cout << "Drilling sounds" << std::endl;
	std::cout << "Drilling sounds" << std::endl;
	std::cout << "Drilling sounds" << std::endl;
	std::cout << "Drilling sounds" << std::endl;

	if (rand() % 2 == 0)
		std::cout << this->target << "has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << "robotomization failed" << std::endl;
	
}
