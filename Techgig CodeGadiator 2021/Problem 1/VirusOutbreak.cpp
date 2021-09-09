/*
Virus Outbreak (100 Marks)
In the Martian land faraway, a new virus has evolved and is attacking the 
individuals at a fast pace. 
The scientists have figured out the virus composition, V. 
The big task is to identify the people who are infected. 
The sample of N people is taken to check if they are POSITIVE or NEGATIVE. 
A report is generated which provides the current blood composition B of the person. 


POSITIVE or NEGATIVE ?
If the blood composition of the person is a subsequence of 
the virus composition V, then the person is identified as POSITIVE otherwise NEGATIVE.


Example:
Virus Composition, V = coronavirus
Blood Composition of the person , B = ravus


The person in question is POSITIVE as B is the 
subsequence of the V. 
The scientists are busy with their research for medicine and 
request you to build a program which can quickly figure out if the 
person is POSITIVE or NEGATIVE. They will provide you with the virus 
composition V and all the people’s current blood composition. 
Can you help them?

Note: The virus and blood compositions are lowercase alphabet 
strings.


Input Format
The first line of the input consists of the virus composition, V
The second line of he input consists of the number of people, N
Next N lines each consist of the blood composition of the ith person, Bi





Constraints
1<= N <=10
1<= |B|<= |V|<= 10^5



Output Format
For each person, print POSITIVE or NEGATIVE in a separate line


Sample TestCase 1
Input
coronavirus
3
abcde
crnas
onarous
Output
NEGATIVE
POSITIVE
NEGATIVE

Solution:
*/
#include <iostream>
using namespace std;

class Virus{
    string v;
    int n;
    string *b;

    public: 
    void getDetails(){
        cin>>v;
        cin>>n;
        b= new string[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
    }

    void displayDetails(){
        string negative="NEGATIVE";
        string positive="POSITIVE";
        int k,flag=0;

        for(int i=0;i<n;i++){
            k=0;
            for(int j=0;b[i][j]!='\0';j++){
                if(v[k]=='\0' && b[i][j]!='\0'){
                    flag=1;
                    break;
                }
                while(v[k]!='\0'){
                    if(v[k]==b[i][j]){
                        flag=0;
                        k++;
                        break;
                    }
                    k++;
                }
            }
            if(flag==0){
                cout<<positive;
            }
            else if(flag==1){
                cout<<negative;
            }
            if(i<(n-1))cout<<endl;
        }
    }
};

int main(int argc, char *a[])
{
    Virus newVirus;
    newVirus.getDetails();
    newVirus.displayDetails();
    return 0;
}
