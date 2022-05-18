#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>

class matrix {
public:
  matrix(unsigned w = 0, unsigned h = 0);
  matrix(const matrix& other);
  ~matrix();
  unsigned get_width() const;
  unsigned get_height() const;
  void set_width(unsigned w);
  void set_height(unsigned h);
  void set_value(unsigned i, unsigned j, double value);
  void print();
  matrix& operator = (const matrix& other);
  matrix operator *(const matrix& other) const; //перемножение матриц
  matrix& operator *=(const matrix& other); //перемножение матриц
  matrix operator *(double v); //поэлементное умножение на значение v
  matrix operator +(const matrix& other); //сложение матриц
  matrix operator +(double v); //поэлементно прибавить значение v
  matrix transpose(); //транспонировать и вернуть новую матрицу

private:
  double** values;
  unsigned width;
  unsigned height;
  void create_matrix(unsigned w, unsigned h)
  {
    if (width != 0 && height != 0)
    {
      for (int i = 0; i < height; i++)
        delete[] values[i];
      delete[] values;
    }
    this->width = w;
    this->height = h;
    if (w != 0 && h != 0)
    {
      values = new double* [height];
      for (int i = 0; i < height; i++) {
        values[i] = new double[width];
        for (int j = 0; j < width; j++)
          values[i][j] = 1;
      }
    }
  }
};


#endif //MATRIX_MATRIX_H
