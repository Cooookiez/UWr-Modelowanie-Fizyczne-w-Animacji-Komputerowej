#include "Point.h"

Point::Point(int id, float x, float y, float size, float mass, bool isStatic = false) {
    this->id        = id;
    this->posNow    = {x, y};
    this->posOld    = {x, y};
    this->size      = size;
    this->mass      = mass;
    this->velocity  = {0, 0};
    this->forces    = {0, 0};
    this->isStatic  = isStatic;
}

void Point::updateForces(float g, float height) {
    forces.y = mass * g;
    forces.x = 0;
    if (posNow.y > height - size) {
        velocity.y = 0;
        posNow.y = height - size;
    }
}

void Point::updateWithVelocity(float deltaTime) {
    if (!isStatic) {
        posNew = 2 * posNow - posOld + (deltaTime * deltaTime * forces / mass);
        posOld = posNow;
        posNow = posNew;
    }
}

ofColor Point::getColor() {
    if (isStatic) {
        return {255, 0, 255};
    } else {
        return {100, 100, 100};
    }
}