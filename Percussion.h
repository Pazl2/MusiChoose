#ifndef PERCUSSION_H
#define PERCUSSION_H

#include "Instrument.h"

class Percussion : public Instrument {
protected:

public:
    Percussion(std::string model, int count, std::string material, double price) :
        Instrument(model, count, material, price) {

    }

    ~Percussion(){};
};



#endif // PERCUSSION_H
