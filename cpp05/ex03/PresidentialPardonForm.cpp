#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	this->target = src.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const//AForm nesnesinin içindeki hiçbir değeri değiştirmeyeceğimizi garanti eder
{
	if (!this->getIsSigned())//form imzalı mı
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > this->getExecGrade())//imza yetkisi var mı
		throw AForm::GradeTooLowException();
	
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
