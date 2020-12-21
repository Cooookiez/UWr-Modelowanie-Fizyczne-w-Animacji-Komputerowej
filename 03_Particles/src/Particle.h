#ifndef _PARTICLE
#define _PARTICLE
#include "ofMain.h"

class Particle {
public:
    double radius;
    double lifeSpan;
    double lifeLived;

    ofVec2f position;
    ofVec2f v;
    ofColor color;
    
    Particle(ofVec2f position, ofVec2f v);
    void update(double dt);
    void draw();
};

#endif