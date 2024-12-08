#ifndef WIND_H
#define WIND_H

#include "Instrument.h"

class Wind : public Instrument {
protected:
public:
    Wind(std::string model, int count, std::string material, double price) :
        Instrument(model, count, material, price) {

    }

    ~Wind(){};
};

#endif // WIND_H
