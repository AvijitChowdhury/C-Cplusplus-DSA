#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;


vector<int> insertInHeap(vector<int> arr, int n, int key){
    n = n+1;
    arr.push_back(key);
    int i = n-1;
    int currentIndex = i;
    int parentIndex = (currentIndex-1)/2;
    while(currentIndex!=0){
         parentIndex = (currentIndex-1)/2;
        if(arr[parentIndex] < arr[currentIndex]){
           
            swap(arr[parentIndex], arr[currentIndex]);
            currentIndex = parentIndex;//cus
        }
}
return arr;
}
int32_t main(){
    int arr[]={10, 5, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 15;
    vector<int> v(arr,arr+n);
    vector<int> v1= insertInHeap(v, n, key);
    for(auto it : v1){
        cout<<it<<" ";
    }
    return 0;
}