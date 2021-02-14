/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
9 9 9 9 9 9 9 9 9
   7 7 7 7 7 7 7
      5 5 5 5 5
         3 3 3
            1

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,i,j,no;
    cin>>n;
    for(i=n;i>=1;i--){
        for(j=1;j<(n-i+1);j++){
            cout<<"  ";
        }
        no=(i*2)-1;
        for(j=1;j<=no;j++){
            cout<<no;
            if(j<no)cout<<" ";
        }
        if(i>1)cout<<endl;
    }
    return 0;
}
