#ifndef COORD2D_H
#define COORD2D_H

#include <iostream>
using namespace std;

//implement a class that keeps track of the coordinates of a point in the X-Y plane
class coord2d {
	//overload the << operator so that if p is of type "coord2d" then  "cout<<p";
	//will print out (x_coord, y_coord)
	friend ostream& operator<<(ostream&, const coord2d&);

	//overload the > operator as a friend function so that if  p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	friend bool operator>(const coord2d&, const coord2d&);

	//overload the < operator as a friend function so that if  p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	//p1, p2 should not change
	friend bool operator<(const coord2d&, const coord2d&);

	//overload the * operator so that if p1 and p2 are of type "coord2d" and k is a double
	//then p1=k*p2 will result in the coordinates of p1 be set to those of p2 multiplied by k
	//p2 should not change
	friend coord2d operator*(double, const coord2d&);

	//overload the + operator so that if p1 and p2 are of type "coord2d" and x is a double
	//then p1=x+p2 will result in the coordinates of p1 be set to adding x to those of p2 
	//p2 should not change
	friend coord2d operator+(double, const coord2d&);


public:
	coord2d(double a = 0, double b = 0) {
		x_coord = a, y_coord = b;
	}
	//default constructor: initializes coordinates x_coord and y_coord to a and b respectively.  

	void set(double a, double b) {
		x_coord = a, y_coord = b;
	}
	//sets the coordinates to (a,b)


	//overload the + operator as a member function so that if p1 and p2 and p3 are of type "coord2d" 
	//then p1=p2+p3 will result in the coordinates of p1 be set to adding coordinates of p3 to those of p2 
	//p2, p3 should not change
	coord2d operator+(const coord2d&) const;

	//overload the * operator as a member function so that if p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	//then p1*p2  will return a*c+b*d
	//p1, p2 should not change
	double operator*(const coord2d&) const;

	//overload [] operator so if p is of type "coord2d", then 
	//p[k] will return p_xcoord if k=0, p[k] will return p.y_coord if k=1 
	//and p[k] will display an error message and exit the program for other k's 
	double& operator[](int);

private:
	double x_coord;  //x coordinate
	double y_coord; //y coordinate
};

ostream& operator<<(ostream& out, const coord2d& C) {
	// Returns cout << (a, b)
	out << "(" << C.x_coord << ", " << C.y_coord << ")";
	return out;
}

bool operator>(const coord2d& c1, const coord2d& c2) {

	// For c1(a, b) c2(c, d), returns true if (a > c) and (b > d)
	if (c1.x_coord > c2.x_coord && c1.y_coord > c2.y_coord)
		return true;

	return false;
}

bool operator<(const coord2d& c1, const coord2d& c2) {

	// For c1(a, b) c2(c, d), returns true if (a < c) and (b < d)
	if (c1.x_coord < c2.x_coord && c1.y_coord < c2.y_coord)
		return true;

	return false;
}

coord2d operator*(double d, const coord2d& C) {

	// Returns (x*d, y*d)
	coord2d c1(C.x_coord * d, C.y_coord * d);

	return c1;
}

coord2d operator+(double d, const coord2d& C) {

	// Returns (x+d, y+d)
	coord2d c1(C.x_coord + d, C.y_coord + d);

	return c1;
}

coord2d coord2d::operator+(const coord2d& C) const {

	// For "a, b" being the var before the "+"
	// and "x, y" being the var after the "+"
	// Returns (a+x, b+y)
	coord2d c1(this->x_coord + C.x_coord, this->y_coord + C.y_coord);

	return c1;
}

double coord2d::operator*(const coord2d& C) const {

	// For "a, b" being the var before the "+"
	// and "x, y" being the var after the "+"
	// Returns (a*x, b*y)
	double result = (this->x_coord * C.x_coord) + (this->y_coord * C.y_coord);

	return result;
}

double& coord2d::operator[](int k) {

	// If k = 0, returns x coord
	// If k = 1, returns y coord
	// Else = Error
	if (k == 0)
		return this->x_coord;
	else if (k == 1)
		return this->y_coord;
	else {
		cout << "Error" << endl;
		exit(0);
	}
}

#endif
