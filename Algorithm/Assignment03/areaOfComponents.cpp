/*
You will be given a 2D matrix of size  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1*/
/*
You will be given a 2D matrix of size  which will contain only dot() and minus() where dot() means you can go in that cell and minus() means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of two cells - (,) and (,). You need to tell if these  and  cells are in the same component or not. Same component means you can go from  to .

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Next line will contain  and .
Last line will contain  and .
Constraints

Output Format

Output "YES" if those cell are in the same component, "NO" otherwise.
Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0

NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1

YES*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n,m;
vector<vector<char>> adj(N, vector<char>(N));
bool visited[N][N]={false};
int cnt=0;
void dfsMatrix(int i,int j){
    visited[i][j] = true;
    cnt++;
    if(i>0&&adj[i-1][j]=='.'&&!visited[i-1][j]){
        dfsMatrix(i-1,j);
    }
    if(i<n-1&&adj[i+1][j]=='.'&&!visited[i+1][j]){
        dfsMatrix(i+1,j);
    }
    if(j>0&&adj[i][j-1]=='.'&&!visited[i][j-1]){
        dfsMatrix(i,j-1);
    }
    if(j<m-1&&adj[i][j+1]=='.'&&!visited[i][j+1]){
        dfsMatrix(i,j+1);
    }
    
}
int32_t main(){
    
   cin>>n>>m;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>adj[i][j];
    }
   }
   int minArea = INT_MAX;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cnt=0;
        if(adj[i][j]=='.'&&!visited[i][j]){
            cnt=0;
            dfsMatrix(i,j);
            minArea = min(minArea,cnt);
        }
    }
   }
    if(minArea==INT_MAX){
         cout<<-1<<endl;
    }
    else{
        cout<<minArea<<endl;
    }
}