/*

Jazzy and Cricket Balls (100 Marks)
Jazzy is good with bowling but is not good with studies. 
His mom wants him to focus on studies too and for this s
he has found an interesting way. 
She has brought N packets of balls which may or 
may not have the same number of balls in them. 
The balls in a packet are arranged in a 
linear manner and Jazzy wants to play with the balls.


She will give the balls to Jazzy only if he can tell 
the maximum number of moves required in which he 
can get to play with all the balls. 
There are few conditions though:
1.	In one move, Jazzy can divide the number of balls in 
the packet into an equal number of groups only. 

Example: Suppose there are 6 balls in the packet.
Jazzy can divide this packet in 3 ways.
1. Two groups of 3 balls each. (3, 3)
2. Three groups of 2 balls each (2, 2, 2)
3. Six groups of 1 ball each.


Note: Dividing a single group into multiple groups of 
equal number is considered one move only.


2.	Jazzy can get to play with the balls when they are 
present as a single unit only and not in any group of 
size greater than 1. 
Also, getting to play with a ball is considered a move.
Example: In a group there are 2 balls, then Jazzy 
cannot play with them until he further divides 
them into single-single units.


3.	 The length of all the packets/groups should 
always be an integer.


Example:
Number of Packets, N = 1
Number of balls in packet = 6


 


Jazzy only cares about playing with the balls and 
needs your help in finding the maximum number of 
moves. Can you help him?





Input Format
The first line of input consists of the number of 
packets, N.
The second line of input consists of N space-separated 
integers representing the number of balls in the packet 
(length of the packet), Ni


Constraints
1<= N <=100
1<= Ni <=10^12 (1e12)


Output Format
Print the required number of maximum moves to get to 
play with the balls.


Sample TestCase 1
Input
2
6 1
Output
11
Explanation
For 6 numbers of balls in a packet, 10 moves are 
required as explained above.
For 1 ball, only 1 move is required.


Total number of moves = 10 + 1 = 11

*/
#include <bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;
bool isPrime(long long int n){
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (long long int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false; 
    return true;
}
int main(int argc, char *a[]){
    map<long long int,long long int> mapArr;
    long int n,i,flag=0;
    map<long long int,long long int>::iterator itr;
    cin>>n;
    long long int j,balls[n],temp,tempTotal,total=0;
    for(i=0;i<n;i++){
        cin>>balls[i];temp=balls[i];
        if(temp==1){total=total+1;continue;}
        if(isPrime(temp)){total=total+1+temp;continue;}
        if(mapArr.empty());
        else{
            itr=mapArr.find(temp);
            if(itr != mapArr.end()){
                total=total+itr->second;
                continue;
            }
        }
        if(flag==1)flag=0;
        tempTotal=temp;
        for(j=2;j<=temp;j++){
            if(temp%j==0){
                flag=1;
                itr=mapArr.find(temp);
                if(itr != mapArr.end()){
                    tempTotal=tempTotal+itr->second;break;
                }
               temp=temp/j;
               tempTotal=tempTotal+temp;
               if(isPrime(temp)){tempTotal++;break;}
               j=1;
            }
            if(j>=3){j=j+1;}
        }
        mapArr.insert({ balls[i], tempTotal });
        total=total+tempTotal;
        if(flag==0){total=total+1+temp;}
    }
    cout<<total;
    return 0;
}
