/*
 take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int no,n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        no=64;
        for(j=1;j<=5;j++){
            no++;
            cout<<char(no);
            if(j<5)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
