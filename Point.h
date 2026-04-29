#pragma once
#include <string>
using namespace std;
class Point {
public:
    Point(int x = 0, int y = 0, int z = 0);
    virtual ~Point() = default;
    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int);
    void setY(int);
    void setZ(int);
    virtual string toString() const;
private:
    int x;
    int y;
    int z;
};

