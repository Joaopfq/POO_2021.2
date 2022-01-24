#pragma once

#include "Timeline.hpp"
#include "User.hpp"

class Controller {
private: 
    map<string, User*> users;
    map<int, Tweet*> tweets;
    int nextTwId = 0;

    Tweet* createTweet(string sender, string msg){
        Tweet* tweet = new Tweet((this->nextTwId++), sender, msg);
        return tweet;
    }
public: 
    Controller(){
    }

    void addUser(string username){
        if(this->users.find(username) == this->users.end()){
            User* user = new User(username);            
            this->users.insert({username, user});
        } else {
            cout << "Usuario ja existe" << endl;
        }
    }

    User* getUser(string username){
        auto it = this->users.find(username);
        if(it != this->users.end()){
            return it->second;
        } else {
            cout << "Usuario nao encontrado" << endl;
            return nullptr;
        }
    }

    void sendTweet(string username, string msg){
        Tweet* tweet = createTweet(username, msg);
        User* user = getUser(username);
        user->sendTweet(tweet);
    }

    void sendRt(string username, string msg, int twId){
        auto it = users.find(username);
        if(it != users.end()){
            Tweet* tweet = it->second->getTimeline().getTweet(twId);
            Tweet* rt = createTweet(username, msg);
            rt->setRt(tweet);
            it->second->sendTweet(rt);
        } else {
            cout << "Usuario nao encontrado" << endl;
        }
    }

    void removeUser(string username){
        User* user = getUser(username);
        user->unfollowAll();
        user->rejectAll();
        for(auto tweet : user->getTimeline().getMyTweets()){
            tweet.second->setDeleted();
        }
        users.erase(username);
    }

    string toString(){
        string str = "Usuarios:\n" "\t|";
        for(auto user : this->users){
            str = str + user.first + "|";
        }
        return str + "\n";
    }
};