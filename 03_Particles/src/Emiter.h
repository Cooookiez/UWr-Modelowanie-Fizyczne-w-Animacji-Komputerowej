#ifndef _EMITER
#define _EMITER
#include "ofMain.h"
#include "Particle.h"

class Emiter {
public:
    const double V_START_MIN = 80;
    const double V_START_MAX = 100;
    const double DIRECTION_MAX_DEGREE = 60;
    const double DEVATION_MAX_DEGREE = 15;

    int particlesPerSecond = 420;

    ofVec2f position;
    double width;
    double height;
    double direction_degree;

    Emiter();
    Emiter(double x, double y, double width, double height);
    void update(double dt);
    void draw();
    Particle addParticle();
    
};

#endif