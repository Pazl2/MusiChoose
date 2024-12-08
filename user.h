#include <string>

#ifndef USER_H
#define USER_H

class User
{
private:
    std::string login;
    std::string passwordCipher;
    bool mode;
public:
    User(){};
    void setLoginPass(std::string lg, std::string ps, bool mode){
        this->login = lg;
        this->passwordCipher = ps;
        this->mode = mode;
    }

    std::string getLogin(){
        return this->login;
    }

    std::string getPass(){
        return this->passwordCipher;
    }

    bool getMode(){
        return this->mode;
    }
};

#endif // USER_H
