/*
Petr wants to make a calendar for current month. 
For this purpose he draws a table in which columns correspond to weeks 
(a week is seven consequent days from Monday to Sunday), 
rows correspond to weekdays, and cells contain dates. 
For example, a calendar for January 2017 should look like on the picture:

Petr wants to know how many columns his table should have
given the month and the weekday of the first date of that month? 
Assume that the year is non-leap.


Input Format
You will be given a function with two integers m and d as arguments.


Constraints
1 < = m < = 12
1 < = d < = 7


Output Format
You need to return single integer: the number of columns the table should have..


Sample TestCase 1
Input
1
7
Output
6


*/

#include <iostream>
using namespace std;
int main(int argc, char *a[])
{
    int m,d;
    cin>>m>>d;
    if(d==1 && m==2)cout<<4;
    else if(d<=6 && (m==4 || m==6 || m==9 || m==11)) cout<<5;
    else
    if(d<=5) cout<<5;
    else{
        if(m!=2 || m==1 || m==3 || m==5 || m==7|| m==8 || m==10 || m==12)
            cout<<6;
        else cout<<5;
    }
}
