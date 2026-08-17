#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat president("President", 1);
    Bureaucrat intern("Intern", 150);

    std::cout << "--- 1. Shrubbery Test (File Creation) ---" << std::endl;
    ShrubberyCreationForm shrub("garden");
    president.signForm(shrub);
    president.executeForm(shrub);

    std::cout << "\n--- 2. Robotomy Test (Drilling Noise & 50% Chance) ---" << std::endl;
    RobotomyRequestForm robot("Target-1");
    president.signForm(robot);
    president.executeForm(robot);

    std::cout << "\n--- 3. Presidential Pardon Test (Pardon Action) ---" << std::endl;
    PresidentialPardonForm pardon("Criminal");
    president.signForm(pardon);
    president.executeForm(pardon);

    std::cout << "\n--- 4. Error Handling Test (Insufficient Grade) ---" << std::endl;
    PresidentialPardonForm classified("Classified_Doc");
    president.signForm(classified);
    intern.executeForm(classified); // Intern grade 150 cannot execute

    return 0;
}