#ifndef STRINGED_H
#define STRINGED_H

#include "Instrument.h"

class Stringed: public Instrument {
protected:
    int count_of_string;
public:
    Stringed(std::string model, int count, std::string material, int count_of_string, double price) :
        Instrument(model, count, material, price) {

        this->count_of_string = count_of_string;
    }

    int GetCOString() {
        return this->count_of_string;
    }

    void SetCOString(int count_of_string) {
        this->count_of_string = count_of_string;
    }

    ~Stringed(){};
};

#endif // STRINGED_H
