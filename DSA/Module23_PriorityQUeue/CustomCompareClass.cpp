#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int roll;
    int marks;
    Student(string name,int roll,int marks){
        this->name=name;
        this->roll=roll;
        this->marks=marks;
    }
};
class cmp{
    public:
    bool operator()(Student a,Student b){
        return a.roll>b.roll;
}
};

int32_t main(){
    int n;
    cin>>n;
    priority_queue<Student,vector<Student>,cmp>pq;
    while(n--){
        string name;int roll, marks;
        cin>>name>>roll>>marks;
        Student obj(name,roll,marks);
        
        pq.push(obj);
    }
    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
    
}
