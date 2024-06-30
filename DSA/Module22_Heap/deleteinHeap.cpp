#include<bits/stdc++.h>
using namespace std;

void deleteInHeap(vector<int>&v,int size, int key){
    int i;
    for(i=0;i<size;i++){
        if(v[i]==key){
            break;
        }
    }
    swap(v[i],v[size-1]);
    v.pop_back();
    size--;
    int parentIndex = (i-1)/2;
    while(i>0 && v[parentIndex]<v[i]){
        swap(v[parentIndex],v[i]);
        i = parentIndex;
        parentIndex = (i-1)/2;
    }
    for(auto it : v){
        cout<<it<<" ";
    }

}
void deleteLastElement(vector<int>&v,int size){
    v.pop_back();
    size--;
    int i = 0;
    int Left_idx = 2*i+1;
    int right_idx = 2*i+2;
    while(true){
        if(Left_idx<size && right_idx<size){
            if(v[i]<v[Left_idx] && v[i]<v[right_idx]){
                if(v[Left_idx]>v[right_idx]){
                    swap(v[i],v[Left_idx]);
                    i = Left_idx;
                }
                else{
                    swap(v[i],v[right_idx]);
                    i = right_idx;
                }
            }
            else if(v[i]<v[Left_idx]){
                swap(v[i],v[Left_idx]);
                i = Left_idx;
            }
            else if(v[i]<v[right_idx]){
                swap(v[i],v[right_idx]);
                i = right_idx;
            }
            else{
                break;
            }
            Left_idx = 2*i+1;
            right_idx = 2*i+2;
        }
        else if(Left_idx<size){
            if(v[i]<v[Left_idx]){
                swap(v[i],v[Left_idx]);
                i = Left_idx;
            }
            else{
                break;
            }
            Left_idx = 2*i+1;
            right_idx = 2*i+2;
        }
        else{
            break;
        }
    
    }
}
int32_t main(){
    vector<int> v{10, 5, 3, 2, 4};


    deleteInHeap(v,v.size(), 3);
    // for(auto it : v){
    //     cout<<it<<" ";
    // }
}