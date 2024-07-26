/*
link: https://codeforces.com/contest/25/problem/B
Phone number in Berland is a sequence of n digits. Often, to make it easier to memorize the number, it is divided into groups of two or three digits. For example, the phone number 1198733 is easier to remember as 11-987-33. Your task is to find for a given phone number any of its divisions into groups of two or three digits.

Input
The first line contains integer n (2 ≤ n ≤ 100) — amount of digits in the phone number. The second line contains n digits — the phone number to divide into groups.

Output
Output any of divisions of the given phone number into groups of two or three digits. Separate groups by single character -. If the answer is not unique, output any.

Examples
inputCopy
6
549871
outputCopy
54-98-71
inputCopy
7
1198733
outputCopy
11-987-33*/
#include <bits/stdc++.h>
using namespace std;
#define int long long




int32_t main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<char>v;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==2&&i!=n-1){
                v.push_back('-');
                cnt=0;
            }
            v.push_back(s[i]);cnt++;
            
        
    }
    for(auto it:v){
        cout<<it;
    }

    

}