/*

Vasya decided to pass a very large integer n to Kate. First, he wrote that number as a string, then he appended to the right integer k the number of digits in n.

Magically, all the numbers were shuffled in arbitrary order while this note was passed to Kate. The only thing that Vasya remembers, is a non-empty substring of n (a substring of n is a sequence of consecutive digits of the number n).
Vasya knows that there may be more than one way to restore the number n. Your task is to find the smallest possible initial integer n. Note that decimal representation of number n contained no leading zeroes, except the case the integer n was equal to zero itself (in this case a single digit 0 was used).


Input Format
You will be given a function with two strings as arguments where number of digits in first string does not exceed and the second string can contain leading zeroes.


Constraints
1 < |S| < 10^5

Output Format
Return the smallest integer n which Vasya could pass to Kate.


Sample TestCase 1
Input
003512
021
Output
30021

Sample TestCase 2
Input
79436
37
Output
3769

Sample TestCase 3
Input 
399876729
396
Output
23967799

Sample TestCase 4
Input
365289
38
Output
23869

*/

#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

//class to identify the actual number sent 
class MagicalNumber {
    //no is the jumbled number 
    //rem is the substring of the remembered number
    string no, rem;
    //num is the list of the number
    // r is the list of numbers rememered by the sender 
    // res is the resultant list/number 
    list<int> num, r, res;
    

    //remove the length of the number that was appended before sending 
    void removeStringLength(int len) {
        int strlen = len;
        while (len!=0) {
            int x = len % 10;
            list<int> ::iterator it;
            for (it = num.begin(); it != num.end(); it++) {
                if (x == (*it)) {
                    num.erase(it);
                    break;
                }
            }
            len = len / 10;
        }
    }

    //assigning the num list the jumbled numbers
    void assignNumber() {
        int len = no.length();
        int temp;
        for (int i = 0; i < len; i++) {
            temp = int(no[i]) - int('0');
            num.push_back(temp);
        }
        len--;
        //cout <<"\n Length: "<< len<<endl;
        num.sort();
        //cout << "Displaying the num list: ";
        //printNum();
        //cout << "\nRemoving the size of the string : ";
        removeStringLength(len);
        //cout << "Displaying the num list: ";
        //printNum();
    }

    /*
    void printNum() {
        list<int> ::iterator it;
        for (it = num.begin(); it != num.end(); it++) {
            cout << *it << "  ";
        }
    }*/

    //removing the rememered string from num and assigning to the r list
    void removeRemebernumber() {
        for (int i = 0; rem[i] != '\0'; i++) {
            list<int> ::iterator it;
            int x = int(rem[i]) - int('0');
            r.push_back(x);
            for (it = num.begin(); it != num.end(); it++) {
                if (x == (*it)) {
                    num.erase(it);
                    break;
                }
            }
        }
    }
    /*
    void printR() {
        list<int> ::iterator it;
        for (it = r.begin(); it != r.end(); it++) {
            cout << *it << " ";
        }
    }
    */

    //assigning remembered numbers to res list
    void assignRemember() {
        list<int> ::iterator p;
        for (p = r.begin(); p != r.end(); p++) {
            res.push_back(*p);
        }
    }
  
    //compare the num list value to the initial value of the r list
    int compareRemember(int val,int *first) {
        list<int> :: iterator p;
        p=r.begin();
        if (val == (*p)) {
            //cout << "\nValue is equal to remember beginning ";
            p++;
            if (val > (*p)) {
                //cout << "\nValue is equal to remember next to beginning ";
                assignRemember();
                return 1;
            }
        }
        else if (val > (*p) && (*p) != 0 && *first!=-1) {
            assignRemember();
            return 1;
        }
        else if (val > (*p) && *first==-1 && (*p) != 0) {
            assignRemember();
            *first = *p;
            return 1;
        }
        return 0;
    }
    
    //assign the first number of the res list 
    //it must not be zero at the begining 
    int assignFirst(int *first) {
        int val;
        int flag = 0;
        list<int>::iterator it;
        for (it = num.begin(); it != num.end(); it++) {
            if ((*it) == 0)continue;
            else {
                val = *it;
                flag = compareRemember(val,first);
                if (flag == 0)
                {
                    res.push_back(val);
                    num.erase(it);
                    *first = val;
                }
                break;
            }
        }
        return flag;
    }
    
    //assigning the rest of the numbers to res list 
    void assignRest(int flag,int *first) {
        list<int> ::iterator it;
        int val;
        //cout << "\nFlag = " << flag;
        if (flag == 1) {
            for (it = num.begin(); it != num.end(); it++) {
                val = *it;
                res.push_back(val);
            }
        }
        else {
            for(it = num.begin(); it != num.end();it++) {
                val = *it;
                if (flag == 0) {
                    flag = compareRemember(val,first);
                    //cout << "\nFlag after remebering: " << flag;
                }
                res.push_back(val);
            }
            if (flag == 0) {
                assignRemember();
            }
        }
    }

public:
    //getting the values of the magic number and the remebered string 
    void getStringNo() {
        //cout << "Enter string : ";
        getline(cin, no);
        //cout << "\nEnter sub-string : ";
        getline(cin, rem);
        //cout << "\nAssigning number :\n ";
        assignNumber();
        //cout << "\nRemoving remember numbers from the string : ";
        removeRemebernumber();
        //cout << "\nDisplaying the num list: ";
        //printNum();
        //cout << "\nDisplaying the r list: ";
        //printR();
    }
    
    //display the number in the res list 
    void display() {
        //cout << "\nDisplaying the result: \n";
        list<int> ::iterator it;
        for (it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
    }
    
    //creating the number using num and r list 
    void createNumber() {
        int first = -1;
        //cout << "\nAssigning the first number: ";
        int flag = assignFirst(&first);
        //cout << "\nDisplaying the num list: ";
        //printNum();
        //display();
        assignRest(flag, &first);
    }
};

int main()
{
    MagicalNumber no;
    no.getStringNo();
    no.createNumber();
    no.display();
}



