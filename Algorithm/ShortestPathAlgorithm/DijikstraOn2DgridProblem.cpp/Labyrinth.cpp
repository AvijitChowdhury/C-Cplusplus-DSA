/*
You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 1e3+5;
vector<string>g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
int n,m;
vector<pii> direc={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i, int j){
    return (i>=0&&i<n &&j>=0&&j<m);
}

void bfs(int si,int sj){
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj] = 1;
    level[si][sj] = 0;
    while(!q.empty()){
        pii upair = q.front();
        int i= upair.first;
        int j = upair.second;
        q.pop();
        for(auto d: direc){
            int ni = i+d.first;
            int nj = j+d.second;
            if(isValid(ni,nj)&&!visited[ni][nj]&&g[ni][nj]!='#'){
                q.push({ni,nj});
                visited[ni][nj] = 1;
                parent[ni][nj] = {i,j};
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
int32_t main(){
    int si,sj,di,dj;
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
        for(int j=0;j<m;j++){
            if(g[i][j]=='A'){
                si = i;
                sj = j;
            }
            if(g[i][j]=='B'){
                di = i;
                dj = j;
            }
        }
        }
        bfs(si,sj);
        if(level[di][dj]==0){
            cout<<"NO"<<endl;
            return 0;
        }else{
            cout<<"YES"<<endl;
            cout<<level[di][dj]<<endl;
            
           
        }
        vector<pii>path;
        pii current = {di,dj};
        while(!(current.first==si&&current.second==sj)){
            path.push_back(current);
            current = parent[current.first][current.second];
        }
        path.push_back({si,sj});//inserting the start point
        reverse(path.begin(),path.end());
        for(int i=1;i<path.size();i++){
            //path[i-1] -> path[i]
            if(path[i-1].first == path[i].first){
                if(path[i-1].second == path[i].second-1){
                    cout<<"R";
                    }else{
                        cout<<"L";
                    }
            }else{
                if(path[i-1].first == path[i].first-1){
                    cout<<"D";
                }else{
                    cout<<"U";
                }
            }
        }
}


