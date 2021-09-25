// Dijkstra algo
//Steps:
//1. Adj List
//2. isVisited and minDist
//3. dijkstraAlgo

import java.util.*;

public class ShortestPathLength{
    static void createAdjList(ArrayList<LinkedList<Integer>> adjList,int[][] graph,int startNode){
        LinkedList<Integer> tempList = new LinkedList<Integer>();
        for(int j=0;j<graph.length;j++){
            if(graph[startNode][j]!=0){
                tempList.add(0,j);
            }
        }
        adjList.add(tempList);
    }
    
    static void initIsVisited(boolean[] isVisited,int V){
        isVisited[0]=true;
        for(int i=1;i<V;i++){
            isVisited[i]=false;
        }
    }
    
    static void displayIsVisited(boolean[] isVisited,int V){
        for(int i=0;i<V;i++){
            System.out.print(isVisited[i]+" ");
        }
        System.out.println();
    }
    
    static void initMinDist(int[] minDist,int V){
        minDist[0]=0;
        for(int i=1;i<V;i++){
            minDist[i]=Integer.MAX_VALUE;
        }
    }
    
    static void displayMinDist(int[] minDist,int V){
        for(int i=0;i<V;i++){
            System.out.println(i+" "+minDist[i]+" ");
        }
        System.out.println();
    }
    
    static void dijkstraAlgo(ArrayList<LinkedList<Integer>> adjList,int[] minDist,boolean[] isVisited,int V,int[][] graph){
        int min,nextNode=0;
        for(int i=0;i<V-1;i++){
            min=Integer.MAX_VALUE;

            // check is visited array
            for(int j=0;j<V;j++){
                if(isVisited[j]==true){
                    //assigning not visited nodes the min value 
                    for(int k=0;k<adjList.get(j).size();k++){
                        if(isVisited[adjList.get(j).get(k)]==false){
                            if(minDist[adjList.get(j).get(k)]>(minDist[j]+graph[j][adjList.get(j).get(k)]))
                            minDist[adjList.get(j).get(k)] = minDist[j]+graph[j][adjList.get(j).get(k)];
                        }
                    }
                }
            }
            //find next min distance
            for(int j=0;j<V;j++){
                    if(isVisited[j]==false && min>minDist[j]){
                        nextNode = j;
                        min = minDist[j];
                    }
            }
            
            //System.out.println(" NextNode: "+nextNode+" Min: "+min);
            //making the node visited
            isVisited[nextNode] = true;
            //System.out.println("MinDistance: "+minDist[nextNode]+"\n");
        }
    }
    
    public static void main(String[] args){
        
        int V =9;
        int graph[][]= new int[][]{
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
        };
        
        //adjacency List
        ArrayList<LinkedList<Integer>> adjList = new ArrayList<LinkedList<Integer>>(V);
        for(int i=0;i<V;i++)
            createAdjList(adjList,graph,i);
        
        /*
        for(LinkedList ls : adjList){
            System.out.println(ls);
        }
        */
        
        //isVisited
        boolean isVisited[] = new boolean[V];
        initIsVisited(isVisited,V);
        //displayIsVisited(isVisited,V);
        
        //minDist
        int minDist[] = new int[V];
        initMinDist(minDist,V);
        //displayMinDist(minDist,V);
        
        //perform dijkstraAlgo
        dijkstraAlgo(adjList,minDist,isVisited,V,graph);
        
        //displayIsVisited(isVisited,V);
        displayMinDist(minDist,V);
    }
}

