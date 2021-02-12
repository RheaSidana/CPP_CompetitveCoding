/*
 take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
        A
      A B
    A B C
  A B C D
A B C D E 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26
*/

#include <iostream>
using namespace std;

int main(int argc, char *a[])
{
    int n,i,j,no;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=i;j<n;j++){
            cout<<"  ";
        }
        no=65;
        for(j=1;j<=i;j++,no++){
            cout<<char(no);
            if(j<i)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
