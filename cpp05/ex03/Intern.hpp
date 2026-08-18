#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	//no name, no grade, and no unique characteristics.
public:
	Intern();
	~Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);

	//AForm* polmorphism/çok biçimlilik sağlar yani base class pointer sayesinde farklı sınıflardan nesneleri tek bir tür ile return edebiliyoruz
	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception {
	public:
		const char *what() const throw() {
			return "Unknown form!";
		}
	};
};

#endif