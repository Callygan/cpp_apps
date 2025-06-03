#include <iostream>

// Interfața veche
class OldInterface {
public:
    virtual void performOldAction() const {
        std::cout << "Performing old action.\n";
    }
};

// Interfața nouă
class NewInterface {
public:
    void performNewAction() const {
        std::cout << "Performing new action.\n";
    }
};

// Adaptorul care convertește interfața veche în interfața nouă
class Adapter : public OldInterface {
private:
    NewInterface newInterface;

public:
    virtual void performOldAction() const override {
        // Utilizăm noua interfață în implementarea vechii acțiuni
        newInterface.performNewAction();
    }
};

int main() {
    // Folosim Adapter pentru a integra funcționalitatea nouă în codul existent
    OldInterface* adapter = new Adapter();
    adapter->performOldAction();

    delete adapter;

    return 0;
}
