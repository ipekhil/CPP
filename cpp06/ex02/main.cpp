#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

// random olarak A,B,C nesnelerini üretir ve Base* olarak döndürür
Base *generate(void) {
  int random;

  random = std::rand() % 3;
  if (random == 0)
    return (new A());
  if (random == 1)
    return (new B());
  return (new C());
}

// pointer ile tipini kontrol eder. başarılı olursa adresini, başarısız olursa
// NULL döner dynamic cast runtime'da vtable'ına bakıp doğru sınıfı bulur
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

// referans ile tipini kontrol eder. başarılı olursa adresini, başarısız olursa
// exception döner referanslar asla NULL olamaz o yüzden dynamic cast NULL
// döndüremez, eğer başarısız olursa C++ bir exception fırlatır ve catch ile bu
// istisnayı yakalayıp bir sonraki bloğa bakarız.
void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    (void)a;
    return;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    (void)b;
    return;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    (void)c;
    return;
  } catch (std::exception &e) {
  }
  // hiçbirisine girmediyse
  std::cout << "Unknown" << std::endl;
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  for (int i = 0; i < 5; i++) {
    std::cout << "\n[Test " << i + 1 << "]" << std::endl;

    // 1. Rastgele A, B veya C nesnesi oluşturuluyor
    Base *randomObj = generate();

    // 2. Pointer ile tespit
    std::cout << "identify(Base*) -> ";
    identify(randomObj);

    // 3. Reference ile tespit (Nesneyi dereference edip yolluyoruz)
    std::cout << "identify(Base&) -> ";
    identify(*randomObj);

    // 4. Bellek temizliği (virtual destructor sayesinde türetilmiş sınıf da temizlenir)
    delete randomObj;
  }

  return 0;
}
