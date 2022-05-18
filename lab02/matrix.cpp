#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"
using namespace std;

matrix::matrix(unsigned w, unsigned h) :width(0), height(0)
{
  create_matrix(w, h);
  std::cout << "Constructor\n";
}

matrix::matrix(const matrix& other)
{
  this->width = other.width;
  this->height = other.height;
  values = new double* [height];
  for (int i = 0; i < height; i++)
  {
    values[i] = new double[width];
    for (int j = 0; j < width; j++)
      values[i][j] = other.values[i][j];
  }
  std::cout << "Copy constructor\n";
}

matrix::~matrix()
{
  std::cout << "Destructor\n";
  if (width != 0)
    for (int i = 0; i < height; i++)
      delete[] values[i];
  if (height != 0)
    delete[] values;
}

unsigned matrix::get_width() const
{
  return width;
}

unsigned matrix::get_height() const
{
  return height;
}

void matrix::set_width(unsigned w)
{
  create_matrix(w, height);
}

void matrix::set_height(unsigned h)
{
  create_matrix(width, h);
}

void matrix::set_value(unsigned i, unsigned j, double value)
{
  if (i >= height || j >= width)
    std::cout << "Warning! Element with coordinates (" << i << "," << j << ") doesn't exist\n";
  else
    values[i][j] = value;
}

void matrix::print()
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
      std::cout << values[i][j] << " ";
    std::cout << std::endl;
  }
}

matrix& matrix::operator = (const matrix& other)
{
  if (this == &other)
    return *this;
  this->width = other.width;
  this->height = other.height;
  values = new double* [height];
  for (int i = 0; i < height; i++)
  {
    values[i] = new double[width];
    for (int j = 0; j < width; j++)
      values[i][j] = other.values[i][j];
  }
  return *this;
}

matrix matrix::operator *(const matrix& other) const //перемножение матриц
{
  // кол-во столбцов первой матрицы должно быть равно кол-ву строк второй матрицы
  if (this->get_width() == other.get_height())
  {
    matrix result(other.get_width(), this->get_height());
    for (int i = 0; i < this->get_height(); i++)
    {
      for (int j = 0; j < other.get_width(); j++)
      {
        // вычисление ячейки новой матрицы
        double sum = 0;
        for (int k = 0; k < this->get_width(); k++)
          sum += values[i][k] * other.values[k][j];
        result.values[i][j] = sum;
      }
    }

    std::cout << "Called operator * between matrix and matrix\n";
    return result;
  }
  else
  {
    std::cout << "The number of columns of the first matrix is not equal to the number of rows of the second!" << endl;
    return *this;
  }
}

//matrix& matrix::operator *=(const matrix& other) //перемножение матриц
//{
//  *this = *this * other;
//  std::cout << "Called operator *= between matrix and matrix\n";
//  return *this;
//}

matrix matrix::operator *(double v) //поэлементное умножение на значение v
{
  matrix result(this->get_width(), this->get_height());
  for (int i = 0; i < result.get_height(); i++)
  {
    for (int j = 0; j < result.get_width(); j++)
      result.values[i][j] = this->values[i][j] * v;
  }

  std::cout << "Called operator * between matrix and double\n";
  return result;
}

matrix matrix::operator +(const matrix& other) //сложение матриц
{
  // матрицы должны быть одинаковых размеров
  if (this->get_height() == other.get_height() && this->get_width() == other.get_width()) {
    matrix result(other.get_width(), this->get_height());
    for (int i = 0; i < result.get_height(); i++)
    {
      for (int j = 0; j < result.get_width(); j++)
        result.values[i][j] = this->values[i][j] + other.values[i][j];
    }

    std::cout << "Called operator + between matrix and matrix\n";
    return result;
  }
  else
  {
    std::cout << "The matrices must be of the same size" << endl;
    return *this;
  }
}

matrix matrix::operator +(double v) //поэлементно прибавить значение v
{
  matrix result(this->get_width(), this->get_height());
  for (int i = 0; i < result.get_height(); i++) {
    for (int j = 0; j < result.get_width(); j++)
      result.values[i][j] = this->values[i][j] + v;
  }

  std::cout << "Called operator + between matrix and double \n";
  return result;
}

matrix matrix::transpose() //транспонировать и вернуть новую матрицу
{
  matrix result(this->get_height(), this->get_width());
  for (int i = 0; i < this->get_height(); i++) {
    for (int j = 0; j < this->get_width(); j++) {
      result.values[j][i] = this->values[i][j];
    }
  }

  std::cout << "Called transpose of matrix\n";
  return result;
}