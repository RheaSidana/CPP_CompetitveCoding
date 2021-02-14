/*
given an array and you need to find odd numbers and add them, find even numbers and add them and print the absolute value of subtraction between those two sums of odd and even values.

Input Format
You will be taking a number as an input from STDIN which tells about the length of the array. On another line, array elements should be there with single space between them.

Constraints
1 <= L <= 1000
1 <= Ai <= 1000


Output Format
Print the absolute value of subtraction to the STDOUT.

Sample TestCase 1
Input
3
23 22 1
Output
2

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,odd=0,even=0,res;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0)
            even+=arr[i];
        else odd+=arr[i];
    }
    if(odd>even)res=odd-even;
    else res=even-odd;
    cout<<res;
    return 0;
}
