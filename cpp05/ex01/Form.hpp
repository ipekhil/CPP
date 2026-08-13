#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat; // buna forward declaration deniyor '#include "Bureaucrat.hpp"' yazmamak için (sadece class ın varlığından bahsetmek için) yazıyoruz
class Form
{
	private:
		const std::string name;
		bool isSigned;
		int signGrade;
		int execGrade;

	public:
		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
  		
		class GradeTooHighException : public std::exception//public yazmayınca derleyici private olarak algıladı hatalı çalıştı
		{
			public:
				const char* what() const throw()
				{
					return "Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade is too low!";
				}
		};
		
		void beSigned(const Bureaucrat &b);

};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif