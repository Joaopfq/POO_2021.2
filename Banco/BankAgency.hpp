#pragma once

#include <iostream>
#include <unordered_map>
#include "Account.hpp"
#include "Client.hpp"
#include "CheckingAccount.hpp"
#include "SavingAccount.hpp"

class BankAgency {
    unordered_map<string, Client> clients;
    unordered_map<int, Account*> accounts;
    int nextAccountId = 0;

    Account* getAccount(int id){
        for (auto& account : this->accounts) {
            if (account.first == id) {
                return account.second;
            }
        }
        cout << "Não encontrado" << endl;  
    }

public:
    BankAgency(){

    }

    bool findClient(string name){
        for (auto& account : this->clients) {
            if (name == account.first) {
                return true;
            }
        }
        return false;
    }

    void addClient(string clientId){

        if (!findClient(clientId)) {
            Client client(clientId);
            CheckingAccount* checking = new CheckingAccount(this->nextAccountId++, clientId);
            SavingAccount* saving = new SavingAccount(this->nextAccountId++, clientId);

            client.addAccount(checking);
            client.addAccount(saving);

            this->clients[clientId] = client;
            this->accounts[checking->getID()] = checking;
            this->accounts[saving->getID()] = saving;
        } else {
            cout << "Cliente ja existe!" << endl;
        }
    }
    
    void withdraw(int idAccount, float value){

        if (value > 0) {
            this->accounts[idAccount]->withdraw(value);
        }
    }
    
    void deposit(int idAccount, float value){
        if (value > 0) {
            this->accounts[idAccount]->deposit(value);
        }
    }

    void transfer(int accountFrom, int accountTo, float value){
        if(value > 0){
            this->accounts[accountFrom]->withdraw(value);
            this->accounts[accountTo]->deposit(value);
        }
    }

    void monthlyUpdate(){
        for(auto account : accounts){
            account.second->monthlyUpdate();
        }
    }

    string toString(){
        string str = "Clients:\n";
        for (auto& client : this->clients) {
            vector<Account*> accounts = client.second.getAccounts();
            str = str + "- " + client.first + "[" + to_string(accounts[0]->getID()) + ", " + to_string(accounts[1]->getID()) + "]\n";

        }
        str = str + "\nAccounts:\n";
        for (auto& account : this->accounts) {
            str = str + to_string(account.second->getID()) + ":" + account.second->toString() + "\n";
        }
        return str;
    }
};