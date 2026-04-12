#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Constructor test ---" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();	
	delete j;
	delete i;
	
	std::cout << "--- Array of 10 AAnimals (5 Dog, 5 Cat) ---" << std::endl;
	const AAnimal* animals[10];
	for (int k = 0; k < 5; k++)
		animals[k] = new Dog();
	for (int k = 5; k < 10; k++)
		animals[k] = new Cat();

	std::cout << "--- Making sounds ---" << std::endl;
	for (int k = 0; k < 10; k++)
		animals[k]->makeSound();

	std::cout << "--- Deleting animals ---" << std::endl;
	for (int k = 0; k < 10; k++)
		delete animals[k];

	std::cout << "--- Deep copy test ---" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->ideas[0] = "I am the original Dog";

	Dog* dog2 = new Dog(*dog1);
	std::cout << "dog1 idea: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "dog2 idea: " << dog2->getBrain()->ideas[0] << std::endl;

	dog1->getBrain()->ideas[0] = "I changed my mind";
	std::cout << "After change - dog1 idea: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "After change - dog2 idea: " << dog2->getBrain()->ideas[0] << std::endl;

	delete dog1;
	delete dog2;

	return 0;
}
