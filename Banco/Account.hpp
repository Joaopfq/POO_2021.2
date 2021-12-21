#pragma once

#include <iostream>

using namespace std;

class Account {
protected:
    float balance;
    string clientId;
    int id;
    string type;

public:
    Account(int id = 0, string clientId = ""){
        this->id = id;
        this->clientId = clientId;
    }

    virtual void monthlyUpdate() = 0;

    void withdraw(float value){
        this->balance = this->balance - value;
    } 

    void deposit(float value){
        this->balance = this->balance + value;
    }

    void transfer(Account* other, float value){
        other->deposit(value);
    }

    int getID(){
        return this->id;
    }

    int getBalance(){
        return this->balance;
    }

    string getClientId(){
        return this->clientId;
    }

    string getType(){
        return this->type;
    }

    void setType(string type){
        this->type = type;
    }

    void setId(int id){
        this->id = id;
    }

    string toString(){
        return this->clientId + ":" + to_string(this->balance) + ":" + this->type;
    }
};