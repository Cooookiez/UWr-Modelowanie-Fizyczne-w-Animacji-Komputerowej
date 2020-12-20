#ifndef _EMITER
#define _EMITER
#include "ofMain.h"
#include "Particle.h"

class Emiter {
public:

    ofVec2f position;
    double width, height;

    Emiter();
    Emiter(double x, double y, double width, double height);
    void update(double dt);
    void draw();
    void addParticle(int x, int y, ofVec2f v);
    

};

#endif