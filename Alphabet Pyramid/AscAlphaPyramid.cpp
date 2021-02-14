/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
            A
         A B C
      A B C D E
   A B C D E F G
A B C D E F G H I 

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
        for(j=i;j<n;j++){
            cout<<"  ";
        }
        no=65;
        int m=(i*2)-1;
        for(j=m;j>=1;j--,no++){
            cout<<char(no);
            if(j>1)cout<<" ";
        }
        if(i<n)cout<<"\n";
    }
    return 0;
}
