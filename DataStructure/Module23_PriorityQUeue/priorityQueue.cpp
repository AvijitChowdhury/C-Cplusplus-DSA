#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<int>> pq;//min heap
    //priority_queue<int> pq; //max heap

    while (true) {
        int x;
        cin >> x;

        if (x == 0) {
            int c;
            cin >> c;
            pq.push(c);
        } else if (x == 1) {
            if (pq.empty()) {
                //cout << "Error: priority_queue is empty\n"; // Handle empty queue for pop
            } else {
                pq.pop();
            }
        } else if (x == 2) {
            if (pq.empty()) {
                //cout << "Error: priority_queue is empty\n"; // Handle empty queue for top
            } else {
                //cout << pq.top() << endl;
            }
        } else {
            break;
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}

/*
input: 
1
0 5
1
2
0 8
2
3
*/