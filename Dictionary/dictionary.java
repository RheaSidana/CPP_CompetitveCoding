/*
Lets make a dictionary order (100 Marks)
You need to input N words one on each line and output should be 
lexicographically sorted i.e the words which comes as a output 
should be alphabetically sorted

Input Format
You will be taking an integer N from STDIN.
Following N lines contains string one on each line.

Constraints
1 < N < 10000
1 < |S| < 1000


Output Format
The words should be lexicographically sorted and should be 
displayed one per each line.

Sample TestCase 1
Input
10
fortran
java
perl
python
php
javascript
c
cpp
ruby
csharp
Output
c
cpp
csharp
fortran
java
javascript
perl
php
python
ruby
Explanation
In mathematics, the lexicographic or lexicographical 
order (also known as lexical order, dictionary order, 
alphabetical order or lexicographical product) is a 
generalization of the way the alphabetical order of 
words is based on the alphabetical order of their 
component letters.

Time Limit(X):
1.00 sec(s) for each input.
Memory Limit:
512 MB
Source Limit:
100 KB

*/

/* 
 * Enter your code here. Read input from STDIN. Print your output to STDOUT. 
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class CandidateCode {
    public static void main(String args[] ) throws Exception {
        Scanner in = new Scanner(System.in);
        TreeSet<String> hs = new TreeSet<String>();
        String s;
        int n;
        n=in.nextInt();
        in.nextLine();
        for(int i=0;i<n;i++){
            s=in.nextLine();
            hs.add(s);
        }
        for(String str : hs){
            System.out.println(str);
        }
   }
}
