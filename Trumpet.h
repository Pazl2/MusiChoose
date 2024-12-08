#ifndef TRUMPET_H
#define TRUMPET_H

#include "Wind.h"

class Trumpet :public Wind {
protected:
    std::string build;
    std::string type;
public:
    Trumpet(std::string model, std::string material, int count, double price, std::string type, std::string build) :
        Wind(model, count, material, price) {
        this->type = type;
        this->build = build;
    }

    std::string getBuild() {
        return this->build;
    }

    void setBuild(std::string build) {
        this->build = build;
    }

    std::string getType( ){
        return this->type;
    }

    void setType(bool type){
        this->type = type;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << type << ";" << build << ";" << count << ";" << price;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        std::getline(iss, type, ';');
        std::getline(iss, build, ';');
        iss >> count >> delimiter >> price;
    }
};


#endif // TRUMPET_H
