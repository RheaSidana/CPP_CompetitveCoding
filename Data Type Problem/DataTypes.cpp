/*
need to read a line from stdin and check whether it is of type integer, float or string.
If input is-
    Integer print 'This input is of type Integer.' to the stdout
    Float print 'This input is of type Float.' to the stdout
    String print 'This input is of type string.' to the stdout
    else print 'This is something else.' to the stdout.

Input Format
A single line to be taken as input as save it to a variable(name of your choice). 

Constraints
1 < |s| < 10000
*/

#include <iostream>
using namespace std;
//checks whether the itput provided is integer
bool isNo(string val){
    for (int i = 0; i < val[i]!='\0'; i++){
        if (isdigit(val[i]) == false){
            if(val[i]!='-')
            if(val[i]!='+')
            return false;
        }
    }
    return true;
}

//checks whether the itput provided is float
bool isFloat(string val){
    for(int i=0;val[i]!='\0';i++){
        if(val[i]=='.'){
            return true;
        }
    }
    return false;
}

//checks whether the itput provided is string 
bool isString(string val){
  for(int i=0;val[i]!='\0';i++){
   if(isalpha(val[i])==false){
       if(val[i]!=' ')
       if(val[i]!='.')
        return false;
   }
  }
  return true;
 }

int main(int argc, char *a[])
{
    string val;
    getline(cin,val);
    // checking first character is alphabet or not because both string and floating point can contain '.'(full stop or real no)
    if(isalpha(val[0])==false){
      if(isNo(val)){
        cout<<"This input is of type Integer.";
      }
      else if(isFloat(val)){
        cout<<"This input is of type Float.";
      }
    }
    else{
      if(isString(val)){
        cout<<"This input is of type string.";
      }
      else cout<<"This is something else.";
    }
    return 0;
}
