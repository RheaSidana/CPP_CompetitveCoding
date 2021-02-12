/*
 take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
            1
         3 3 3
      5 5 5 5 5
   7 7 7 7 7 7 7
9 9 9 9 9 9 9 9 9 

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
    for(i=1;i<=n;i++){
        for(j=i;j<n;j++){
            cout<<"  ";
        }
        no=(i*2-1);
        for(j=(i*2-1);j>=1;j--){
            cout<<no;
            if(j>1)cout<<" ";
        }
        if(i<n)cout<<"\n";
    }
    return 0;
}
