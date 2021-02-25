/*
Patch Up Two Matrices (100 Marks)
For this challenge, you need to take 2 matrices as an input from the stdin , add them and print the resultant matrix to the stdout.

Input Format
Two matrices to be taken as an input. 
For each matrix, on first line you need to tell that how many rows and columns your matrix need to have and these values should be separated by space. 
Then after that, each line will represent will represent each row and you need to enter numbers which each rows should have separated by a space. 

Constraints
1 <  (n,m) < 100
1 <  (p,q) < 100

Output Format
Print the resultant matrix to the stdout where each each line should represent 
Note : Please do not include space after the numbers which are in the last column as it will affect your submission and you will not get marks. 
each row and values in the row should be separated by a space. 

Sample TestCase 1
Input
3 3
1 2 3
4 5 6
7 8 9
3 3
2 3 4
5 6 7
7 8 9
Output
3 5 7
9 11 13
14 16 18

*/

#include <iostream>
using namespace std;
class Matrix{
    int row,col;
    int** mat;
    public:
    void dimension(){
        cin>>row>>col;
    }
    void getMat(){
        mat= new int*[row];
        for(int i=0;i<row;i++){
            mat[i]=new int[col];
            for(int j=0;j<col;j++){
                cin>>mat[i][j];
            }
        }
    }
    Matrix operator + (Matrix &m1){
        Matrix m3;
        m3.row=m1.row;
        m3.col=m1.col;
        m3.mat=new int*[m3.row];
        for(int i=0;i<m3.row;i++){
            m3.mat[i]=new int[m3.col];
            for(int j=0;j<m3.col;j++){
                m3.mat[i][j]=m1.mat[i][j]+mat[i][j];
            }
        }
        return m3;
    }
    void display(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<mat[i][j];
                if(j<(col-1)){
                    cout<<" ";
                }
            }
            if(i<(row-1)){
                cout<<endl;
            }
        }
    }
};
int main(int argc, char *a[])
{
    Matrix m1,m2,m3;
    m1.dimension();
    m1.getMat();
    m2.dimension();
    m2.getMat();
    m3=m1+m2;
    m3.display();
    return 0;
}
