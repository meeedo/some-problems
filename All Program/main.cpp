#include <iostream>

using namespace std;

struct matrix
{
    int** data;
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat); // create a new matrix by take the row and col

matrix operator+  (matrix mat1, matrix mat3); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat3); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat3); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);               // Add 1 to each element ++mat
void   operator-- (matrix& mat);    	       // Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat); // take matrix from user

ostream& operator<< (ostream& out, matrix mat); // to print matrix
bool   operator== (matrix mat1, matrix mat2); // check if the two matrix are equal
bool   operator!= (matrix mat1, matrix mat2); // check if the two matrix are not equal
bool   isSquare   (matrix mat);                // check if the matrix is square
bool   isSymetric (matrix mat);                // check if the matrix is symmetric
bool   isIdentity (matrix mat);                 // check if the matrix is identity
matrix transpose(matrix mat);                   // transpose matrix and return new matrix

int main()
{
    matrix mat1 , mat2 , mat3;
    int num[9]={1,0,0,0,1,0,0,0,1};
    int num2[9]={1,2,3,4,5,6,7,8,9};
    createMatrix(3,3,num,mat1);
    createMatrix(3,3,num2,mat2);
    cout << mat1;
    cout << isIdentity(mat1);

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

//----------------------------------------------------------------------

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
    cout << "Enter the row : " ;
    cin >> mat.row;
    cout << "Enter the col : " ;
    cin >> mat.col;
    mat.data = new int* [mat.row];
    for (int i = 0; i < mat.row; i++)
        mat.data[i] = new int [mat.col];

    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            in>>mat.data[i][j];
        }
    }
    return in;
}
//--------------------------------------------------------

ostream& operator<< (ostream& out, matrix mat){
    for(int i=0 ; i<3 ;i++){
        for(int j=0 ; j<3 ; j++){
            out << mat.data[i][j] << " ";
        }
        out << endl;
    }
 return out;
}
bool operator== (matrix mat1, matrix mat2){
    int check=0;
    if((mat1.row==mat2.row) && (mat1.col==mat2.col)){
        for(int i=0 ; i<mat1.row ; i++){
            for(int j=0 ; j<mat1.col ; j++){
                if(mat1.data[i][j] != mat2.data[i][j]) check+=1;
    }}
    }
    else{
        cout << "The two matrices not have the same row and col" << endl;
        check=1;
    }
    return !check;
}
bool operator!= (matrix mat1, matrix mat2){
    int check=0;
    if((mat1.row==mat2.row) && (mat1.col==mat2.col)){
        for(int i=0 ; i<mat1.row ; i++){
            for(int j=0 ; j<mat1.col ; j++){
                if(mat1.data[i][j] != mat2.data[i][j]) check+=1;
    }}
    }
    else{
        cout << "The two matrices not have the same row and col" << endl;
        check=1;
    }
    return check;

}
bool isSquare   (matrix mat) {
    if (mat.row == mat.col) return true;
    else return false;
}
bool isSymetric (matrix mat){

    if(mat == transpose(mat)) return true;
    else return false;

}
bool isIdentity (matrix mat){
    if(!isSquare(mat)) return false;
    for(int i=0 ; i< mat.row ; i++){
            for(int j=0 ; j<mat.col ; j++){
                if(i==j){
                        if(mat.data[i][j] != 1) return false;
                }

                else if (mat.data[i][j] !=0) return false;
        }
    }
        return true;
}
matrix transpose(matrix mat){
    matrix trans;
    int arr[mat.col * mat.row];
    createMatrix((mat.col),(mat.row) , arr , trans);
    for(int i=0 ; i<(mat.row) ; i++){
        for(int j=0 ; j<(mat.col) ; j++)
            trans.data[j][i] = mat.data[i][j];
    }
    return trans;
}
