#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== TEST 1: Başarılı İmzalama ===" << std::endl;
    try {
        Bureaucrat ahmet("Ahmet", 10);
        Form ehliyetFormu("Ehliyet Başvurusu", 20, 10); // İmza için min grade 20 gerekli

        std::cout << ahmet << std::endl;
        std::cout << ehliyetFormu << std::endl;

        ahmet.signForm(ehliyetFormu); // Ahmet (10), 20'lik formu rahatça imzalar!
        std::cout << ehliyetFormu << std::endl; // Formun imzalandığını (1 veya Yes) görürüz
    }
    catch (std::exception& e) {
        std::cout << "Hata: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Yetersiz Derece İle İmzalama Denemesi ===" << std::endl;
    try {
        Bureaucrat mehmet("Mehmet", 50);
        Form gizliBelge("Gizli Belge", 10, 5); // İmza için min grade 10 gerekli

        std::cout << mehmet << std::endl;
        std::cout << gizliBelge << std::endl;

        mehmet.signForm(gizliBelge); // Mehmet (50), 10'luk formu imzalayamaz!
        std::cout << gizliBelge << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Hata: " << e.what() << std::endl;
    }

    return 0;
}