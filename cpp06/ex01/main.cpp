#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "test";
    data.value = 3.14;

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Original ptr: " << ptr << std::endl;
    std::cout << "Raw value:    " << raw << std::endl;
    std::cout << "Result ptr:   " << result << std::endl;

	std::cout << "--------Original--------" << std::endl;
	std::cout << "name: " << data.name << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "value: " << data.value << std::endl;


	std::cout << "--------Result--------" << std::endl;
	std::cout << "name: " << result->name << std::endl;
	std::cout << "id: " << result->id << std::endl;
	std::cout << "value: " << result->value << std::endl;

    if (ptr == result)
        std::cout << "OK!" << std::endl;
    else
        std::cout << "KO!" << std::endl;

    return 0;
}