#include "Animal.hpp"

class Person : public Animal{
    string name;
    int age;
    int stamina;
public: 
    Person(int age, string name = "", string taxonomy = "", string kingdom = "", int stamina = 20): Animal(taxonomy, kingdom) {
        this->age = age;
        this->name = name;
        this->stamina = stamina;
    }

    ~Person() {

    }

    void work(){
        cout << "Trabalhou" << endl;
        if(this->stamina == 5){
            cout << "Adquiriu burn-out" << endl;
        } else if (this->stamina == 0){
            cout << "Morreu de exaustao" << endl;
            kill();
        }
        this->stamina--;
    }

    void play(){
        cout << "Se divertiu" << endl;
        this->stamina = this->stamina + 2;
    }

    void rest(){
        cout << "Descansou" << endl;
        this->stamina = this->stamina + 10;
    }

    string toString(){
        if(isAlive()){
            return "-" + this->name + ":" + to_string(this->age) + ":" + to_string(this->stamina);
        }
        return "RIP " + this->name;
    }
};