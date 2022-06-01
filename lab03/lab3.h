#include <iostream>
#include <cmath>

class Point
{
public:
  Point(int _x, int _y);
  virtual ~Point();
  virtual void set_x(int _x) = 0;
  virtual void set_y(int _y) = 0;
  virtual int get_x() = 0;
  virtual int get_y() = 0;
  virtual void print() = 0;

protected:
  int x;
  int y;
};

class Point2D : public Point
{
public:
  Point2D(int _x = 0, int _y = 0);
  ~Point2D() override;
  void set_x(int _x) override;
  void set_y(int _y) override;
  int get_x() override;
  int get_y() override;
  void print() override;
};

class Point3D : public Point2D
{
public:
  Point3D(int _x = 0, int _y = 0, int _z = 0);
  ~Point3D() override;
  void set_z(int _z);
  int get_z();
  void print() override;
private:
  int z;
};

class Figure
{
public:
  Figure();
  virtual void print() = 0;
  virtual double square() = 0;
  virtual double volume() = 0;
  virtual double perimeter() = 0;
protected:
  Point** points;
  Point3D** points3D;
};

class Triangle : public Figure
{
public:
  Triangle();
  void set_point(int id, int x, int y);
  double perimeter();
  double volume() override;
  void print();
  double square();
  ~Triangle();
private:
};

class Rectangle : public Figure
{
public:
  Rectangle();
  void set_point(int id, int x, int y);
  double perimeter();
  double volume() override;
  void print();
  double square();
  ~Rectangle();
private:
};

class Circle : public Figure
{
public:
  Circle();
  void set_center(int x, int y);
  void set_radius(double r);
  void print();
  double square();
  double volume();
  double perimeter();
  ~Circle();
private:
  Point2D center;
  double radius;
};

class Cube : public Figure
{
public:
  Cube();
  void set_point(int id, int x, int y, int z);
  double square();
  double volume() override;
  double perimeter();
  void print();
  ~Cube();
private:
};

class Cuboid : public Figure
{
public:
  Cuboid();
  void set_point(int id, int x, int y, int z);
  double square();
  double volume() override;
  double perimeter();
  void print();
  ~Cuboid();
private:
};

class Cylinder : public Figure
{
public:
  Cylinder();
  void set_center(int x, int y);
  void set_radius(double r);
  void set_height(double h);
  void print();
  double square();
  double volume();
  double perimeter();
  ~Cylinder();
private:
  Point2D center;
  double radius;
  double height;
};

class Sphere : public Figure
{
public:
  Sphere();
  void set_center(int x, int y, int z);
  void set_radius(double r);
  void print();
  double square();
  double volume();
  double perimeter();
  ~Sphere();
private:
  Point3D center;
  double radius;
};