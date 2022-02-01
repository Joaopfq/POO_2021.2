#pragma once

#include "Timeline.hpp"

class User{
private: 
    string username;
    map<string, User*> followers; 
    map<string, User*> following; 
    Timeline timeline; 

public:
    User(string username){
        this->username = username;
    }

    void follow(User* other){
        auto name = other->username;
        if(this->following.find(name) == this->following.end()){

            this->following[name] = other;
            other->followers[this->username] = this;
        } else {
            cout << "Voce ja segue esse usuario!" << endl;
        }
    }

    void unfollow(string username){
        auto it = this->following.find(username);
        User* other = it->second;
        if (it != this->following.end() && other->followers.find(this->username) != other->followers.end()) {
            this->timeline.removeMsgsFrom(username);
            this->following.erase(it);
            it = other->followers.find(this->username);
            other->followers.erase(it);

        } else {
            cout << "Voce nao segue esse usuario!" << endl;
        }
        
    }

    void unfollowAll(){
        for (auto user : this->following){
            this->unfollow(user.second->username);
        }
    }

    void rejectAll(){
        for (auto user : this->followers){
            user.second->unfollow(this->username);
        }
    }

    
    void like(string username, int twId){
        for(auto& msg : this->timeline.getAll()){
            if(msg.first == twId){
                msg.second->like(username);
            } else{
                cout << "Tweet nao encontrado" << endl;
            }
        }
    }
    
    Timeline getTimeline(){
        return this->timeline;
    }
    
    void sendTweet(Tweet* tw){
        this->timeline.storeTimeline(tw);
        this->timeline.storeMyTweets(tw);
        for(auto follower : this->followers){ 
            follower.second->timeline.storeTimeline(tw);
        }
    }

    
    string toString(){
        string str = this->username + "\n\t" + "seguidores [";
        for (auto follower : this->followers) {
            str = str + follower.second->username + ",";
        }
        str = str + "]\n" + "\tseguidos" + " [";
        for (auto person : this->following) {
            str = str + person.second->username + ",";
        }
        return str + "]";
    }
};