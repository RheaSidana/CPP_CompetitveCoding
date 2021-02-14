/*
given an array and you are asked to find the largest even 
number and print it to the STDOUT.

Input Format
you will be taking a number as an input from STDIN 
which tells about the length of the array. On another line, 
array elements should be there with single space between them.

Constraints
1 <= L <= 1000
1 <= Ai <= 1000


Output Format
print the largest even number to the STDOUT.

Sample TestCase 1
Input
6
78 92 44 63 71 97
Output
92

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,l;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0)l=arr[i];
        else
        if((arr[i]%2==0) && arr[i]>l)
        l=arr[i];
    }
    cout<<l;
    return 0;
}
