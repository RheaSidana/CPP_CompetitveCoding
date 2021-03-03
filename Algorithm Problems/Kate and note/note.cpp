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

/*
Algorithm : 
step 1: sort the magical number in ascending number 
step 2: remove length of the original number from the magical number
step 3: remove the remember number "substring" 
step 4: check if both magic number and remember should not contain all zero
            if allzero 
               ans = 0
step 4: assign first number (number should be non zero)
step 5: compare the numbers from sorted list to the remember list 
step 6: if remeber list is greater than the sorted list numbers then assign remember in the end 
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
    //len is the length of the original number sent 
    void removeStringLength(int len) {
        while (len != 0) {
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
        //step 1: find the actual length of the number sent
        int len = no.length();
        int temp;
        for (int i = 0; i < len; i++) {
            temp = int(no[i]) - int('0');
            num.push_back(temp);
        }
        if (len > 10)len -= 2;
        else len--;
        //cout <<"\n Length: "<< len<<endl;

        //step 2: sort the numbers in ascending order 
        num.sort();
        //cout << "Displaying the num list: ";
        //printNum();
        //cout << "\nRemoving the size of the string : ";

        //step 3: remove the length of the string from the list
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
            //Step 1: add the remember numbers order to r list
            r.push_back(x);
            for (it = num.begin(); it != num.end(); it++) {
                if (x == (*it)) {
                    //Step 2: remove the number from the num list
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
    int compareRemember(int val, int* first) {
        list<int> ::iterator p;
        p = r.begin();
        //Step 1: if(val==(*p)) then
        //step 2: if(r[1] < val) then
        //Step 3: assign r list numbers 
        if (val == (*p)) {
            p++;
            if (val > (*p)) {
                assignRemember();
                return 1;
            }
        }
        //Step 4: if(val>r[0] && r[0]!=0 && first is assigned) then
        //Step 5: assign r list numbers
        else if (val > (*p) && (*p) != 0 && *first != -1) {
            assignRemember();
            return 1;
        }
        //Step 6: if(val>r[0] r[0]!=0 && first is not assigned) then 
        //Step 7: assign r list number 
        else if (val > (*p) && *first == -1 && (*p) != 0) {
            assignRemember();
            *first = *p;
            return 1;
        }
        return 0;
    }

    //assign the first number of the res list 
    //it must not be zero at the begining 
    int assignFirst(int* first) {
        int val;
        //flag checks if the r list number is assigned to res list or not 
        int flag = 0;
        //allzero checks if the num list only contains zero
        int allzero = 0;
        list<int>::iterator it;
        for (it = num.begin(); it != num.end(); it++) {
            if ((*it) == 0) {
                allzero = 1;
                continue;
            }
            else {
                allzero = 0;
                val = *it;
                //compare the val with r list 
                //flag = 1 :  r list numbers are assigned to res list
                //flag = 0 :  val is assigned to res list
                flag = compareRemember(val, first);
                if (flag == 0)
                {
                    res.push_back(val);
                    num.erase(it);
                    *first = val;
                }
                break;
            }
        }
        //if num list numbers are all zeros then assign r list to res list 
        if (allzero) {
            assignRemember();
            flag = 1;
        }
        return flag;
    }

    //assigning the rest of the numbers to res list 
    void assignRest(int flag, int* first) {
        list<int> ::iterator it;
        int val;
        //flag=1 : r list numbers are already assigned 
        if (flag == 1) {
            for (it = num.begin(); it != num.end(); it++) {
                val = *it;
                res.push_back(val);
            }
        }
        else {
            for (it = num.begin(); it != num.end(); it++) {
                val = *it;
                if (flag == 0) {
                    flag = compareRemember(val, first);
                    //cout << "\nFlag after remebering: " << flag;
                }
                res.push_back(val);
            }
            //if flag is still 0 
            //the numbers in the num list are all less than the r[0]
            //then only r list numbers are left to be assigned to res list
            // assign r list numbers to res 
            if (flag == 0) {
                assignRemember();
            }
        }
    }

    //check if all numbers are zero in num and r list
    int checkIfAllZero() {
        list<int> ::iterator it;
        int flag = 0;
        //checks in num list first
        for (it = num.begin(); it != num.end(); it++) {
            if (*it == 0) {
                flag = 1;
            }
            else {
                flag = 0;
                break;
            }
        }
        //flaag=1: num list contains all zero
        //then check in res list 
        if (flag != 0) {
            for (it = r.begin(); it != r.end(); it++) {
                if (*it == 0) {
                    flag = 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        //if both are all zeros then this if is executed 
        if (flag != 0)return 1;
        return 0;
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
            cout << *it;
        }
    }

    //creating the number using num and r list 
    void createNumber() {
        //check for all zeros then the res is zero
        int allZero = checkIfAllZero();
        if (allZero) {
            res.push_back(0);
            return;
        }
        int first = -1;
        //cout << "\nAssigning the first number: ";
        int flag = assignFirst(&first);
        //cout << "\nDisplaying the num list: ";
        //printNum();
        //display();

        //assigning the rest of the numbers in the res list
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



