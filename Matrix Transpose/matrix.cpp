/*
take a matrix as an input from the stdin , transpose it and print the resultant matrix to the stdout.

Input Format
A matrix is to be taken as input from stdin. On first line you need to tell that how many rows and columns your matrix need to have and these values should be separated by space. Below lines will represent the elements of the matrix where each line will represent the row of the matrix.

Constraints
1 < (n,m) < 100

Output Format
Print the resultant matrix to the stdout where each line should represent each row and values in the row should be separated by a space. 

Sample TestCase 1
Input
3 3
1 2 3
4 5 6
7 8 9
Output
1 4 7
2 5 8
3 6 9
Explanation
The transpose of a matrix is a new matrix whose rows are the columns of the original.

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int r,c;
    cin>>r>>c;
    int mat[c][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[j][i];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<mat[i][j];
            if(j<(r-1))cout<<" ";
        }
        if(i<(c-1))cout<<endl;
    }
    return 0;
}
