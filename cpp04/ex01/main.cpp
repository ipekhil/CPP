#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- new/delete tests ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Animal();
	delete j;
	delete i;
	delete k;

	std::cout << "--- Array of 10 Animals (5 Dog, 5 Cat) ---" << std::endl;
	const Animal* animals[10];
	for (int k = 0; k < 5; k++)
		animals[k] = new Dog();
	for (int k = 5; k < 10; k++)
		animals[k] = new Cat();

	std::cout << "--- Deleting animals array ---" << std::endl;
	for (int k = 0; k < 10; k++)
		delete animals[k];

	std::cout << "--- Deep copy test ---" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->ideas[0] = "I am the original Dog";

	Dog* dog2 = new Dog(*dog1);
	std::cout << "dog1->ideas[0]: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "dog2->ideas[0]: " << dog2->getBrain()->ideas[0] << std::endl;

	dog1->getBrain()->ideas[0] = "I changed my mind";
	std::cout << "After modifying d1:" << std::endl;
	std::cout << "dog1->ideas[0]: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "dog2->ideas[0]: " << dog2->getBrain()->ideas[0] << std::endl;

	delete dog1;
	delete dog2;

	return 0;
}
