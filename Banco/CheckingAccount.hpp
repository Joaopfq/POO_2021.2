#pragma once

#include "Account.hpp"

class CheckingAccount : public Account{
public:

    CheckingAccount() : Account(){
        this->type = "CC";
    }

    CheckingAccount(int id, string clientId) : Account(id, clientId){
        this->type = "CC";
    }

    void monthlyUpdate(){
        this->balance = this->balance - 20;   
    }
};