#pragma once

#include "Tweet.hpp"
#include <map>

using namespace std;

    class Timeline {
private: 
    map<int, Tweet*> timeline; 
    map<int, Tweet*> myTweets;

public:
    
    Timeline(){
    }

    void storeTimeline(Tweet* tweet){
        timeline.insert({tweet->getId(), tweet});
    }

    void storeMyTweets(Tweet* tweet){
        myTweets.insert({tweet->getId(), tweet});
    }

    map<int, Tweet*> getMyTweets(){
        return this->myTweets;
    }

    map<int, Tweet*> getAll(){
        return this->timeline;
    }


    Tweet* getTweet(int id){
        auto it = this->timeline.find(id);
        if (it == timeline.end()) {
            cout << "Tweet nao encontrado!" << endl;
            return nullptr;
        } else {
            return it->second;
        }    
    }
    
    void removeMsgsFrom(string username){
        set<int> ids; 
        for (auto msg : this->timeline) {
            if (msg.second->getSender() == username) {
                ids.insert(msg.first);
            }
        }

        for (int id : ids) {
            this->timeline.erase(id);
        }
    }

    string toString(){
        string str;
        for(auto msg : this->timeline){
            str = str + msg.second->toString() + "\n";
        }
        return str;
    }
};