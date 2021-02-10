/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
        1
      3 2 1
    5 4 3 2 1
  7 6 5 4 3 2 1
9 8 7 6 5 4 3 2 1

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
        //loop for space 
        for(j=i;j<(n-1);j++){
            cout<<"  ";
        }
        //loop for rev counting 
        for(j=(i*2-1);j>=1;j--){
            cout<<j;
            if(j>1)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
