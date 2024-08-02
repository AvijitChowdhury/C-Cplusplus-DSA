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
bool dfsMatrix(int i,int j,int endi,int endj){
    if(i<0 || i>=n || j<0 || j>=m || adj[i][j]=='-' || visited[i][j]){
        return false;
    }
    visited[i][j] = true;
    if(i==endi && j==endj){
        return true;
    }
    
    return (dfsMatrix(i-1,j,endi,endj) || dfsMatrix(i+1,j,endi,endj) || dfsMatrix(i,j-1,endi,endj) || dfsMatrix(i,j+1,endi,endj));
   
}
int32_t main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    int i,j,endi,endj;
    cin>>i>>j>>endi>>endj;
    if(dfsMatrix(i,j,endi,endj)){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
}