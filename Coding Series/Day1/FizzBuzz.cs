/*
STDIN    Function
-----    --------
15    →  n = 15

Output
1     
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
*/using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;


class Result
{

    /*
     * Complete the 'fizzBuzz' function below.
     *
     * The function accepts INTEGER n as parameter.
     */

    public static void fizzBuzz(int n)
    {
        for(int i=1;i<=n;i++){
            if(i%3==0){
                Console.Write("Fizz");
            }
            if(i%5==0){
                Console.Write("Buzz");
            }
            if(i%3!=0 && i%5!=0){
                Console.Write(i);
            }
            Console.WriteLine();
        }
    }

}
class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        Result.fizzBuzz(n);
    }
}
