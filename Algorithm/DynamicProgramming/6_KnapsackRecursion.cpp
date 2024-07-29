#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&value,vector<int>&weight,int n, int w){
    if(n==0||w==0){
        return 0;
    }

    if(weight[n-1]<=w){
       return max(value[n-1]+knapsack(value,weight,n-1,w-weight[n-1]),knapsack(value,weight,n-1,w));
    }
    
    return knapsack(value,weight,n-1,w);


}

int32_t main(){
    int n;
    cin>>n;
    vector<int> value(n);
    vector<int>weight(n);
    
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int w;
    cin>>w;
    cout<<knapsack(value,weight,n,w);   

}