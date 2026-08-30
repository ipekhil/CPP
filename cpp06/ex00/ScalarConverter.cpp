#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>

ScalarConverter :: ScalarConverter() {}
ScalarConverter :: ScalarConverter(const ScalarConverter& src) {(void)src;}
ScalarConverter& ScalarConverter :: operator=(const ScalarConverter& src) {(void)src;return(*this);}
ScalarConverter :: ~ScalarConverter() {}

//static cast built indir yani bir kütüphane ile dahil etmeden delete, new keywordleri gibi kullanabiliyoruz
//nan(not a number) = 0/0 , +inf -inf = 1/0 infinity
//float ise +inff -inff nanf
static bool isSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		return (true);
	}
	if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
		return (true);
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return (true);
	}
	return (false);
}

void ScalarConverter :: convert(const std::string &str)
{
	double	value;
	char	*endPtr;

	if (isSpecial(str))
		return ;
	//girilen metin 'a' '*' gibi bir karakter ise ASCII değerini double tipine cast ediyor
	if (str.length() == 1 && !std::isdigit(str[0]))
		value = static_cast<double>(str[0]);
	else
	{
		//strtod stringi double'a çevirir, çevirmesinin bittiği karakteri endPtr'e yazar yani hiç çevirmezse null kalır
		value = std::strtod(str.c_str(), &endPtr);
		if (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0'))
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "impossible" << std::endl;
			std::cout << "double: " << "impossible" << std::endl;
			return;
		}
	}

	//char için
	if (value < 0 || value > 127)
		std::cout << "char: " << "impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	//int için
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);//ondalıklı sayılarda virgülden sonra 1 basamak yazdırır
	//float için
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	//double için
	std::cout << "double: " << static_cast<double>(value) << std::endl;

}