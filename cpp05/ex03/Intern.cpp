#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{
		(void)src;
	}
	return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

//amacı dışarıdan aldığı form ismine göre ilgili nesneyi dinamik olarak (new ile) oluşturup adresini döndürmek.
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	//lookup table:fonksiyon işaretçilerini stringlerle eşleştiriyoruz
	std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

	AForm* (*formCreators[3])(const std::string &target) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

	//string ve fonksiyon işaretçileri üzerinde dönüp, eşleşen ismi bulup ilgili fonksiyonu çağırıyoruz.
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "ERROR:Intern could not create " << formName << " because it is not a valid form name" << std::endl;
	return (NULL);
}