/*
given the values of principal, interest and year. You need to calculate the simple interest, round it to the nearest integer and print it.

Input Format
There will be 3 lines of numeric input - 
'a' : principal which is of type double. 
'b' : interest which is of type integer. 
'c' : year which is again of type integer. 

Constraints
1 < = (a,b,c) < = 1000

Sample TestCase 1
Input
1000
4
2
Output
80
*/

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *a[])
{
    double ab,si;
    int b,c;
    cin>>ab;
    cin>>b>>c;
    si=(ab*b*c)/100;
    cout<<round(si);
    return 0;
}
