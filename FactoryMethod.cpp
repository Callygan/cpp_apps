#include <iostream>


class Product {
public:
    virtual void display() = 0;
};

class ConcreteProductA : public Product {
public:
    void display() override {
        std::cout << "Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void display() override {
        std::cout << "Product B" << std::endl;
    }
};


class Creator {
public:
    virtual Product* createProduct() = 0;
};


class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->createProduct();
    productA->display();

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->createProduct();
    productB->display();

    delete creatorA;
    delete creatorB;
    delete productA;
    delete productB;

    return 0;
}