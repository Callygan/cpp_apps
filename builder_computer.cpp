#include <iostream>
#include <string>

// Produsul pe care il construim
class Computer {
public:
    std::string cpu;
    std::string memory;
    std::string storage;
    std::string graphics_card;

    void display() {
        std::cout << "Computer: CPU=" << cpu << ", Memory=" << memory << ", Storage=" << storage << ", Graphics Card=" << graphics_card << std::endl;
    }
};

// Interfata Builder
class ComputerBuilder {
public:
    virtual void setCPU() = 0;
    virtual void setMemory() = 0;
    virtual void setStorage() = 0;
    virtual void setGraphicsCard() = 0;
    virtual Computer* getResult() = 0;
};

// Implementare concreta a Builder-ului
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() {
        computer = new Computer();
    }

    void setCPU() override {
        computer->cpu = "Intel i7";
    }

    void setMemory() override {
        computer->memory = "16GB";
    }

    void setStorage() override {
        computer->storage = "512GB SSD";
    }

    void setGraphicsCard() override {
        computer->graphics_card = "Nvidia GeForce RTX 3080";
    }

    Computer* getResult() override {
        return computer;
    }
};

int main() {
    // Crearea unui builder de tip GamingComputer
    ComputerBuilder* builder = new GamingComputerBuilder();

    // Directorul controleaza procesul de constructie
    builder->setCPU();
    builder->setMemory();
    builder->setStorage();
    builder->setGraphicsCard();

    // Obtinerea produsului finit
    Computer* gamingComputer = builder->getResult();

    // Afisarea produsului
    gamingComputer->display();

    delete builder;
    delete gamingComputer;

    return 0;
}
