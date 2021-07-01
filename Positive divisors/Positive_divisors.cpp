/*
positive divisors (100 Marks)
If an integer a is divisible by another integer b, then b is called the divisor of a.

For example: 12 has positive 6 divisors. They are 1, 2, 3, 4, 6 and 12.
Let s define a function D(n) number of integers between 1 and n (inclusive) which has exactly four positive divisors.
Between 1 and 10 only the integers 6, 8 and 10 has exactly four positive divisors. So, D(10) = 3.
You are given an integer n. You have to calculate D(n).


Input Format
You will be given a function with integer n, as a single argument.


Constraints
1 <= n <=1011

Output Format
Return the only integer c the number of integers between 1 and n with exactly four divisors.


Sample TestCase 1
Input
10
Output
3
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    //Write code here

    int num,div,i,res,ans=0;
    cin>>num;
    for(i=1;i<=num;i++){
        res=2;
        for(int j=2;j<i;j++){
            if(i%j==0){
                res++;
            }
            if(res>4){
                break;
            }
        }
        if(res==4){
            ans++;
        }
    }
    cout<<ans;
}
