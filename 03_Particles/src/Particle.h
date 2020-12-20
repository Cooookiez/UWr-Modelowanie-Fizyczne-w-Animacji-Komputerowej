#ifndef _PARTICLE
#define _PARTICLE
#include "ofMain.h"

class Particle {
public:
    double radius;
    double lifeSpan;

    ofVec2f position;
    ofVec2f force;
    ofVec2f v;
    
    ofColor color;
    Particle();
};

#endif