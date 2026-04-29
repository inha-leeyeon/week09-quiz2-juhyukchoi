#pragma once
#include "Point.h"
#include <string>
using namespace std;

class Bubble : public Point {
public:
    Bubble(int x, int y, int z, int r = 0);
    virtual ~Bubble() = default;
    int getRadius() const;
    void setRadius(int);
    double getVolume() const;
    void setVolume(int);
    virtual string toString() const;
private:
    int radius;
    double volume;
};


