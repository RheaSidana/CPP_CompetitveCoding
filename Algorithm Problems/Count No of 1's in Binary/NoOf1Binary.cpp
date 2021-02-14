/*
Given a binary array sorted in non-increasing order, count the number of 1's in it.

Input Format
You will be given an integer array of size N.

Constraints
1 < N < 10^5
0< = A[i]< = 1


Output Format
You need to print the count of 1's.

Sample TestCase 1
Input
7
1
1
0
0
0
0
0
Output
2
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,count=0;
    cin>>n;
    int bin[n];
    for(int i=0;i<n;i++){
        cin>>bin[i];
        if(bin[i]==1)count+=1;
    }
    cout<<count;
    return 0;
}
