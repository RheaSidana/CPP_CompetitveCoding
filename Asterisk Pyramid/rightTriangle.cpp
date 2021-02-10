/*
 take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
        *
      * *
    * * *
  * * * *
* * * * *
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
        for(j=1;j<=i;j++){
            cout<<"*";
            if(j<i)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
