using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class CandidateCode {
    static int calDist(ref int Mrow,ref int Mcol, ref int row, ref int col){
        int rowDiff=0,colDiff=0,dist;
        if(Mrow>row)rowDiff=Mrow-row;
        else if(Mrow<row)rowDiff=row-Mrow;
        if(Mcol<4 && col<4)colDiff=0;
        else if(Mcol>=4 && col>=4)colDiff=0;
        else colDiff=2;
        dist=rowDiff+colDiff;
        return dist;
    }

    static void Main(String[] args) {
	    //Write code here
        int N;
        N = Convert.ToInt32(Console.ReadLine());
        string str;
        char[,] mat = new char[N,8];
        int Mrow=0,Mcol=0,min=0,dist;
        for(int i=0;i<N;i++){
            str=Console.ReadLine();
            int j=0;
            foreach(char c in str){
                if(c==' ')continue;
                if(c=='M'){Mrow=i;Mcol=j;}
                mat[i,j]=c;
                j++;
            }
        }
        /*
        if(Mcol!=0 && mat[Mrow,(Mcol-1)] == 'V')min=0;
        else if(Mcol!=7 && mat[Mrow,(Mcol+1)] == 'V')min=0;
        else if(Mrow!=0 && mat[(Mrow-1),Mcol] == 'V')min=1;
        else if(mat[(Mrow+1),Mcol] == 'V')min=1;
        else if(Mrow!=0 && Mcol!=0 && mat[(Mrow-1),(Mcol-1)] == 'V')min=1;
        else if(Mrow!=0 && Mcol!=7 && mat[(Mrow-1),(Mcol+1)] == 'V')min=1;
        else if(Mrow!=(N-1) && Mcol!=0 && mat[(Mrow+1),(Mcol-1)] == 'V')min=1;
        else if(Mrow!=(N-1) && Mcol!=7 && mat[(Mrow-1),(Mcol+1)] == 'V')min=1;
        else*/
        for(int i=0;i<N;i++){
            for(int j=0;j<8;j++){
                if(mat[i,j]=='V'){
                    if(min==0){
                        min=calDist(ref Mrow,ref Mcol,ref i,ref j);
                    }
                    else{
                        dist=calDist(ref Mrow,ref Mcol,ref i,ref j);
                        if(min>dist)min=dist;
                    }
                }
            }
        }
        Console.WriteLine(min);
    }
}
