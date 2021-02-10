/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
        A
      C C C
    E E E E E
  G G G G G G G
I I I I I I I I I

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 13

*/

#include <iostream>
using namespace std;

int main(int argc, char *a[])
{
    int n,no;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<n;j++){
            cout<<"  ";
        }
        no=64+(i*2-1);
        for(int j=(i*2-1);j>=1;j--){
            cout<<char(no);
            if(j>1)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
