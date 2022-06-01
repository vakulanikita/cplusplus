#include <iostream>
#include <cmath>
#include"lab3.h"
# define M_PI           3.14159265358979323846  /* pi */

Point::Point(int _x, int _y) :x(_x), y(_y) { std::cout << "Point constructor\n"; }
Point::~Point() { std::cout << "Point destructor\n"; }

Point2D::Point2D(int _x, int _y) :Point(_x, _y) { std::cout << "Point2D constructor\n"; }
Point2D::~Point2D() { std::cout << "Point2D destructor\n"; }
void Point2D::set_x(int _x) { x = _x; }
void Point2D::set_y(int _y) { y = _y; }
int Point2D::get_x() { return x; }
int Point2D::get_y() { return y; }
void Point2D::print() { std::cout << "X=" << x << " Y=" << y << std::endl; }

Point3D::Point3D(int _x, int _y, int _z) :Point2D(_x, _y), z(_z) { std::cout << "Point3D constructor\n"; }
Point3D::~Point3D() { std::cout << "Point3D destructor\n"; }
void Point3D::set_z(int _z) { z = _z; }
int Point3D::get_z() { return z; }
void Point3D::print() { std::cout << "X=" << x << " Y=" << y << " Z=" << z << std::endl; }

Figure::Figure() { std::cout << "Figure constructor\n"; }

double distance2D(Point* a, Point* b)
{
  return sqrt(pow(a->get_x() - b->get_x(), 2) + pow(a->get_y() - b->get_y(), 2));
}

double distance3D(Point3D* a, Point3D* b)
{
  return sqrt(pow(b->get_x() - a->get_x(), 2) + pow(b->get_y() - a->get_y(), 2) + pow(b->get_z() - a->get_z(), 2));
}

Triangle::Triangle() { points = new Point * [3]; }
void Triangle::set_point(int id, int x, int y)
{
  if (id < 0 || id > 2)
    return;
  points[id] = new Point2D(x, y);
}
double Triangle::perimeter()
{
  return distance2D(points[0], points[1]) + distance2D(points[1], points[2]) + distance2D(points[2], points[0]);
}
double Triangle::volume() { std::cout << "Volume is not supported for triangles\n"; return 0; }
void Triangle::print()
{
  std::cout << "Triangle" << std::endl;
  for (int i = 0; i < 3; i++)
  {
    std::cout << "Point " << i + 1 << ": ";
    points[i]->print();
  }
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl;
}
double Triangle::square()
{
  double p = perimeter() / 2;
  double a = p - distance2D(points[0], points[1]);
  double b = p - distance2D(points[1], points[2]);
  double c = p - distance2D(points[2], points[0]);
  double S = sqrt(p * a * b * c);
  return S;
}
Triangle::~Triangle()
{
  for (int i = 0; i < 3; i++)
    delete points[i];
  delete[] points;
}


Rectangle::Rectangle() { points = new Point * [4]; }
void Rectangle::set_point(int id, int x, int y)
{
  if (id < 0 || id > 3)
    return;
  points[id] = new Point2D(x, y);
}
void Rectangle::print()
{
  std::cout << "Rectangle" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    std::cout << "Point " << i + 1 << ": ";
    points[i]->print();
  }
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl;
}
double Rectangle::perimeter() { return distance2D(points[0], points[1]) * 2 + distance2D(points[1], points[2]) * 2; }
double Rectangle::volume() { std::cout << "Volume is not supported for rectangles\n"; return 0; }
double Rectangle::square() { return distance2D(points[0], points[1]) * distance2D(points[1], points[2]); }
Rectangle::~Rectangle()
{
  for (int i = 0; i < 4; i++)
    delete points[i];
  delete[] points;
}


Circle::Circle() { std::cout << "Circle constructor\n"; }
void Circle::set_center(int x, int y) { center = Point2D(x, y); }
void Circle::set_radius(double r) { radius = r; }
void Circle::print()
{
  std::cout << "Circle" << std::endl;
  std::cout << "Radius: " << radius << std::endl << "Center: ";
  center.print();
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl;
}
double Circle::square() { return M_PI * pow(radius, 2); }
double Circle::volume() { std::cout << "Volume is not supported for circles\n"; return 0; }
double Circle::perimeter() { return 2 * M_PI * radius; }
Circle::~Circle() { std::cout << "Circle destructor\n"; }


Cube::Cube() { points3D = new Point3D * [8]; }
void Cube::set_point(int id, int x, int y, int z)
{
  if (id < 0 || id > 7)
    return;
  points3D[id] = new Point3D(x, y, z);
}
void Cube::print()
{
  std::cout << "Cube" << std::endl;
  for (int i = 0; i < 8; i++) {
    std::cout << "Point " << i + 1 << ": ";
    points3D[i]->print();
  }
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl << "Volume: " << volume() << std::endl;
}
double Cube::perimeter() { return distance3D(points3D[0], points3D[1]) * 12; }
double Cube::volume() { return pow(distance3D(points3D[0], points3D[1]), 3); }
double Cube::square() { return pow(distance3D(points3D[0], points3D[1]), 2) * 6; }
Cube::~Cube()
{
  for (int i = 0; i < 8; i++)
    delete points3D[i];
  delete[] points3D;
}


Cuboid::Cuboid() { points3D = new Point3D * [8]; }
void Cuboid::set_point(int id, int x, int y, int z)
{
  if (id < 0 || id > 7)
    return;
  points3D[id] = new Point3D(x, y, z);
}
void Cuboid::print()
{
  std::cout << "Cuboid" << std::endl;
  for (int i = 0; i < 8; i++) {
    std::cout << "Point " << i + 1 << ": ";
    points3D[i]->print();
  }
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl << "Volume: " << volume() << std::endl;
}
double Cuboid::perimeter() { return distance3D(points3D[0], points3D[1]) * 4 + distance3D(points3D[1], points3D[2]) * 4 + distance3D(points3D[4], points3D[5]) * 4; }
double Cuboid::volume() { return distance3D(points3D[1], points3D[2]) * distance3D(points3D[3], points3D[4]) * distance3D(points3D[0], points3D[1]); }
double Cuboid::square() { return distance3D(points3D[0], points3D[1]) * distance3D(points3D[1], points3D[2]) * 2 + distance3D(points3D[0], points3D[1]) * distance3D(points3D[3], points3D[4]) * 2 + distance3D(points3D[1], points3D[2]) * distance3D(points3D[3], points3D[4]) * 2; }
Cuboid::~Cuboid()
{
  for (int i = 0; i < 8; i++)
    delete points3D[i];
  delete[] points3D;
}


Cylinder::Cylinder() { std::cout << "Cylinder constructor\n"; }
void Cylinder::set_center(int x, int y) { center = Point2D(x, y); }
void Cylinder::set_radius(double r) { radius = r; }
void Cylinder::set_height(double h) { height = h; }
void Cylinder::print()
{
  std::cout << "Cylinder" << std::endl;
  std::cout << "Radius: " << radius << " Height: " << height << std::endl << "Center: ";
  center.print();
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl << "Volume: " << volume() << std::endl;
}
double Cylinder::square() { return 2 * M_PI * radius * (radius + height); }
double Cylinder::volume() { return M_PI * pow(radius, 2) * height; }
double Cylinder::perimeter() { return 4 * radius + 2 * height; }
Cylinder::~Cylinder() { std::cout << "Cylinder destructor\n"; }


Sphere::Sphere() { std::cout << "Sphere constructor\n"; }
void Sphere::set_center(int x, int y, int z) { center = Point3D(x, y, z); }
void Sphere::set_radius(double r) { radius = r; }
void Sphere::print()
{
  std::cout << "Sphere" << std::endl;
  std::cout << "Radius: " << radius << " Center: ";
  center.print();
  std::cout << "Perimeter: " << perimeter() << std::endl << "Square: " << square() << std::endl << "Volume: " << volume() << std::endl;
}
double Sphere::square() { return 4 * M_PI * pow(radius, 2); }
double Sphere::volume() { return M_PI * pow(radius, 3) * 4 / 3; }
double Sphere::perimeter() { return 2 * M_PI * radius; }
Sphere::~Sphere() { std::cout << "Sphere destructor\n"; }