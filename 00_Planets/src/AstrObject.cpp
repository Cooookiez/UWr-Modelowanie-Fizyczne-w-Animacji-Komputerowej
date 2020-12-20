#include "AstrObject.h"

AstrObject::AstrObject() {
    this->mass = 1000000000;
    this->radius = 64;
    this->color.set(255, 255, 0);
    this->position.set(0, 0, 0);
    this->speed.set(0, 0, 0);
}

//--------------------------------------------------------------
AstrObject::AstrObject(
    unsigned int mass,
    unsigned int radius,
    ofVec3f position,
    ofVec3f speed
) {
    this->mass = mass;
    this->radius = radius;
    this->position = position;
    this->speed = speed;
    this->color.set(ofRandom(255), ofRandom(255), ofRandom(255), 100);

    // double speedX = -this->position.x / this->position.length() * std::sqrt(this->G * AstrObject().mass / this->position.length());
    // double speedY = -this->position.y / this->position.length() * std::sqrt(this->G * AstrObject().mass / this->position.length());
    // double speedZ =  this->position.z / this->position.length() * std::sqrt(this->G * AstrObject().mass / this->position.length());
    // int speedCheat = 000;
    // this->speed.set(speedX*speedCheat, speedY*speedCheat, speedZ*speedCheat);
    // this->speed.set(30, 0, 0);

}

//--------------------------------------------------------------
void AstrObject::update(double deltaTime) {
    ofRotateY(ofGetElapsedTimef() * 10);
    this->position += this->speed * deltaTime;

    // AstrObject() is sun
    // double F1 = G * AstrObject().mass * this->mass / pow(( this->position - AstrObject().position ).length(), 2);
    // ofVec3f F2 = (AstrObject().position - this->position) / (this->position - AstrObject().position).length();
    // ofVec3f F  = deltaTime * F1 * F2;

    double distance = pow( (AstrObject().position - this->position).length(), 2);
    // m1 * m2 / d^2
    double force = this->G * (pow(AstrObject().mass, 2) * this->mass / distance);
    ofVec3f vFoce = force * (AstrObject().position - this->position);

    this->speed += vFoce / this->mass * deltaTime;
    // F / m
}

//--------------------------------------------------------------
void AstrObject::draw() {
    ofSetColor(this->color);
    ofEnableDepthTest();
    ofDrawSphere(this->position, this->radius);
}