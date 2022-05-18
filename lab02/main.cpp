#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"
using namespace std;

bool read_matrix(matrix& m, char* filename)
{
  std::cout << filename << '\n';
  std::ifstream in;
  in.open(filename, std::ios::in);
  if (in.good())
  {
    int width, height;
    in >> height >> width;
    m.set_width(width);
    m.set_height(height);
    double value;
    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
      {
        in >> value;
        m.set_value(i, j, value);
      }
  }
  else
  {
    in.close();
    std::cout << "Error! Cannot open file " << filename << "\n";
    return false;
  }
  in.close();
  return true;
}

int main(int argc, char* argv[])
{
  matrix* matrices = new matrix[argc - 1];
  for (int i = 1; i < argc; i++)
  {
    read_matrix(matrices[i - 1], argv[i]);
    matrices[i - 1].print();
  }
  cout << "init matrix" << endl;
  matrices->print();

  matrix matrix1 = matrices[0];
  matrix matrix2 = matrices[1];
  matrix matrix3 = matrices[2];
  //cout << matrixx.get_width() << endl;
  //cout << matrices[2] << endl;
  matrix1.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  matrix matrix4;
  matrix4 = matrix1 * matrix2;
  matrix4.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  matrix matrix5;
  matrix5 = matrix1 * 3;
  matrix5.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  matrix matrix6;
  matrix6 = matrix1 + matrix3;
  matrix6.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  matrix matrix7;
  matrix7 = matrix1 + 3;
  matrix7.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  matrix matrix8;
  matrix8 = matrix3.transpose();
  matrix8.print();
  cout << "_ _ _ _ _ _ _ _" << endl;

  delete[] matrices;

  return 0;
}