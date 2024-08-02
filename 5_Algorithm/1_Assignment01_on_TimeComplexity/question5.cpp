/*
You are given two sorted arrays arr1 and arr2 in descending order. Your task is to merge these two arrays into a new array result using the merge sort technique, but Instead of merging the arrays in ascending order, you need to merge them in descending order to create the result array.
	 
You cannot use stl sort function here
Marks: 20



Sample Input
Sample Output
4
8 6 4 2	
4
7 5 3 1
8 7 6 5 4 3 2 1

*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5+7;
int nums[N];
vector<int>v1(1000),v2(1000);

vector<int> mergeTwoVector(vector<int>&v1,vector<int>&v2){
    int i=0,j=0,k=0;
    vector<int>v3(v1.size()+v2.size());
    int lp = 0,rp=0;
    for(int i=0,j=0;i<v1.size(),j<v2.size();){
        if(v1[i] >= v2[j]){
            v3[k] = v1[i];
            i++;}
            else{
                v3[k] = v2[j];
                j++;
            }
            k++;
    }
    return v3;
}
int32_t main(){
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
    vector<int>v3= mergeTwoVector(v1,v2);
    for(int i=0;i<n+m;i++){
        cout<<v3[i]<<" ";
    }
    
    return 0;
}