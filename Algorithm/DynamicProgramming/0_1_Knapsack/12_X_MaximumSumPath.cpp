/*
*/
/*link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W*/
// There are N

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 15;
int dp[N][N];
int a[N][N];
int row,col;
int maxPath(int start,int end){ // 0 0
	if(start == row - 1 && end == col - 1){
		return a[start][end];
	} else if(start == row + 1 || end == col + 1){
		return -1000000;
	}
	int right = maxPath(start,end+1);
	int down = maxPath(start+1,end);
	return a[start][end] + max(right,down);// -100000
}


int32_t main(){
    int row,col;
    cin>>row>>col;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
   
    memset(dp,-1,sizeof(dp));
    
    cout<<maxPath(0,0)<<endl;
}