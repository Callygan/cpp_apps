#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Interfață pentru componente
class Component {
public:
    virtual void print() const = 0;
    virtual ~Component() {}
};

// Clasa frunza - reprezintă obiectul simplu (cuvântul)
class Leaf : public Component {
private:
    string word;

public:
    Leaf(const string& w) : word(w) {}

    void print() const override {
        cout << word << " ";
    }
};

// Clasa compozit - reprezintă obiectul compus (propoziția)
class Composite : public Component {
private:
    vector<shared_ptr<Component>> components;

public:
    void addComponent(const shared_ptr<Component>& component) {
        components.push_back(component);
    }

    void print() const override {
        for (const auto& component : components) {
            component->print();
        }
        cout << endl;
    }
};

int main() {
    // Creăm cuvinte (Frunze)
    shared_ptr<Component> word1 = make_shared<Leaf>("Hello");
    shared_ptr<Component> word2 = make_shared<Leaf>("world");

    // Creăm o propoziție (Composite) și adăugăm cuvintele la aceasta
    shared_ptr<Composite> sentence = make_shared<Composite>();
    sentence->addComponent(word1);
    sentence->addComponent(word2);

    // Printăm cuvintele și propoziția
    cout << "Words: ";
    word1->print();
    word2->print();

    cout << "\n\nSentence: ";
    sentence->print();

    return 0;
}
