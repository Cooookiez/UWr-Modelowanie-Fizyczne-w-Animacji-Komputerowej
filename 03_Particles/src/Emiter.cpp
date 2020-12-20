#include "Emiter.h"

Emiter::Emiter() {
    this->position = {0, 0};
    this->width = 50;
    this->height = 50;
}

Emiter::Emiter(double x, double y, double width, double height) {
    this->position = {x, y};
    this->width = width;
    this->height = height;
}

void Emiter::draw() {
    ofSetColor(80, 0, 0);
    ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}