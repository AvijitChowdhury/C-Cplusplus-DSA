/*
You will be given a chessboard of  size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell  ( and ), and the queen's cell  ( and ). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below:image

Input Format

First line will contain , the number of test cases.
First line of each test case will contain  and .
Second line of each test case will contain  and .
Third line of each test case will contain  and .
Constraints

Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print .
Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
const int N = 100;
int visited[N][N];
int level[N][N];
int n,m;
bool isValid(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}
void bfs(int start, int end, int qi, int qj){
    visited[start][end] = 1;
    level[start][end] = 0;
    queue<pii>q;
    q.push({start,end});
    vector<pii>direc = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    while(!q.empty()){
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;

        q.pop();
        for(auto d: direc){
            int ni = i+d.first;
            int nj=j+d.second;

            if(isValid(ni,nj)&&!visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj] = 1;
                
                level[ni][nj] = level[i][j]+1;
            }
            
        }
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        int ki,kj;
        cin>>ki>>kj;
        int qi,qj;
        cin>>qi>>qj;
        memset(visited,0,sizeof(visited));
        memset(level,-1,sizeof(level));
        bfs(ki,kj,qi,qj);
        if(level[qi][qj]==-1){
            cout<<-1<<endl;}
        else{
            cout<<level[qi][qj]<<endl;
        }
        
    }
}