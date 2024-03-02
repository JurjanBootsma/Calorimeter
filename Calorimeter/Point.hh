// Exercise 10: Point class
// Author: Jurjan Bootsma

#ifndef POINT_HH
#define POINT_HH

class Point {
public:

  Point(double x=0, double y=0, double z=0) : _x(x), _y(y), _z(z) {} // Constructor

  // Accessors
  double x() const { return _x ; }
  double y() const { return _y ; }
  double z() const { return _z ; }
  
  // Modifiers
  void setX(double x) { _x = x ; }
  void setY(double y) { _y = y ; }
  void setZ(double z) { _z = z ; }

  // Modify all coordinates at once
  void set(double x, double y, double z) { _x = x ; _y = y ; _z = z ; }

private:

  double _x, _y, _z ;

} ;

#endif 