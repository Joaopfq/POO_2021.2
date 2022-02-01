#include "Organism.hpp"

class Animal : public Organism{
    string taxonomy;

public: 
    Animal(string taxonomy = "", string kingdom = ""): Organism(kingdom){ 
        this->taxonomy = taxonomy;
    }

    ~Animal() {

    }

    void eat() {
        cout << "Comeu" << endl;
    }

    void drink() {
        cout << "Bebeu" << endl;
    }
};