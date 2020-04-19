#include <iostream>
#include<iomanip>

using namespace std;

struct matrix{
        int** data;
        int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat);
ostream& operator<< (ostream& out, matrix mat);
bool   operator== (matrix mat1, matrix mat2);
bool   operator!= (matrix mat1, matrix mat2);
bool   isSquare   (matrix mat);
bool   isSymetric (matrix mat);
bool   isIdentity (matrix mat);
matrix transpose(matrix mat);

int main()
{
    matrix mat1 , mat2;
    int num[9]={1,0,0,0,1,0,0,0,1};
    int num2[9]={1,2,3,4,5,6,7,8,9};
    createMatrix(3,3,num,mat1);
    createMatrix(3,3,num2,mat2);
    cout << mat1;
    cout << isIdentity(mat1);

    return 0;
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
                if(i==j) if(mat.data[i][j] != 1) return false;

                else (mat.data[i][j] !=0) return false;
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
