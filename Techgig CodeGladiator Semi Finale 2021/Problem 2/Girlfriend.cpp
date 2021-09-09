/*
Girlfriend (100 Marks)
There are N number of houses in the city of La La Land 
and R number of roads connecting the houses. 
Each house is marked from 1 to N. Rahul lives in 
house number 1 and his girlfriend Anjali lives in the 
Nth house. 
Anjali is home alone today and has hurt herself while 
she was trying to make a present for Rahul. 
Rahul gets to know about it and wants to go to meet 
Anjali in the most cost efficient way as it is the 
month end and he does not have a lot of money with him. 
Since Anjali lives far away, 
Rahul will use the taxi to reach her house.


The city of La La Land has a unique system of fare 
collection by taxis.
1.	Each road has a cost associated with it to travel on it.
2.	There might or might not be a direct road between any 
two houses. 
3.	To travel on a road connecting Ni and Nj, the person 
has to pay the difference in cost price connecting 
(Ni, Nj) and the total cost to reach Ni.
Example:
Consider three houses H1, H2 and H3

The cost to travel from H2 to H3 is 15.

Cost = Cost of travel between (H2, H3) - Total cost to reach H2 = 25 - 10 = 15

Note: If the difference comes out to be negative, 
it is free of cost for a person to travel on the 
road between Hi and Hj.
4.	The roads are bidirectional (directionless).


Rahul is good in the subject of love but is very poor 
in the subject of mathematics. Can you help Rahul 
determine the cost he would have to pay to reach 
Anjali if it is possible otherwise just tell him 
NOT POSSIBLE.


Example:
Number of houses, N = 5
Number of roads, R = 5

Consider the connection graph given below.

There are two ways in which Rahul (1) can reach 
Anjali’s house (5).

Route 1: 1 - 2 - 5

Cost of travel from 1 to 2 = 30
Cost of travel from 2 to 5 = 40 - 30 = 10

Total cost of travel = 30 + 10 = 40

Route 2: 1 - 3 - 4 - 5

Cost of travel from 1 to 3 = 10
Cost of travel from 3 to 4 = 20 - 10 = 10
Cost of travel from 4 to 5 = 30 - 20 
(Total cost of travel to reach 4, 10 + 10) = 10

Total cost of travel = 10 + 10 + 10 = 30

Route 2 is better suited for Rahul as it is cost 
efficient and he would have to 30.

Input Format
The first line of input consists of two space-separated 
integers: number of houses, N and number of roads, R.
Next R lines each consists of three space-separated 
integers: starting node (house), Ni; ending node (house), 
Nj and Cost of travel on Road Ri connecting Ni and Nj, C.


Constraints
1<= N <=50000
1<= R < 500000
1<= C (Cost of travel on road connection two houses) <= 10^7 (1e7)

Output Format
If it is possible for Rahul to reach Anjali’s house, 
print the minimum amount of fare he has to pay to 
taxi otherwise print NOT POSSIBLE.


Sample TestCase 1
Input
5 5
1 2 30
1 3 10
2 5 40
3 4 20
4 5 30
Output
30
Explanation
As explained in the example.
Sample TestCase 2
Input
4 3
1 2 10
3 2 20
1 3 5
Output
NOT POSSIBLE
Explanation
It is not possible to reach Anjali’s 
house (4)

Time Limit(X):
0.75 sec(s) for each input.
Memory Limit:
512 MB
Source Limit:
100 KB
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
#include <vector>
#include<iterator>
using namespace std;
/*void showVect(vector<long int> houseVect){
    vector<long int> :: iterator itr;
    for(itr=houseVect.begin();itr!=houseVect.end();itr++){
        cout<<*itr<<"  ";
    }
}*/
void showVectLong(vector<long long int> houseVect){
    vector<long long int> :: iterator itr;
    for(itr=houseVect.begin();itr!=houseVect.end();itr++){
        cout<<*itr<<"  ";
    }
}
long long int calCost(vector<long long int> houseVect){
    long long int tot=0,prev;
    //vector<long long int> :: iterator itr;
    for(long int itr=0;itr<houseVect.size();itr++){
        //cout<<*itr<<"  ";
        if(itr == 0){
            tot=houseVect.at(itr);
            prev=houseVect.at(itr);
        }
        else{
            tot=tot+houseVect.at(itr)-prev;
            prev=houseVect.at(itr);
        }
    }
    return tot;
}
int main(int argc, char *a[])
{
    long int N,R,i,row,col,j,start=0,prev=-1,next=-1,end;
    cin>>N>>R;
    end=N-1;
    //vector<long int> houseVect;
    //vector<long int> route;
    vector<long long int> routeCost;
    /*for(i=0;i<N;i++){
        houseVect.push_back(i);
    }*/
    //showVect(houseVect);
    long long int cost[N][N],min=0,totalCost;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cost[i][j]=0;
        }
    }
    for(i=0;i<R;i++){
        cin>>row>>col;
        row--;col--;
        cin>>cost[row][col];
        cost[col][row]=cost[row][col];
    }
    //cout<<end<<endl;
    for(i=0;i<N;i++){
        if(min==0 && cost[end][i]!=0){
            min=cost[end][i];
            break;
        }
    }
    if(min==0) cout<<"NOT POSSIBLE";
    else{
        min=0;
        for(i=0;i<N;i++){
            if(min==0 && cost[start][i]!=0){
                min=cost[start][i];
            }
            else if(cost[start][i]!=0 &&  min>cost[start][i]){
                min=cost[start][i];
                next=i;
            }
        }
        if(min==0)cout<<"NOT POSSIBLE";
        else{
            //cout<<"enter the main";
            //route.push_back(start);
            prev=start;
            start=next;
            //route.push_back(next);
            routeCost.push_back(min);
            while(true){
                if(start==end)break;
                min=0;
                for(i=0;i<N;i++){
                    if(i==prev)continue;
                    if(min==0 && cost[start][i]!=0){
                        min=cost[start][i];
                        next=i;
                    }
                    else if(cost[start][i]!=0 && min>cost[start][i]){
                        min=cost[start][i];
                        next=i;
                        //cout<<"start: "<<start<<"  min: "<<min<<"  next: "<<next<<endl;
                    }
                }
                if(min==0){
                    start=prev;
                }
                else if(min>0){
                    //cout<<"min: "<<min<<"  next: "<<next<<endl;
                    prev=start;
                    start=next;
                    //route.push_back(next);
                    routeCost.push_back(min);
                }
            }
            //cout<<"\nFinally: ";
            //showVect(route);
            //cout<<endl;
            showVectLong(routeCost);
            cout<<endl;
            totalCost=calCost(routeCost);
            cout<<totalCost;
        }
    }
    return 0;
}
