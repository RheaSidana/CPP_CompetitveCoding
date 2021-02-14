/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
            1
         1 2 3
      1 2 3 4 5
   1 2 3 4 5 6 7
1 2 3 4 5 6 7 8 9 

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
    for(i=1;i<=n;i++){
        for(j=i;j<n;j++){
            cout<<"  ";
        }
        int m=(i*2-1);
        for(j=1;j<=m;j++){
            cout<<j;
            if(j<m)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
