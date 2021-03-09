/*
After finishing eating her bun, Alyona came up with two integers n and m. She decided to write down two columns of integers the first column containing integers from 1 to n and the second containing integers from 1 to m. Now the girl wants to count how many pairs of integers she can choose, one from the first column and the other from the second column, such that their sum is divisible by 5.

Formally, Alyona wants to count the number of pairs of integers (x, y) such that 1 <=x <= n, 1 <= y <=m and equals 0.

As usual, Alyona has some troubles and asks you to help.



Input Format
You will be given two integers n and m .



Constraints
1 <=n, m <= 10^6

Output Format
Print the only integer the number of pairs of integers (x, y) such that 1 <= x <=n, 1 <=y <=m and (x + y) is divisible by 5.


Sample TestCase 1
Input
6 
12
Output
14
Sample TestCase 2
Input
11 
14
Output
31
*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int n,m,count=0;
    cin>>n>>m;   // n=6 and m=12
    int res=n+m;  //res=6+12  => 18
    res/=5;   //res= 18/5  => 3   
    
    //max sum possible is 15
    
    for(int i=1;i<=res;i++){
        int x=5*i;                      //i=1 then x=5*1 => 5
            int p=0;                    //find the value present in m 
            for(int j=1;j<=n;j++){
                if(p!=j){
                    p=x-j;              //x=5 j=1      p=5-1  =>4
                }
                else break;
                if(p>=1 && p<=m){      //if p<=m count++
                    count++;
                }
                if(p==j)break;         //if p=5 and j=5 sum=10 count once only
                if(p>=1 && p<=n){     //if p<=n count++  (pair1: 2 3 and pair2: 3 2)
                    count++;
                }
            }
    }
    cout<<count;
    return 0;
}

