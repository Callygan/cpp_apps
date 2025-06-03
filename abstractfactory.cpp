#include <iostream>

// Interfața pentru forma geometrică Circle
class Circle {
public:
    virtual void draw() = 0;
};

// Clasa concretă pentru forma geometrică Circle
class ConcreteCircle : public Circle {
public:
    void draw() override {
        std::cout << "Desenare cerc\n";
    }
};

// Interfața pentru forma geometrică Square
class Square {
public:
    virtual void draw() = 0;
};

// Clasa concretă pentru forma geometrică Square
class ConcreteSquare : public Square {
public:
    void draw() override {
        std::cout << "Desenare pătrat\n";
    }
};

// Interfața Abstract Factory pentru forme geometrice
class AbstractShapeFactory {
public:
    virtual Circle* createCircle() = 0;
    virtual Square* createSquare() = 0;
};

// Fabrica concretă pentru forme geometrice
class ConcreteShapeFactory : public AbstractShapeFactory {
public:
    Circle* createCircle() override {
        return new ConcreteCircle();
    }

    Square* createSquare() override {
        return new ConcreteSquare();
    }
};

int main() {
    AbstractShapeFactory* factory = new ConcreteShapeFactory();

    Circle* circle = factory->createCircle();
    Square* square = factory->createSquare();

    circle->draw();
    square->draw();

    delete factory;
    delete circle;
    delete square;

    return 0;
}
