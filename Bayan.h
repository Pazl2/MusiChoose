#ifndef BAYAN_H
#define BAYAN_H

#include "Wind.h"

class Bayan : public Wind {
    bool keys;
public:
    Bayan (std::string model, std::string material, int count, double price, bool keys) :
        Wind(model, count, material, price) {
        this->keys = keys;
    }

    void setKeys (bool keys){
        this->keys = keys;
    }

    int getKeys (){
        return this->keys;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << count << ";" << price << ";" << keys;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        iss >> count >> delimiter >> price >> delimiter >> keys;

    }

    ~Bayan(){};

};

#endif // BAYAN_H
