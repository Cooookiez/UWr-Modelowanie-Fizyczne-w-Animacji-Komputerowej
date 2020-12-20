#include "LiveSys.h"

LiveSys::LiveSys() {
    this->width = 50;
    this->height = 50;
}

LiveSys::LiveSys(double width, double height) {
    this->width = width;
    this->height = height;
}

void LiveSys::update(double dt) {
    
}

void LiveSys::draw() {
    // Emiters
    for (unsigned i = 0; i < this->emiters.size(); i++) {
        this->emiters.at(i).draw();
    }
}

void LiveSys::addEmiter(double x, double y, double width, double height) {

    this->emiters.push_back(Emiter(x, y, width, height));

}