/*
Question: Write a C++ program that takes N integer numbers that are sorted and distinct. The next line will contain an integer k. You need to tell whether K exists in that array or not. If it exists, print its index otherwise print “Not Found”. 	
You must solve this in O(logn) complexity.
Marks: 20



Sample Input
Sample Output
8
-4 0 2 6 9 10 29 54
29
6
10
0 1 2 3 4 5 6 7 8 9
-3
Not Found

*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5+7;
int searchk(vector<int>v,int l,int r,int k){
    if(l>r){return -1;}
    int mid = (l+r)/2;
    if(v[mid]==k){
        return mid;
    }
    
    if(v[mid]>k){return searchk(v,l,mid-1,k);}
    else{return searchk(v,mid+1,r,k);}
    
}
int32_t main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;cin>>k;
    if(searchk(v,0,n-1,k)==-1){
        cout<<"Not Found";
    }else{
        cout<<searchk(v,0,n-1,k);
    };
    
    return 0;
}