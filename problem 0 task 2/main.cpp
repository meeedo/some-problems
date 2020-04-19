#include <iostream>

using namespace std;

struct matrix
{
    int** data;
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat);

matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);


int main()
{
    matrix mat1 , mat2;
    int num[9]={1,2,3,2,1,6,3,6,1};
    int num2[9]={1,2,3,4,5,6,7,8,9};
    createMatrix(3,3,num,mat1);
    createMatrix(3,3,num2,mat2);

    return 0;
}

matrix operator+= (matrix& mat1, matrix mat3)
{
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat1.data[i][j]+=mat3.data[i][j];
        }
    }
    return mat1;
}
matrix operator-= (matrix& mat1, matrix mat2)
{
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat1.data[i][j]-=mat2.data[i][j];
        }
    }
    return mat1;
}
matrix operator+= (matrix& mat, int scalar)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            if(i==j)
                mat.data[i][j]+=scalar;
        }
    }
    return mat;
}
matrix operator-= (matrix& mat, int scalar)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            if(i==j)
                mat.data[i][j]-=scalar;
        }
    }
    return mat;
}
void operator++ (matrix& mat)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]++;
        }
    }
}
void operator-- (matrix& mat)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]--;
        }
    }
}
istream& operator>> (istream& in, matrix& mat)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            in>>mat.data[i][j];
        }
    }
    return in;
}
void createMatrix (int row, int col, int num[], matrix& mat){
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}
