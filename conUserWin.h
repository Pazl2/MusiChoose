#ifndef CONUSERWIN_H
#define CONUSERWIN_H

#include <QString>
#include <QDebug>
#include <fstream>
#include "mainwindow.h"

std::string fileName = "../../users.txt";

std::unordered_map<std::string, std::pair<std::string, bool>> readUsers() {

    std::unordered_map<std::string, std::pair<std::string, bool>> users;

    std::ifstream file(fileName);

    if (!file.is_open()) return users;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, passwordHash;
        bool mode;

        if (std::getline(iss, username, ':') && std::getline(iss, passwordHash, ':')) {
            iss >> mode;
            users[username].first = passwordHash;
            users[username].second = mode;
        }
    }
    file.close();
    return users;
}

bool checkPass(std::string& lg, std::string& ps, bool* mode, std::unordered_map<std::string, std::pair<std::string, bool>>* users){

    std::string str = (*users)[lg].first;

    if(str != "" && str == ps){
        *mode = (*users)[lg].second;
        return true;
    } else return false;
}


bool is_exist(std::string& lg, bool *mode, std::unordered_map<std::string, std::pair<std::string, bool>>* users){
    std::string str = "";
    if((*users)[lg].first != str){
        *mode = (*users)[lg].second;
        return true;
    } else return false;
}

void loadUsers(std::unordered_map<std::string, std::pair<std::string, bool>>* users){
    std::ofstream file(fileName, std::ios::trunc);
    if (file.is_open()) {
        for (auto l: (*users)){
            if(l.second.first != ""){
                file << l.first << ":" << l.second.first << ":" << l.second.second << "\n";
            }
        }
        file.close();
    }else{
        qDebug() << "ОШИБКА РЕГИСТРАЦИИ!";
    }
    return;
}

void writeUser(std::string& lg, std::string& ps, bool& mode, std::unordered_map<std::string, std::pair<std::string, bool>>* users){
    (*users)[lg].first = ps;
    (*users)[lg].second = mode;
}

#endif // CONUSERWIN_H
