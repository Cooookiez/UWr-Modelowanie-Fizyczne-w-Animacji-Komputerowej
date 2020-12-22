#include "Emiter.h"
#include <math.h>

Emiter::Emiter() {
    this->position = {0, 0};
    this->width = 50;
    this->height = 50;
    this->direction_degree = 90 + ofRandom(-this->DIRECTION_MAX_DEGREE, this->DIRECTION_MAX_DEGREE);
}

Emiter::Emiter(double x, double y, double width, double height) {
    this->position = {x, y};
    this->width = width;
    this->height = height;
    this->direction_degree = 90 + ofRandom(-this->DIRECTION_MAX_DEGREE, this->DIRECTION_MAX_DEGREE);

}

void Emiter::update(double dt) {

}

void Emiter::draw() {
    // clouds
    double r = 55;
    double x, y;
    ofSetColor(255, 255, 255, 80);
    ofSetCircleResolution(64);
    // bottom layer
    y = this->position.y + this->height/2;
    // 1st
    x = this->position.x + this->width/6*1;
    ofDrawCircle(x, y, r);
    // 2nd
    x = this->position.x + this->width/6*3;
    ofDrawCircle(x, y, r*1.2);
    // 3th
    x = this->position.x + this->width/6*5;
    ofDrawCircle(x, y, r*.8);
    // top layer
    y = this->position.y - this->height/2;
    // 1st
    x = this->position.x + this->width/6*2;
    ofDrawCircle(x, y, r*1.2);
    // 2nd
    x = this->position.x + this->width/6*4;
    ofDrawCircle(x, y, r);

}

Particle Emiter::addParticle() {

    // random position
    double x = ofRandom(0, this->width) + this->position.x;
    double y = ofRandom(0, this->height) + this->position.y;
    double tmpDirection = ofRandom(-this->DEVATION_MAX_DEGREE, this->DEVATION_MAX_DEGREE) + this->direction_degree;
    // random v going down +-5 degreees od main v
    double tmpV = ofRandom(this->V_START_MIN, this->V_START_MAX);
    double vx = cos(tmpDirection * M_PI / 180) * tmpV;
    double vy = sin(tmpDirection * M_PI / 180) * tmpV;

    return Particle({x, y}, {vx, vy});
}