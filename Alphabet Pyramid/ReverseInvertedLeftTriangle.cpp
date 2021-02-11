/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-

E D C B A
E D C B
E D C
E D
E

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
        no=64+n;
        for(j=1;j<=(n-i);j++,no--){
            cout<<char(no);
            if(j<(n-i))cout<<" ";
        }
        cout<<endl;
    }
}
