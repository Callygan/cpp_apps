#include <iostream>
#include <string>

using namespace std;

class Handler {
public:
    virtual void handleRequest(const string& request) = 0;
    virtual ~Handler() {}
};

class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const string& request) override {
        if (request == "A") {
            cout << "ConcreteHandlerA handles the request." << endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
    
    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }

private:
    Handler* successor = nullptr;
};

class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const string& request) override {
        if (request == "B") {
            cout << "ConcreteHandlerB handles the request." << endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }

    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }

private:
    Handler* successor = nullptr;
};

class Client {
public:
    void makeRequest(Handler* handler, const string& request) {
        handler->handleRequest(request);
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;

    handlerA.setSuccessor(&handlerB);

    Client client;
    client.makeRequest(&handlerA, "A");
    client.makeRequest(&handlerA, "B");
    client.makeRequest(&handlerA, "C");

    return 0;
}
