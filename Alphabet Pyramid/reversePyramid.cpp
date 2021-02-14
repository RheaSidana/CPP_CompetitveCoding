/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
           A
        C B A
     E D C B A
  G F E D C B A
I H G F E D C B A

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
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--){
            cout<<"  ";
        }
        int m=(i*2-1);
        no=64+m;
        for(j=m;j>=1;j--,no--){
            cout<<char(no);
            if(j>1)cout<<" ";
        }
        if(i<n)cout<<endl;
    }
    return 0;
}
