
#include <iostream>
#include<bits/stdc++.h>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

#define n 6


bool bfs(int rGraph[n][n],int s, int t, int parent[]){
    bool visited[n];
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v<n;v++){
            if(visited[v]==0&&rGraph[u][v]>0){
                if(v==t){
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v]=true;
            }
            
        }
    }
    return false;
}


int fordFulkerson(int graph[n][n],int s,int t,int &count){
    int u,v;
    int rGraph[n][n];
    for (u=0;u<n;u++){
        for(v=0;v<n;v++){
            rGraph[u][v]=graph[u][v];
        }
    }
    int parent[n];
    int maxFlow = 0;
    while(bfs(rGraph,s,t,parent)){
        int pathFlow = INT_MAX;
        for(v = t; v!=s; v= parent[v]){
            u = parent[v];
            pathFlow = min(pathFlow,rGraph[u][v]);
            count++;
        }
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
            count++;
        }
        maxFlow+=pathFlow;
    }
    return maxFlow;
}


int main()
{
    int graph[n][n]
		= {
		    {0,1000000,1000000,0},
		    {0,0,1,0},
		    {0,0,0,0},
		    {0,1000000,1000000,0}
		};
		
		
// 		{
// 		    {0,10,0,8,0,0},
// 		    {0,0,5,2,0,0},
// 		    {0,0,0,0,0,7},
// 		    {0,0,0,0,10,0},
// 		    {0,0,8,0,0,10},
// 		    {0,0,0,0,0,0}
// 		};
		
		int count = 0;
// 		   s  a  b  c  d  t
// 		s
// 		a
// 		b
// 		c
// 		d
// 		t
		  
		  /*
		     s  a  b  t
		  s
		  a
		  b
		  t
		  */
		  
// 		  { { 0, 3, 2, 0 },
// 		    { 0, 0, 5, 2 },
// 			{ 0, 0, 0, 3 },
// 			{ 0, 0, 0, 0 }
// 		  };
		  
// 		  { { 0, 16, 13, 0, 0, 0 },
// 		    { 0, 0, 10, 12, 0, 0 },
// 			{ 0, 4, 0, 0, 14, 0 },
// 			{ 0, 0, 9, 0, 0, 20 },
// 			{ 0, 0, 0, 7, 0, 4 },
// 			{ 0, 0, 0, 0, 0, 0 }
//		  };

	cout << "Max flow : "<< fordFulkerson(graph, 0, 3,count);
    cout << endl << count;
	return 0;
    
}
