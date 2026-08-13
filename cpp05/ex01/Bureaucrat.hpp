#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form; //forward declaration

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(const Bureaucrat &src);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void incrementGrade(); //--
  void decrementGrade(); //++

  //throw hata mesajı, catch hata yakaladıktan sonra çalışacak kod bloğu.
  //Ben std::exception soyundan gelen özel bir hatayım. 
  // Birisi benden hata mesajını istediğinde (e.what()), ana sınıftaki içi boş metni değil,
  // benim buraya yazdığım "Grade is too high!" metnini döndür
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

  void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif