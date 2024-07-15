/*
5
7
1 2 2
1 3 6
2 3 1
2 4 6
2 5 3
3 4 4
5 4 9*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+7;
const int INF = 1e9+7;
int d[N][N];
int n,m;
void dist_initialized(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }
}

int32_t main(){
    
    cin>>n>>m;
    dist_initialized();
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v] = w;
    }
    //T.C = O(n^3)
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]<INF&&d[k][j]<INF){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==INF){
                cout<<"x ";}
            else{
                cout<<d[i][j]<<" ";}
        }cout<<endl;}
        cout<<endl;
    }
