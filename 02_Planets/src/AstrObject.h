#ifndef ASTROBJECT
#define ASTROBJECT

#include "ofMain.h"

class AstrObject {
private:
    double G = 7e-5;

public:
    unsigned int mass;
    unsigned int radius;
    double speed_min = 75;
    double speed_max = 100;

    ofVec3f position;
    ofVec3f speed;

    ofColor color;

    AstrObject();   // for sun
    AstrObject(     // for evythin else
        unsigned int mass,
        unsigned int radius,
        ofVec3f position,
        ofVec3f speed
    );
    void update(double deltaTime);
    void draw();

};

#endif