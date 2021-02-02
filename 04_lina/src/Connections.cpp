#include "Connections.h"

Connection::Connection(int index1, int index2, std::vector<Point*>& points) {
    this->index1 = index1;
    this->index2 = index2;
    length = points[index1]->posNow.distance(points[index2]->posNow);
}

void Connection::update(float k, std::vector<Point*>& points) {
    Point* point1 = points[index1];
    Point* point2 = points[index2];
    float distance = point1->posNow.distance(point2->posNow);

    if (distance) {
        // velocity
        point1->velocity = point1->posNow - point1->posOld;
        point2->velocity = point2->posNow - point2->posOld;
        
		ofVec2f velocityDifrence = point1->velocity - point2->velocity;
		ofVec2f posDifrence = point1->posNow - point2->posNow;

        // Forces
        ofVec2f f = ((distance - length) * k) + (velocityDifrence * posDifrence);
        f *= (posDifrence / distance);
        point1->forces -= f;
        point2->forces += f;
    }
}