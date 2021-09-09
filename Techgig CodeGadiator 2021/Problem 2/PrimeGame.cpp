/*
Rax, a school student, was bored at home in the pandemic. 
He wanted to play but there was no one to play with. 
He was doing some mathematics questions including prime numbers 
and thought of creating a game using the same. 
After a few days of work, he was ready with his game. 
He wants to play the game with you.


GAME:
Rax will randomly provide you a range [ L , R ] (both inclusive) 
and you have to tell him the maximum difference between the 
prime numbers in the given range. 
There are three answers possible for the given range.

1.	There are two distinct prime numbers in the given range 
so the maximum difference can be found.
2.	There is only one distinct prime number in the given range. 
The maximum difference in this case would be 0.
3.	There are no prime numbers in the given range. 
The output for this case would be -1.


To win the game, the participant should answer the prime difference 
correctly for the given range.


Example:
Range: [ 1, 10 ]
The maximum difference between the prime numbers in the given range is 5.
Difference = 7 - 2 = 5


Range: [ 5, 5 ]
There is only one distinct prime number so the maximum difference would be 0.


Range: [ 8 , 10 ]
There is no prime number in the given range so the output for the given 
range would be -1.


Can you win the game?



Input Format
The first line of input consists of the number of test cases, T
Next T lines each consists of two space-separated integers, L and R



Constraints
1<= T <=10
2<= L<= R<=10^6



Output Format
For each test case, print the maximum difference in the given range 
in a separate line. 


Sample TestCase 1
Input
5
5 5
2 7
8 10
10 20
4 5
Output
0
5
-1
8
0
Explanation
Test Case 1: [ 5 - 2 ] = 3
Test Case 2: [ 7 - 2 ] = 5
Test Case 3: No prime number in the given range. Output = -1
Test Case 4: [ 19 - 11 ] = 8
Test Case 5: The difference would be 0 since there is only one prime 
number in the given range.

Solution:
*/
#include <iostream>
using namespace std;
class Game{
    int l,r;
    int firstPrime,lastPrime;
    void isBegPrime(){
        int flag;
        for(int i=l;i<=r;i++){
            flag=1;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                firstPrime=i;
                break;
            }
        }
    }
    void isLastPrime(){
        int flag;
        for(int i=r;i>firstPrime;i--){
            flag=1;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                lastPrime=i;
                break;
            }
        }
    }

    public :
    Game(){
        firstPrime=0;
        lastPrime=0;
    }
    void getRange(){
        cin>>l>>r;
    }
    void displayDifference(){
        int diff;
        isBegPrime();
        if(firstPrime!=0){
            isLastPrime();
        }
        //cout<<firstPrime<<" "<<lastPrime;
        if(firstPrime==0 && lastPrime==0){
            diff=-1;
            cout<<diff;
        }
        else if(firstPrime!=0 && lastPrime==0){
            diff=0;
            cout<<diff;
        }
        else{
            diff=lastPrime-firstPrime;
            cout<<diff;
        }
    }
};

int main(int argc, char *a[])
{
    int T,i;
    cin>>T;
    Game myGame[T];
    for(i=0;i<T;i++){
        myGame[i].getRange();
    }
    for(i=0;i<T;i++){
        myGame[i].displayDifference();
        if(i<(T-1))cout<<endl;
    }
    return 0;
}
