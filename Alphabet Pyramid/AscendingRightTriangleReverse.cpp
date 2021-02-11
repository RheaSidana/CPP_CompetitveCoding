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
    int n,i,j,no;
    cin>>n;
    for(i=0;i<n;i++){
        no=65;
        for(j=1;j<=(n-i);j++,no++){
            cout<<char(no);
            if(j<(n-i))cout<<" ";
        }
        cout<<endl;
    }
}

