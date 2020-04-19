#include <iostream>

using namespace std;

struct matrix
{
    int** data;
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat);
matrix operator+  (matrix mat1, matrix mat3); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat3); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat3); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

int main()
{
    int arr[9]={1,2,3,4,5,6,7,8,9};
    matrix mat1 , mat2;
    createMatrix(3,3,arr,mat1);
    createMatrix(3,3,arr,mat2);


    return 0;
}
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];
    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
matrix operator+(matrix mat1, matrix mat3)
{
    matrix mat2;
    mat2.row=mat1.row=mat3.row;
    mat2.col=mat1.col=mat3.col;
    int data[mat2.row*mat2.col];
    createMatrix(mat2.row,mat2.col,data,mat2);
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat2.data[i][j]=mat1.data[i][j]+mat3.data[i][j];
        }
    }
    return mat2;
}
matrix operator-(matrix mat1, matrix mat3)
{
    matrix mat2;
    mat2.row=mat1.row=mat3.row;
    mat2.col=mat1.col=mat3.col;
    int data[mat2.row*mat2.col];
    createMatrix(mat2.row,mat2.col,data,mat2);
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat2.data[i][j]=mat1.data[i][j]-mat3.data[i][j];
        }
    }
    return mat2;
}
matrix operator*(matrix mat1, matrix mat2)
{
    matrix mat3;
    mat3.row=mat1.row;
    mat3.col=mat2.col;
    int data[mat3.row*mat3.col];
    createMatrix(mat3.row,mat3.col,data,mat3);
    int sum=0;
    for(int i=0; i<mat3.row; ++i)
    {
        for(int j=0; j<mat3.col; ++j)
        {
            for(int p=0; p<mat2.row; ++p)
            {
                sum+=mat1.data[i][p]*mat2.data[p][j];
            }
            mat3.data[i][j]=sum;
            sum=0;
        }
    }
    return mat3;
}
matrix operator+ (matrix mat1, int scalar)
{
    matrix mat2;
    mat2.row=mat1.row;
    mat2.col=mat1.col;
    int data[mat2.row*mat2.col];
    createMatrix(mat2.row,mat2.col,data,mat2);
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat2.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat2;
}
matrix operator-(matrix mat1, int scalar)
{
    matrix mat2;
    mat2.row=mat1.row;
    mat2.col=mat1.col;
    int data[mat2.row*mat2.col];
    createMatrix(mat2.row,mat2.col,data,mat2);
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {

                mat2.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat2;
}
matrix operator*  (matrix mat1, int scalar)
{
    matrix mat2;
    mat2.row=mat1.row;
    mat2.col=mat1.col;
    int data[mat2.row*mat2.col];
    createMatrix(mat2.row,mat2.col,data,mat2);
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat2.data[i][j]=scalar*mat1.data[i][j];
        }
    }
    return mat2;

}
