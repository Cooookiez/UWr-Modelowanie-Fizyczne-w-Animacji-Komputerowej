#ifndef _LINE
#define _LINE

#include <vector>
#include "Point.h"

class Connection {
public:
    int index1;
    int index2;
    float length;

    Connection(int i, int j, std::vector<Point*>& points);
    void update(float k, std::vector<Point*>& points);
};

#endif