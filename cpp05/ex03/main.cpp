#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someIntern;
    Bureaucrat president("President", 1);

    std::cout << "--- Form 1: Shrubbery ---" << std::endl;
    AForm *form1 = someIntern.makeForm("shrubbery creation", "garden");
    if (form1)
    {
        president.signForm(*form1);
        president.executeForm(*form1);
    }

    std::cout << "\n--- Form 2: Robotomy ---" << std::endl;
    AForm *form2 = someIntern.makeForm("robotomy request", "home");
    if (form2)
    {
        president.signForm(*form2);
        president.executeForm(*form2);
    }

    std::cout << "\n--- Form 3: Presidential Pardon ---" << std::endl;
    AForm *form3 = someIntern.makeForm("presidential pardon", "Criminal");
    if (form3)
    {
        president.signForm(*form3);
        president.executeForm(*form3);
    }

    std::cout << "\n--- Form 4: Invalid Form ---" << std::endl;
    AForm *form4 = someIntern.makeForm("unknown form", "Unknown");
    if (form4)
    {
        president.signForm(*form4);
        president.executeForm(*form4);
    }

    std::cout << "\n--- Memory Cleanup ---" << std::endl;
    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}