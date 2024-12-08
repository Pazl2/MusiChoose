#ifndef DRUMS_H
#define DRUMS_H

#include "Percussion.h"

class Drums :public Percussion {
    bool sticks;
    std::string type;
public:
    Drums(std::string model, std::string material, int count, double price, std::string type, bool sticks) :
        Percussion(model,count, material, price) {
        this->sticks = sticks;
        this->type = type;
    };

    void setStics(bool sticks){
        this->sticks = sticks;
    }
    void setType(bool type){
        this->type = type;
    }

    bool getStics( ){
        return this->sticks;
    }
    std::string getType( ){
        return this->type;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << type << ";" << count << ";" << price << ";" << sticks;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        std::getline(iss, type, ';');
        iss >> count >> delimiter >> price >> delimiter >> sticks;
    }
};


#endif // DRUMS_H
