#include <iostream>

using namespace std;

class ImplementareDispozitiv {
public:
    virtual void actioneaza() = 0;
};

class ImplementareDispozitiv1 : public ImplementareDispozitiv {
public:
    void actioneaza() override {
        std::cout << "Dispozitiv 1 actioneaza." << std::endl;
    }
};

class ImplementareDispozitiv2 : public ImplementareDispozitiv {
public:
    void actioneaza() override {
        std::cout << "Dispozitiv 2 actioneaza." << std::endl;
    }
};

class Dispozitiv {
protected:
    ImplementareDispozitiv* implementare;

public:
    Dispozitiv(ImplementareDispozitiv* imp) : implementare(imp) {}

    virtual void utilizeazaDispozitiv() = 0;
};

class Dispozitiv1 : public Dispozitiv {
public:
    Dispozitiv1(ImplementareDispozitiv* imp) : Dispozitiv(imp) {}

    void utilizeazaDispozitiv() override {
        std::cout << "Utilizeaza dispozitiv 1. ";
        implementare->actioneaza();
    }
};

class Dispozitiv2 : public Dispozitiv {
public:
    Dispozitiv2(ImplementareDispozitiv* imp) : Dispozitiv(imp) {}

    void utilizeazaDispozitiv() override {
        std::cout << "Utilizeaza dispozitiv 2. ";
        implementare->actioneaza();
    }
};

int main() {

    ImplementareDispozitiv1 imp1;
    ImplementareDispozitiv2 imp2;

    Dispozitiv1 d1(&imp1);
    Dispozitiv2 d2(&imp2);

    d1.utilizeazaDispozitiv();
    d2.utilizeazaDispozitiv();

    return 0;
}
