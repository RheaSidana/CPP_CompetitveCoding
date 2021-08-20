/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example

s= 12:01:00PM
Return '12:01:00'.

s= 12:01:00AM
Return '00:01:00'.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

string s: a time in 12 hour format
Returns

string: the time in 24 hour format
Input Format

A single string s that represents a time in 12-hour clock format (i.e.: hh:mm:ssAM  or hh:mm:ssPM).

Constraints

All input times are valid
Sample Input

07:05:45PM
Sample Output

19:05:45
*/


using System.CodeDom.Compiler;
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
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string timeConversion(string s)
    {
        string[] str = s.Split(':');
        int hr=Convert.ToInt32(str[0]);
        if(str[2].Contains('P')){
            string[] str3 = str[2].Split('P');
            if(hr!=12)
            hr+=12;
            str[0]=hr.ToString();
            str[2]=str3[0];
        }
        else{
            string[] str3 = str[2].Split('A');
            if(hr==12){
                str[0]="00";
            }
            str[2]=str3[0];
        }
        //Console.WriteLine("{0}:{1}:{2}",hr,str[1],str[2]);
        string res = str[0]+":"+str[1]+":"+str[2];
        return res;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.timeConversion(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
