#include "Particle.h"

Particle::Particle(ofVec2f position, ofVec2f v) {
    this->position = position;
    this->v = v;
    this->radius = 1;
    this->lifeSpan = ofRandom(1.5, 3.5);
    this->lifeLived = 0;
    this->color = {255, 255, 255};
}

void Particle::update(double dt) {
    this->position += v * dt;
    this->lifeLived += dt;

    double opacity = this->lifeSpan - (this->lifeLived / this->lifeSpan);
    opacity = opacity >= 0 ? opacity : 0;
    opacity *= 100;
    this->color = {255, 255, 255, opacity};
}

void Particle::draw() {
    ofSetColor(this->color);
    ofDrawCircle(this->position, this->radius);
}