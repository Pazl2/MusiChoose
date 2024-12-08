#ifndef PIANO_H
#define PIANO_H
#include "Instrument.h";

class Piano : public Instrument {
protected:

    int count_of_keys;


public:
    Piano(std::string model, std::string material, int count, double price, int count_of_keys) :
        Instrument(model, count, material, price) {
        this->count_of_keys = count_of_keys;
    }

    int getCOKeys() {
        return this->count_of_keys;
    }

    void setCOKeys(int count_of_keys) {
        this->count_of_keys = count_of_keys;
    }

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << model << ";" << material << ";" << count << ";" << price << ";" << count_of_keys;
        return oss.str();
    }

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str) {
        std::istringstream iss(str);
        char delimiter = ';';
        std::getline(iss, model, ';');
        std::getline(iss, material, ';');
        iss >> count >> delimiter >> price >> delimiter >> count_of_keys;
    }

};


#endif // PIANO_H
