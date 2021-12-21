#pragma once

#include "Account.hpp"

class SavingAccount : public Account{
public:
    SavingAccount() : Account(){
        this->type = "CP";
    }

    SavingAccount(int id, string clientId) : Account(id, clientId){
        this->type = "CP";
    }

    void monthlyUpdate(){
        this->balance = this->balance + (balance/100.0);
    }
};