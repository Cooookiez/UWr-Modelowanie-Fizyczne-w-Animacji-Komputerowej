#ifndef _DISC
#define _DISC
#include "ofMain.h"

class Disc {
private:
    double speed_start_max = 42;
    double speed_start_min = 7;
    double radius_max = 30;
    double radius_min = 10;
    double water_dynamic_viscosity = 0.89 / 500;
    double mass_min = 0.01;
    double mass_max = 0.10;

public:
    double deltaTime = 0;
    double mass;
    double radius;

    ofVec2f position;
    ofVec2f force;
    ofVec2f speed;

    ofColor color;

    Disc();
    void update(double g, double deltaTime);
    void draw();
    void water();
    void colisions();

};

#endif