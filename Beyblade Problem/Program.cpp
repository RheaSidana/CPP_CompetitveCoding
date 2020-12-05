/*
Beyblade World Championship

Tyson is all prepared for the Beyblade World Championship. 
The tournament is team-based and each team can have N members. 
A player can fight against a single player only. 
Team G-Revolution is all excited and pumped up as they have 
practised a lot. Kenny, the mind of team G-Revolution, 
has created a database where he has the data about the power 
of other teams’ members and his own team members. 
The tournament is going to start in some time and Kenny 
moves to the cafeteria to have a snack before the competition.

The team G-Revolution is to fight in some time and they are 
tensed up as someone has kidnapped Kenny from the cafeteria. 
They have made a police complaint and the police are searching 
for Kenny. Luckily, they have found his device with all the 
data. The problem is, the data is present randomly and not in 
the order they have to fight the opponent. Team G-Revolution 
wants to win at any cost and for that, they need the order in 
which they have to fight optimally to win the maximum number 
of battles.

A player can win only when his/her beyblade power is 
strictly greater than the opponents beyblade power.

Consider the team size is 3, N = 3
The maximum number of fights Team G-Revolution can win is 2 when 
they are arranged optimally or fight in an optimal order.

Team G-Revolution needs help with the device. Tyson has heard 
about your skills and called you up to help them shuffle their 
positions in an order such that they would be able to win the 
maximum number of fights. Can you help Tyson and 
Team G-Revolution?

    Constraints
    1<= T <=100000
    1<= N <=100000
    
    0<= Power of Beyblade <= LLONG_MAX 
    
    Input:
    1
    10
    3 6 7 5 3 5 6 2 9 1 
    2 7 0 9 3 6 0 6 2 6 
    Output
    7
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    long int T;
    //The first line of input consists of the number of test cases, T
    cin>>T;
    long int N[T],C[T],n;
    long int i,j,k,m;
    long long int *mp[T],*op[T],maxv;
    for(i=0;i<T;i++){
        //The first line of each test case consists of the number of members each team can have, N.
        cin>>N[i];
        C[i]=0;
        maxv=0;
        n=N[i];
        mp[i]=new long long int [n];
        op[i]=new long long int [n];

        for(j=0;j<n;j++){
            //The second line of each test case consists of N 
            //space-separated integers representing the power 
            //of beyblades of Team G-Revolution members.
            cin>>mp[i][j];
            if(mp[i][j]>maxv){
                maxv=mp[i][j];
            }
        }
        for(j=0;j<n;j++){
            //The third line of each test case consists of 
            //N space-separated integers representing the power 
            //of beyblades of opponent team members.
            cin>>op[i][j];
        }
        //sorting the two lists
        sort(mp[i],mp[i]+n);
        sort(op[i],op[i]+n);
        /*Displaying the array*/
        for(int a=0;a<T;a++){
            for(int b=0;b<n;b++){
                cout<<mp[a][b]<<" ";
            }
            cout<<endl;
            for(int b=0;b<n;b++){
                cout<<op[a][b]<<" ";
            }
            cout<<endl;
        }
        m=0;
        for(j=0;j<N[i];j++){
            if(op[i][j]>=maxv){
                break;
            }
            else{
                for(k=m;k<n;k++){
                    if(op[i][j]<mp[i][k]){
                        C[i]+=1;
                        break;
                    }
                }
                if(k==(n-1)){
                    break;
                }
                m=k;
                m++;
            }
        }
    }
    for(i=0;i<T;i++){
        cout<<C[i]<<"\n";
    }
    return 0;
}
