/*
 take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-

A B C D E
   A B C D
      A B C
         A B
            A 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,j,i,no;
    cin>>n;
    for(i=1;i<=n;i++){
        
        for(j=1;j<i;j++){
            cout<<"  ";
        }
        no=65;
        for(j=n;j>=i;j--,no++){
            cout<<char(no);
            if(j>i)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
