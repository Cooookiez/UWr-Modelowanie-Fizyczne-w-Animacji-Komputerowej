#ifndef _LIVESYS
#define _LIVESYS
#include "ofMain.h"
#include "Emiter.h"
#include "Particle.h"
#include <cstdlib>

class LiveSys {
public:

    double width, height;

    std::vector<Emiter> emiters;
    std::vector<Particle> particles;

    LiveSys();
    LiveSys(double width, double height);
    void update(double dt);
    void draw();
    void addEmiter(double x, double y, double width, double height);
    // void removeEmiter(int key);
    
};

#endif