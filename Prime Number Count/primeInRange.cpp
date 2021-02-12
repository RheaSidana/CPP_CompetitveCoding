/*
 given a range and you need to find how many prime numbers lying between the given range.

Input Format
For this challenge, you need to take two integers on separate lines. These numbers defines the range. 

Constraints
1 < = ( a , b ) < = 100000

Sample TestCase 1
Input
1
20
Output
8
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int start,end,prime=0,flag;
    cin>>start>>end;
    for(int i=start;i<=end;i++){
        flag=1;
        if(i<=1)continue;
        for(int j=2;j<=i/2;j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            //cout<<i<<" ";
            prime++;
        }
    }
    cout<<prime;
    return 0;
}
