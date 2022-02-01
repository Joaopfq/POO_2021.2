#include <iostream>

using namespace std;

class Organism{
    bool alive{true};
    string kingdom;

public:
    Organism(string kingdom = "") {
        this->kingdom = kingdom;
        cout << "Created" << endl;
    }

    ~Organism() {
        cout << "Destroyed" << endl;
    }

    bool isAlive() {
        return alive;
    }

    void kill(){
        alive = false;
    }
};