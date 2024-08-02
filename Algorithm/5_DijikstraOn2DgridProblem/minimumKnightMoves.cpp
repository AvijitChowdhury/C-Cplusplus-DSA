/*
Anjali and Nakul are good friends. They both had a quarrel recently while playing chess. Nakul wants to know the minimum number of moves a knight takes to reach from one square to another square of a chess board (8 × 8). Nakul is brilliant and he had already written a program to solve the problem. Nakul wants to know whether Anjali can do it. Anjali is very weak in programming. Help her to solve the problem.

A knight can move in the shape of an "L" in a chessboard - two squares either forward, backward, left, or right and then one square to its left or right. A knight move is valid if it moves as mentioned above and it is within the boundary of the chessboard (8 × 8).

knight

Input
There are T test cases in total. The next T lines contain two strings (start and destination) separated by a space.

The strings start and destination will only contain two characters - First character is an alphabet between 'a' and 'h' (inclusive), Second character is a digit between '1' and '8' (inclusive) - (Quotes just for clarity).

To know the knight moves more clearly refer to the above figure.

Output
Print the minimum number of moves a knight takes to reach from start to destination in a separate line.

Constraints
1 <= T <= 4096
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
using namespace std;
#define pii pair<int,int>
const int N = 1e3+5;
pii parent[N][N];
int visited[N][N];
int level[N][N];
bool isValid(int i,int j){
    return (i>=1&&i<=8&&j>=1&&j<=8);
}
void bfs(int start,int end){
    queue<pii>q;
    q.push({start,end});
    
    visited[start][end] = 1;
    level[start][end] = 0;
    vector<pii>direc = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    while(!q.empty()){
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();
        for(auto d: direc){
            int ni = i+d.first;
            int nj = j+d.second;
            if(isValid(ni,nj)&&!visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj] = 1;
                parent[ni][nj] = {i,j};
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
    

}
void reset_level_vis(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

int main(){
    int n=8,m=8;
    int t;
    cin>>t;
    while(t--){
        string start,end;
        cin>>start>>end;
        int si = start[0]-'a';
        int sj = start[1]-'1';
        int di = end[0]-'a';
        int dj = end[1]-'1';
        bfs(si+1,sj+1);
        cout<<level[di+1][dj+1]<<endl;
        reset_level_vis();
    }



}