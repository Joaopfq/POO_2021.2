#pragma once

#include <iostream>
#include <set>

using namespace std;

class Tweet {

private:

    int id;
    string username;
    string msg;
    set<string> likes;
    Tweet *rt{nullptr};
    bool deleted{false};

public: 

    Tweet(int id, string username, string msg){
        this->id = id;
        this->username = username;
        this->msg = msg;
    }

    void setRt(Tweet* rt){
        this->rt = rt;
    }

    void setDeleted(){
        this->username = "";
        this->msg = "Esse tweet foi deletado";
        this->likes.clear();
        this->deleted = true;
    }

    bool isDeleted(){
        if (this->deleted) {
            return true;
        }
    }

    int getId(){
        return this->id;
    }
    
    string getSender(){
        return this->username;
    }

    string getMsg(){
        return this->msg;
    }
    
    void like(string username){
        this->likes.insert(username);
    }

    set<string> getLikes(){
        return this->likes;
    }
    
    string toString(){

        string str = to_string(this->id) + ":" + this->username + "(" + this->msg + ")\n";
        if (this->rt != nullptr) {
            str = str + "\t" + to_string(this->rt->id) + ":" + this->rt->username + "(" + this->rt->msg + ")\n";
        }
        return str;
    }
};