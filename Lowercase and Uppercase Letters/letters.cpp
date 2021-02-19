/*
 take a string as an input from the stdin, count the number of uppercase and lowercase letters and print them to the stdout.

Input Format
A single line of string to be taken as an input and store it in a variable of your choice. 

Constraints
1 < = |s| < = 100000 

Output Format
print the number of uppercase letters on one line and number of lowercase letters on another side. 

Sample TestCase 1
Input
I Am Awesome
Output
3
7
*/

#include <iostream>
#include <cctype>
using namespace std;
int main(int argc, char *a[])
{
    string str;
    getline(cin,str);
    int lower=0,upper=0;
    for(int i=0;str[i]!='\0';i++){
        //cout<<"Enter";
        if(islower(str[i])){
            lower++;
        }
        else if(isupper(str[i])){
            upper++;
        }
    }
    cout<<upper<<endl<<lower;
    return 0;
}
