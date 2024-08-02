/*
contest lInk:https://www.hackerrank.com/contests/final-exam-a-basic-data-structures-a-batch-03/challenges/count-me-2

You will be given a sentence  that contains words with lowercase and uppercase English alphabets separated by spaces. You need to determine which word occurs the most times and also provide the count of that word.

Note: If there are multiple words that occur the most, print the first word that reaches the maximum count before others.

Input Format

First line will contain , the number of test cases.
Each test case will contain the sentence .
Constraints

, Here  means the length of .
Output Format

Output the word and the count that occurs the most.
Sample Input 0

1
Ratul loves to play football when he gets time but Ratul is not a good player so his teacher asked Ratul if he can play with him so that Ratul can progress
Sample Output 0

Ratul 4
Sample Input 1

2
ratul piyush fohad shuvo rafi piyush fohad ratul 
jony jony yes papa eating sugar no papa telling lies no papa open your mouth ha ha ha 
Sample Output 1
piyush 2
papa 3*/
#include <bits/stdc++.h>
using namespace std;

void code() {
    string sentence;
    getline(cin,sentence);
    map<string,int> mp;
    size_t pos = 0;
    
    vector<string>v;
    int index=0;
    
    // while ((pos = sentence.find(" ")) != string::npos) {
    //     word = sentence.substr(0, pos);
    //     v.push_back(word);
    //     mp[word]++;index++;
    //     sentence.erase(0, pos + 1);
    // }
    // v.push_back(sentence);
    // mp[sentence]++;  // Add the last word
    stringstream ss(sentence);
    string mostFrequent;
    int maxCount = INT_MIN;
    string word;
    
    int cnt=0;
    while(ss>>word){
        mp[word]+=1;
        v.push_back(word);
        maxCount=max(maxCount,mp[word]);
        // if(maxCount==mp[word]&&cnt==0){
        //     mostFrequent=word;
        //     cnt++;
                       
        // }
    }
    map<string,int>mpe;
    for(auto it :v){
        mpe[it]++;
        if(maxCount==mpe[it]){mostFrequent=it;break;}
    }
    cout<<mostFrequent<<" "<<maxCount<<endl;


    
    
    // set<string>maxWords;
    // for (auto it : mp) {
    //     if (it.second > maxCount) {
    //         maxCount = it.second;
    //         mostFrequent = it.first;
    //         maxWords.clear();
    //         maxWords.insert(it.first);
    //     }
    //     else if (it.second == maxCount && mostFrequent > it.first) {
    //   mostFrequent = it.first;
    // }
    
    // }
    // // for(auto it:mp){
    // //     cout<<it.first<<" "<<it.second<<endl;
    // // }
    // // for(auto it:v){
    // //     if(mp[it]==maxCount){
    // //         cout<<it<<" "<<maxCount<<endl;
    // //         break;
    // //     }
    // // }
    // cout<<mostFrequent<<" "<<maxCount<<endl;

    
    
}

int32_t main() {
    int t;
    cin >> t;
    cin.ignore();  // Ignore the newline character after reading t
    while (t--) {
        code();
    }
    return 0;
}
