/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
E E E E E
D D D D
C C C
B B
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
    int no,n,i,j;
    cin>>n;
    for(i=n;i>=1;i--){
        no=64+i;
        for(j=i;j>=1;j--){
            cout<<char(no);
            if(j>1)cout<<" ";
        }
        if(i>1)cout<<endl;
    }
    return 0;
}
