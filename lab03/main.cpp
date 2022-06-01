#include <iostream>
#include "lab3.h"

int main()
{
  Triangle triangle;
  triangle.set_point(0, 0, 0);
  triangle.set_point(1, 0, 3);
  triangle.set_point(2, 3, 0);
  triangle.print();

  Rectangle rectangle;
  rectangle.set_point(0, 0, 0);
  rectangle.set_point(1, 10, 0);
  rectangle.set_point(2, 10, 5);
  rectangle.set_point(3, 0, 5);
  rectangle.print();

  Circle circle;
  circle.set_center(0, 0);
  circle.set_radius(5);
  circle.print();

  Cube cube;
  cube.set_point(0, 0, 0, 0);
  cube.set_point(1, 0, 0, 5);
  cube.set_point(2, 5, 0, 5);
  cube.set_point(3, 5, 0, 0);
  cube.set_point(4, 5, 5, 0);
  cube.set_point(5, 0, 5, 0);
  cube.set_point(6, 0, 5, 5);
  cube.set_point(7, 5, 5, 5);
  cube.print();

  Cuboid cuboid;
  cuboid.set_point(0, 0, 0, 0);
  cuboid.set_point(1, 0, 0, 7);
  cuboid.set_point(2, 5, 0, 7);
  cuboid.set_point(3, 5, 0, 0);
  cuboid.set_point(4, 5, 10, 0);
  cuboid.set_point(5, 0, 10, 0);
  cuboid.set_point(6, 0, 10, 7);
  cuboid.set_point(7, 5, 10, 7);
  cuboid.print();

  Cylinder cylinder;
  cylinder.set_center(0, 0);
  cylinder.set_radius(5);
  cylinder.set_height(5);
  cylinder.print();

  Sphere sphere;
  sphere.set_center(0, 0, 0);
  sphere.set_radius(5);
  sphere.print();

  return 0;
}