#ifndef _ROPE
#define _ROPE

#include <ofMain.h>
#include <ofVec2f.h>

class Point {
public:
    ofVec2f posNow;
    ofVec2f posOld;
    ofVec2f posNew;

    ofVec2f velocity;
    ofVec2f forces;

    ofColor springColor; 

    int id;
    float size;
    float mass;
    bool isStatic;

    Point(int id, float x, float y, float size, float mass, bool isStatic);
    void updateForces(float g, float height);
    void updateWithVelocity(float deltaTime);
    ofColor getColor();

};

#endif