/*
take an integer input and store it in a variable of your choice and checks whether this number is an Armstrong number or not. If yes print 'True' else print 'False'.

Input Format
A single integer value to be taken as input from stdin and stored it in a variable. 

Constraints
1 < = n < = 18

*/

#include <iostream>
#include<string.h>
#include <math.h>
using namespace std;
int main(int argc, char *a[])
{
    int no,len,res=0;
    string n;
    cin>>n;
    len=n.length();
    //cout<<"Length: "<<len<<endl;
    int numb=stoi(n);
    //cout<<"numb "<<numb<<endl;
    no=numb;
    for(int i=0;i<len;i++){
        //no=numb/10;
        //cout<<"no:"<<no<<"  ";
        int x=pow((no%10),len);
        //cout<<no%10<<" : "<<x<<endl;
        no=no/10;
        res+=x;
    }
    //cout<<res;
    if(res==numb)cout<<"True";
    else cout<<"False";
    return 0;
}
