#include <sstream>
#include "Controller.hpp"

Controller ctrl;

int main(){
    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            ctrl.addUser("Joao");
            ctrl.addUser("Pedro");
        } else if (cmd == "showU") {
            cout << ctrl.toString();
        } else if (cmd == "tweetar") {
            ctrl.sendTweet("Joao", "test 1");
            ctrl.sendTweet("Joao", "test 2");
            ctrl.sendTweet("Pedro", "test 3");
            ctrl.sendTweet("Pedro", "test 4");
        } else if (cmd == "follow") {
            User* user = ctrl.getUser("Joao");
            user->follow(ctrl.getUser("Pedro"));
        } else if (cmd == "unf") {
            User* user = ctrl.getUser("Joao");
            user->unfollow("Pedro");
        } else if (cmd == "showF") {
            User* user1 = ctrl.getUser("Joao");
            cout << user1->toString() << endl;
            User* user2 = ctrl.getUser("Pedro");
            cout << user2->toString() << endl;
        } else if (cmd == "showTJ") {
            User* user = ctrl.getUser("Joao");
            cout << user->getTimeline().toString() << endl;
        } else if (cmd == "showTP") {
            User* user = ctrl.getUser("Pedro");
            cout << user->getTimeline().toString() << endl;
        } else if (cmd == "like") {
            User* user = ctrl.getUser("Joao");
            user->like("Joao", 0);
        }
        else if (cmd == "rt") {
            ctrl.sendRt("Joao", "test rt1", 2);
        } else if (cmd == "rm") {
            ctrl.removeUser("Pedro");
        } else {
            cout << "Comando nao existe" << endl;
        }
    }
}