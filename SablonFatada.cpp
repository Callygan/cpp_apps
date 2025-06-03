#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stoc {
private:
    std::vector<T> elemente;

public:
    void adaugaElement(const T& elem) {
        elemente.push_back(elem);
    }

    void eliminaElement(const T& elem) {
        for (auto it = elemente.begin(); it != elemente.end(); ++it) {
            if (*it == elem) {
                elemente.erase(it);
                break;
            }
        }
    }

    void afiseazaStoc() const {
        std::cout << "Elemente in stoc: ";
        for (const auto& elem : elemente) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    

    Stoc<int> stocInt;
    stocInt.adaugaElement(10);
    stocInt.adaugaElement(20);
    stocInt.afiseazaStoc();

    stocInt.eliminaElement(10);
    stocInt.afiseazaStoc();

    Stoc<string> stocString;
    stocString.adaugaElement("ABC");
    stocString.adaugaElement("XYZ");
    stocString.afiseazaStoc();

    return 0;
}
