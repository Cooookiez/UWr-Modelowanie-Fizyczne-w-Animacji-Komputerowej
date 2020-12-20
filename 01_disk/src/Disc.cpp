#include "Disc.h"
#include <cstdlib>

Disc::Disc() {
    this->color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    this->radius = ofRandom(this->radius_min, this->radius_max);
    this->mass = ofRandom(this->mass_min, this->mass_max) * this->radius;
    
    double speedX = ofRandom(this->speed_start_min, this->speed_start_max);
    double speedY = ofRandom(this->speed_start_min, this->speed_start_max) / ofRandom(2,20);
    //zmiana kierunku albo nie
    speedX *= ofRandom(0,1) > .5 ? 1:-1;
    speedY *= ofRandom(0,1) > .5 ? 1:-1;
    this->speed = {speedX, speedY};
    
    double minX = this->radius;
    double minY = this->radius;
    double maxX = ofGetWindowWidth() - this->radius;
    double maxY = (ofGetWindowHeight()/4) - this->radius;
    this->position = {
        ofRandom(minX, maxX),
        ofRandom(minY, maxY)
    };
}

//--------------------------------------------------------------
void Disc::update(double g, double deltaTime) {
    this->colisions();

    this->deltaTime = deltaTime;
    this->position += this->speed * this->deltaTime;
    this->force.y += g * this->mass;
    // jest zlie, powinno byc
    // g * masa
    this->water();
    this->speed += this->force / this->mass * deltaTime;
    // sila / masa * td

    this->force = {0.0, 0.0};
}

//--------------------------------------------------------------
void Disc::draw() {
    ofSetColor(this->color);
    ofDrawCircle(this->position, this->radius);
}

//--------------------------------------------------------------
void Disc::water() {
    if (this->position.y >= ofGetWindowHeight()/2 - this->radius)
    {
    
        // F = -6 * LEPKOSC * PROMIEN * PREDKOSC
        double forceTmp = -6 * M_PI * this->water_dynamic_viscosity * this->radius;
        this->force.x = forceTmp * this->speed.x;
        this->force.y = forceTmp * this->speed.y;
    }
}

//--------------------------------------------------------------
void Disc::colisions() {
    // Between walls
    // right wall
    if (this->position.x >= ofGetWindowWidth() - this->radius)
    {
        this->position.x = ofGetWindowWidth() - this->radius;
        this->speed.x *= -1;
    }
    // left wall
    else if (this->position.x <= this->radius)
    {
        this->position.x = this->radius;
        this->speed.x *= -1;
    }
    // roof
    else if (this->position.y <= this->radius)
    {
        this->position.y = this->radius;
        this->speed.y *= -1;
    }
    // floor
    else if (this->position.y >= ofGetWindowHeight() - this->radius)
    {
        this->position.y = ofGetWindowHeight() - this->radius;
        this->speed.y *= -1;
    }

}