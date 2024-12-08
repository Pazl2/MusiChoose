#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <fstream>
#include <sstream>

class Instrument {
protected:

    std::string material;
    std::string model;
    int count;
    double price;

public:

    Instrument(std::string model, int count, std::string material, double price) {

        this->model = model;
        this->count = count;
        this->material = material;
        this->price = price;
    }

    std::string getModel() {
        return this->model;
    }

    void setModel(std::string model) {
        this->model = model;
    }

    std::string getMaterial() {
        return this->material;
    }

    void setMaterial(std::string material) {
        this->material = material;
    }

    int getCount() {
        return this->count;
    }

    void setCount(int count) {
        this->count = count;
    }

    double getPrice() {
        return this->price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    virtual std::string toString(){};

    // Виртуальный метод для загрузки объекта из строки
    virtual void fromString(const std::string& str){};


    virtual ~Instrument(){};

};

// void getInstrument (std::vector<Instrument*> inst){
//     inst;
// }


#endif // INSTRUMENT_H
