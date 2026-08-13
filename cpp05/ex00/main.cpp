#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: Gecerli Derece ve Terfi ---" << std::endl;
    try {
        Bureaucrat b1("Ahmet", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // Grade 1 olur
        std::cout << "Terfi sonrasi: " << b1 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Hata Yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Cok Yuksek Derece (0) ---" << std::endl;
    try {
        Bureaucrat b2("Mehmet", 0); // Exception fırlatacak
        std::cout << b2 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Hata Yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Cok Dusuk Derece (151) ---" << std::endl;
    try {
        Bureaucrat b3("Ayse", 151); // Exception fırlatacak
        std::cout << b3 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Hata Yakalandi: " << e.what() << std::endl;
    }

    return 0;
}