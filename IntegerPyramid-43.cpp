/*
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
Output
        0 
      1 0 1
    2 1 0 1 2
  3 2 1 0 1 2 3
4 3 2 1 0 1 2 3 4

Input Format
You will take an integer input n from stdin.

Constraints
0 <= n <= 1000
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    //Write code here
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=i;j<(n-1);j++){
            cout<<"  ";
        }
        for(j=i;j>=0;j--){
            cout<<j<<" ";
        }
        //cout<<0<<" ";
        for(j=1;j<=i;j++){
            cout<<j;
            if(j<i)
                cout<<" ";
        }
        if(i<(n-1))
        cout<<endl;
    }
    return 0;
}
