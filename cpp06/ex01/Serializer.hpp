#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer{
	//will not be initializable by the user,,,bu yüzden private
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& src);
	public:
		//adres->sayı
		static uintptr_t serialize(Data* ptr);
		//sayı->adres
		static Data* deserialize(uintptr_t raw);
};

#endif