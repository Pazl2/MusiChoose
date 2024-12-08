#ifndef CYMBALS_H
#define CYMBALS_H

#include "Percussion.h"

class Cymbals:public Percussion {

public:
    Cymbals(std::string model, std::string material, int count, double price) :
        Percussion(model, count, material, price)  {
        };

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << count << ";" << price;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        iss >> count >> delimiter >> price;
    }
};


#endif // CYMBALS_H
