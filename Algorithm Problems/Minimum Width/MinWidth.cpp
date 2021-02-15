/*
Vanya and his friends are walking along the fence of height h and 
they do not want the guard to notice them. In order to achieve this
the height of each of the friends should not exceed h. 
If the height of some person is greater than h he can bend down and 
then he surely won't be noticed by the guard. The height of the 
i-th person is equal to ai.

Consider the width of the person walking as usual to be equal to 1, 
while the width of the bent person is equal to 2. 
Friends want to talk to each other while walking, so they would like 
to walk in a single row. What is the minimum width of the road, 
such that friends can walk in a row and remain unattended by the guard?


Input Format
You will be given a function with integer array and an integer as arguments.


Constraints
1 < N < 10^5
1 < a[i] < 10^5


Output Format
Return a single integer the minimum possible valid width of the road.


Sample TestCase 1
Input
7
3
4 
5 
14


Output
4

*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int h,n,res=0;
    //h is height of the fence and n is the number of friends
    cin>>h>>n;
    int arrh[n];
    for(int i=0;i<n;i++){
        //arrh[] is the array of friend's height 
        cin>>arrh[i];
        //res is the width of the road
        if(arrh[i]>h)
            res+=2;
        else
            res+=1;
    }
    cout<<res;
    return 0;
}


