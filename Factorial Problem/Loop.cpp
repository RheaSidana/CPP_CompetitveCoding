/*
 take an integer value as input from stdin, calculate its factorial and print the result to the stdout. 1

Input Format
A single integer value to be taken as input from stdin and stored it in a variable of your choice. 

Constraints
1 < = n < = 15

*/
#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,r=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        r*=i;
    }
    cout<<r;
    return 0;
}
