#ifndef VIOLIN_H
#define VIOLIN_H

#include "Stringed.h"

class Violin :public Stringed {
    bool smich;
    std::string type;
public:
    Violin(std::string model, std::string material, int count, double price, int count_of_string, std::string type, bool smich) :
        Stringed(model, count, material, count_of_string, price) {
        this->smich = smich;
        this->type = type;
    };

    void setSmich(bool smich){
        this->smich = smich;
    }
    void setType(bool type){
        this->type = type;
    }

    bool getSmich( ){
        return this->smich;
    }
    std::string getType( ){
        return this->type;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << type << ";" << count << ";" << price << ";" << count_of_string << ";" << smich;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {

        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        std::getline(iss, type, ';');
        iss >> count >> delimiter >> price >> delimiter >> count_of_string >> delimiter >> smich;

    }

};


#endif // VIOLIN_H
