#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
	private:
		//not instantiable yani örneklendirilemez olduğu için private tanımlıyoruz
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
	public:
		//dışarıdan çağrılacak tek fonksiyon
        static void    convert(const std::string &str);
};

#endif
