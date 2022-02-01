#pragma once

#include <iostream>
#include "Account.hpp"
#include <vector>

class Client{

    string clientId;
    vector<Account*> accounts;

public : 
    Client(string clientId = ""){
        this->clientId = clientId;
    }

    void addAccount(Account* account){
        this->accounts.push_back(account);
    }

    string getClientId(){
        return this->clientId;
    }

    void setClientId(string clientId){
        this->clientId = clientId;
    }

    vector<Account*> getAccounts(){
        return this->accounts;
    }

    void setAccounts(vector<Account*> accounts){
        this->accounts = accounts;
    }

};