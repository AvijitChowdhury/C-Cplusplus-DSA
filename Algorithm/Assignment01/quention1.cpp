/*
Write a C++ program that takes N integer numbers and sorts them in non-increasing order using Merge Sort. 
You can’t use any built-in function for sorting.	
Marks: 20

Sample Input
Sample Output
7
1 2 9 4 0 2 5
9 5 4 2 2 1 0
6
5 3 -1 3 3 8
8 5 3 3 3 -1

*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5+7;
int nums[N];


void merge(int l,int mid, int r){
//    if(l>=r){return;}
    int n1 = mid-l+1;
    int n2 = r-mid; 
    int left[n1 + 1],right[n2+1];
    for(int i=l,j=0;i<=mid; i++,j++){
        left[j] = nums[i];
    }//left sorted array
    for(int i=mid+1,j=0;i<=r;i++,j++){
        right[j] = nums[i];
    }//right sorted array

    left[n1] = INT_MAX;//infinity
    right[n2] = INT_MAX;//infinity

    int lp = 0,rp=0;
    for(int i=l;i<=r ;i++){
        if(left[lp] <= right[rp]){
            nums[i] = left[lp];
            lp++;}
            else{
                nums[i] = right[rp];
                rp++;
            }
    }//merge the two sorted arrays using two pointers

}
void reverse(int start, int end){
    while(start<end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void mergesort(int l,int r){
    
    if(l>=r){return;}
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}
int32_t main(){
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    mergesort(0,n-1);
    reverse(0,n-1);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}