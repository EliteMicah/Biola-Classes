#ifndef COORD_H
#define COORD_H
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class coord {
public:

    coord(double a = 0, double b = 0);
    //default constructor: initializes coordinates x_coord and y_coord to a and b respectively.

    void set(double a, double b);
    //sets the coordinates to (a,b)

    void display() const;
    //prints the coordinates in the following format
    // (x_coord, y_coord)

    void scale(double k);
    //scales each coordinate by k (i.e. each coordinate is multiplied by k)
    //e.g. if point has coordinates (10, -5) and k=10, then the new coordinate is (100,-50)

    double distance() const;
    //returns the Euclidian distance of the point from the origin
    //if coordinates of the point are (x,y) then the distance from the origin is given by
    // d=sqrt(x^2+y^2) where sqrt is the square root function

    double distance(coord p) const;
    //returns the Euclidian distance of the point p
    //if coordinates are (x,y), and the coordinates of p are (a,b) then the distance from p is given by
    // d=sqrt((x-a)^2+(y-b)^2) where sqrt is the square root function

private:
    double x_coord = 0;
    double y_coord = 0;
};







coord::coord(double a, double b) {

    x_coord = a;
    y_coord = b; // Initialization

}

void coord::set(double a, double b) {

    x_coord = a;
    y_coord = b;

    //sets a to x_coord and b to y_coord
}

void coord::display() const {

    cout << "(" << x_coord << ", " << y_coord << ")" << endl;
    //Prints "(x, y)"
}

void coord::scale(double k) {

    if (k > 0) {
        x_coord *= k;
        y_coord *= k;
    }
    else
        cout << "Invalid k" << endl;
    //If k is not 0 or less than 0, will scale
}

double coord::distance() const {

    double d = 0;

    d = sqrt(pow(x_coord, 2) + pow(y_coord, 2)); // returns square root of x*x + y*y
    cout << d << endl;

    return d;
}

double coord::distance(coord p) const {

    double d = 0;

    d = sqrt(pow((x_coord - p.x_coord), 2) + pow((y_coord - p.y_coord), 2));
    cout << d << endl; // Returns the square root of (x*a)^2 + (y*b)^2

    return d;
}


#endif
