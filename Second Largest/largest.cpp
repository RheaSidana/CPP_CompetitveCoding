/*
take number of elements as input on one line and array elements as an input on another line and find the second largest array element and print that element to the stdout.

Input Format
In this challenge, you will take number of elements as input on one line and array elements which are space separated as input on another line. 

Constraints
1 < = n < = 100000
1 < = a[i] < = 10^9

Output Format
You will print the second largest element to the stdout. 

Sample TestCase 1
Input
6
11 22 33 44 55 66
Output
55
Explanation
Of all the given elements, search the second largest element.

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n;
    cin>>n;
    int arr[n],lmax=0,lmax2=0,rmax=0,rmax2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lmax=lmax2=arr[0];
    rmax=rmax2=arr[(n-1)];
    
    //lmax and lmax2(i) : left to right 
    //rmax and rmax2(j) : right to left 
    for(int i=0,j=(n-1);i<n,j>=0;i++,j--){
        if(arr[i]>lmax){
            lmax2=lmax;
            lmax=arr[i];
        }
        if(arr[j]>rmax){
            rmax2=rmax;
            rmax=arr[j];
        }
    }
    if(lmax2<=rmax2)
        cout<<lmax2;
    else if(lmax2>rmax2)
        cout<<rmax2;
    return 0;
}


