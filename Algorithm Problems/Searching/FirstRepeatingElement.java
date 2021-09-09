/*
First repeating element (80 Marks)
Given an array of integers, find the first repeating element in it. We need to find the element that occurs more than once and whose index of first occurrence is smallest.


Input Format
You will be given a function with an integer array as arguments.


Constraints
1 < N < 10^5
1 < a[i] < 10^5


Output Format
You need to return the first repeating element from the function.


Sample TestCase 1
Input
7
10
5
3
4
3
5
6
Output
5
*/

/* 
 * Enter your code here. Read input from STDIN. Print your output to STDOUT. 
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class CandidateCode {
    public static void main(String args[] ) throws Exception {
        Scanner in= new Scanner(System.in);
        Vector<Integer> v = new Vector<Integer>();
        int n,i=0;
        n=in.nextInt();
        in.nextLine();
        int val=-1;
        while(i<n){
            val=in.nextInt();
            v.add(val);
            i++;
        }
        for(int no: v){
            int first=v.indexOf(no);
            int last=v.lastIndexOf(no);
            if(last!=first){
                val=no;
                break;
            }
        }
        System.out.print(val);
   }
}
