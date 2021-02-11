/*
take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
E D C B A
E D C B A
E D C B A
E D C B A
E D C B A

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,j,i;
    string no="EDCBA";
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;no[j]!='\0';j++){
            cout<<no[j];
            if(no[j+1]!='\0')cout<<" ";
        }
        if(i<(n-1))cout<<endl;
    }
    return 0;
}
