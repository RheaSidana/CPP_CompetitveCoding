/*
read a integer value(default name - age) from stdin, store it in a variable and then compare that value with the conditions given below -
    - if age is less than 10, then print 'I am happy as having no responsibilities.' to the stdout.
    - if age is equal to or greater than 10 but less than 18, then print 'I am still happy but starts feeling pressure of life.' to the stdout.
    - if age is equal to or greater than 18, then print 'I am very much happy as i handled the pressure very well.' to the stdout. 

Input Format
A single line to be taken as input and save it into a variable of your choice(Default name - age). 

Constraints
1 < = age < = 100 

*/
#include <iostream>
using namespace std;

int main(int argc, char *a[])
{
    int n;
    cin>>n;
    if(n<10){
        cout<<"I am happy as having no responsibilities.";
    }
    else if(n>=10 && n<18){
        cout<<"I am still happy but starts feeling pressure of life.";
    }
    else{
        cout<<"I am very much happy as i handled the pressure very well.";
    }
    return 0;
}
