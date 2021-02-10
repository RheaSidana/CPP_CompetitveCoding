/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
5 5 5 5 5
4 4 4 4 4
3 3 3 3 3
2 2 2 2 2
1 1 1 1 1 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

*/
#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,i,j;
    cin>>n;
    for(i=n;i>=1;i--){
        for(j=1;j<=5;j++){
            cout<<i;
            if(j<5)cout<<" ";
        }
        if(i>1)cout<<endl;
    }
    return 0;
}
