/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
A A A A A
B B B B B
C C C C C
D D D D D
E E E E E 

Input Format
You will take an integer input n from stdin.

Constraints
1 < = n < = 26
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int no=65,n,i,j;
    cin>>n;
    for(i=1;i<=n;i++,no++){
        for(j=1;j<=5;j++){
            cout<<char(no);
            if(j<5)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
