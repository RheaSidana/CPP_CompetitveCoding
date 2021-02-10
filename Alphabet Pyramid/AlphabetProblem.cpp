/*

take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
             A
          B A B
       C B A B C
   D C B A B C D
E D C B A B C D E 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,no,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        // adding space 
        for(j=0;j<(n-1-i);j++){
            cout<<"  ";
        }
        no=65+i;
        // alphabets in right triangle
        for(j=0;j<=i;j++){
            cout<<(char)no<<" ";
            no--;
        }
        no++;
        //alphabets in left triangle 
        for(j=0;j<i;j++){
            no++;
            cout<<(char)no;
            if(j<(i-1)){
                cout<<" ";
            }
        }
        if(i<(n-1))
        cout<<endl;
    }
    return 0;
}
