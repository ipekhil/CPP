#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	this->target = src.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const//AForm nesnesinin içindeki hiçbir değeri değiştirmeyeceğimizi garanti eder
{
	if (!this->getIsSigned())//form imzalı mı
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > this->getExecGrade())//imza yetkisi var mı
		throw AForm::GradeTooLowException();
	
	// dosya oluşturma, çıktıyı dosyaya yazar
	//outfile:Bizim oluşturduğumuz dosya nesnesinin adıdır. Bu satır çalıştığı an işletim sistemi o klasörde dosyayı fiziksel olarak oluşturur.
	std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: File could not be created!" << std::endl;
        return;
    }
	outfile << "    *    \n"
			<< "   ***   \n"
			<< "  *****  \n"
			<< " ******* \n"
			<< "   |||   \n";
    outfile.close();
    std::cout << "Successfully created " << this->target << "_shrubbery" << std::endl;
}
