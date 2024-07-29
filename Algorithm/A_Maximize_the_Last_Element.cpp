#include<bits/stdc++.h>
using namespace std;
#define int long long
void code(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(i%2==0&&a[i]>mx){
            mx=a[i];
        }
        
    }
  cout<<mx<<endl;
    
}
int32_t main(){
    int t;
    cin >> t; // Initialize 't' with a value
    while(t--){
        code();
    }

}