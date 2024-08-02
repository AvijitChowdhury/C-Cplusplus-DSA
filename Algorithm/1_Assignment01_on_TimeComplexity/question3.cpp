/*
You are given an array of N positive integers. The next line will contain an integer K. You need to tell whether there exists more than one occurrence of K in that array or not. If there exists more than one occurrence of K print YES, Otherwise print NO.
See the sample input-output for more clarification.
The given array will be sorted in increasing order. And it is guaranteed that at least one occurrence of K will exist.	 You must solve this in O(logn) complexity.
Marks: 20



Sample Input
Sample Output
7
1 3 4 6 6 9 17		
6
YES
10
0 1 2 3 4 5 6 7 8 9
3
NO

*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5+7;
int searchkFirst(vector<int>v,int l,int r,int k){
    if(l>r){return -1;}
    int mid = (l+r)/2;
    if(v[mid]==k){ 
        if (mid == 0 || v[mid - 1] != k) {
            return mid;
        } else {
            return searchkFirst(v, l, mid - 1, k);
        }       
        
    }
    
    if(v[mid]>k){return searchkFirst(v,l,mid-1,k);}
    else{return searchkFirst(v,mid+1,r,k);}
    
}
int searchkLast(vector<int>v,int l,int r,int k){
    if(l>r){return -1;}
    int mid = (l+r)/2;
    if(v[mid]==k){ 
        if (mid == v.size()-1 || v[mid + 1] != k) {
            return mid;
        } else {
            return searchkLast(v, mid+1, r, k);
        }       
        
    }
    
    if(v[mid]>k){return searchkLast(v,l,mid-1,k);}
    else{return searchkLast(v,mid+1,r,k);}
    
}
int32_t main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;cin>>k;
    
    if(searchkFirst(v,0,n-1,k)!=searchkLast(v,0,n-1,k)){
        cout<<"YES";
    }else{
        cout<<"NO";
    };
    
    return 0;
}