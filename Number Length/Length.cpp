/*

 take an integer input from stdin, store it in a variable and  calculate the number of digits in the number using division operator.

Input Format
A single integer value to be taken as input from stdin and stored it in a variable of your choice. 

Constraints
1 < = n < = 18
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,res=0;
    cin>>n;
    while(n){
        res++;
        n=n/10;
    }
    cout<<res;
    return 0;
}
