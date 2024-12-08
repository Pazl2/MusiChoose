#ifndef GUITAR_H
#define GUITAR_H

#include "Stringed.h"

class Guitar : public Stringed {
    bool elec;
public:
    Guitar(std::string model, std::string material, int count, double price, int count_of_string, bool elec) :
        Stringed(model, count, material, count_of_string, price) {
        this->elec = elec;
    };

    void setElec (bool elec){
        this->elec = elec;
    }

    bool getElec (){
        return this->elec;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << count << ";" << price << ";" << count_of_string << ";" << elec;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        iss >> count >> delimiter >> price >> delimiter >> count_of_string >> delimiter >> elec;
    }

};


#endif // GUITAR_H
