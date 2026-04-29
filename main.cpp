#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point.h"
#include "Bubble.h"

using namespace std;

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::getZ() const {
    return z;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setZ(int z) {
    this->z = z;
}

string Point::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}

Bubble::Bubble(int x, int y, int z, int r) : Point(x, y, z), radius(r) {
    volume = (4.0 / 3.0) * 3.14 * r * r * r;
}

int Bubble::getRadius() const { 
    return radius; 
}

void Bubble::setRadius(int r) {
    radius = r;
    volume = (4.0 / 3.0) * 3.14 * r * r * r;
}

double Bubble::getVolume() const { 
    return volume; 
}

void Bubble::setVolume(int r) {
    volume = (4.0 / 3.0) * 3.14 * r * r * r;
}

string Bubble::toString() const {
    return "bubble " + Point::toString() + " R=" + to_string(radius);
}

int main() {
    int n;
    cin >> n;

    Bubble** bubbles = new Bubble * [n * 2];

    for (int i = 0; i < n; i++) {
        int x1, y1, z1, r1;
        int x2, y2, z2, r2;

        cin >> x1;
        cin >> y1;
        cin >> z1;
        cin >> r1;

        cin >> x2;
        cin >> y2;
        cin >> z2;
        cin >> r2;

        bubbles[i * 2] = new Bubble(x1, y1, z1, r1);
        bubbles[i * 2 + 1] = new Bubble(x2, y2, z2, r2);

        Bubble* b1 = bubbles[i * 2];
        Bubble* b2 = bubbles[i * 2 + 1];

        int b1x = b1->getX();
        int b1y = b1->getY();
        int b1z = b1->getZ();
        int b2x = b2->getX();
        int b2y = b2->getY();
        int b2z = b2->getZ();

        double dx = (double)(b2x - b1x);
        double dy = (double)(b2y - b1y);
        double dz = (double)(b2z - b1z);

        double dx2 = dx * dx;
        double dy2 = dy * dy;
        double dz2 = dz * dz;

        double dist = sqrt(dx2 + dy2 + dz2);

        int r1val = b1->getRadius();
        int r2val = b2->getRadius();

        double sumR = (double)(r1val + r2val);
        double diffA = (double)(r1val - r2val);
        double diffB = (double)(r2val - r1val);

        string b1str = b1->toString();
        string b2str = b2->toString();

        if (dist > sumR) {
            cout << b1str << " and " << b2str << " are disjoint" << endl;
        }
        else if (dist <= diffA) {
            cout << b1str << " includes " << b2str << endl;
        }
        else if (dist <= diffB) {
            cout << b1str << " is included in " << b2str << endl;
        }
        else {
            cout << b1str << " and " << b2str << " partially overlap" << endl;
        }

        double v1 = b1->getVolume();
        double v2 = b2->getVolume();

        cout << fixed << setprecision(2);

        if (v1 > v2) {
            cout << "bubble with the larger volume: " << b1str << ", V=" << v1 << endl;
        }
        else if (v2 > v1) {
            cout << "bubble with the larger volume: " << b2str << ", V=" << v2 << endl;
        }
        else {
            cout << b1str << " and " << b2str << " have the same volume, V=" << v1 << endl;
        }
    }

    for (int i = 0; i < n * 2; i++) {
        delete bubbles[i];
    }
    delete[] bubbles;

    return 0;
}