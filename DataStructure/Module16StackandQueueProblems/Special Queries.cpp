/*
Problem Statement

You will be given  queries. In each query you will get a command. The command is of two types -

You will be given  and  of a person who stood in a line of a ticket counter.
You will be given only  which means the person in front of the line got the ticket and will be removed from the line. You need to print the name of that person who got that ticket. If there are no one in the line, print .
Note: There can be multiple person in the line with same name.

Input Format

First line will contain .
Next  lines will contain the commands.
Constraints

. Here |Name| means the length of the string and it will not contain any space. The string will contain only small English alphabets.
Output Format

For each time someone get out of the line, print his/her name. Print a new line after that.
Sample Input 0

5
0 rahim
0 karim
1
0 sakib
1
Sample Output 0

rahim
karim
Sample Input 1

8
1
0 embappe
0 neymar
1 
1
0 messi
1
1
Sample Output 1

Invalid
embappe
neymar
messi
Invalid
Sample Input 2

6
0 embappe
0 embappe
1 
1
0 messi
1
Sample Output 2

embappe
embappe
messi*/
#include <bits/stdc++.h>

#include <queue>
#include <string>

using namespace std;
void code(){
  int Q;
  cin >> Q;
  queue<string> qu;
  for (int i = 0; i < Q; i++) {
    int query;
    string name;
    cin >> query;

    if (query == 0) {
      cin >> name;
      qu.push(name);
    } else if (query == 1) {
      if (qu.empty()) {
        cout << "Invalid\n";
      } else {
        cout << qu.front() << endl;
        qu.pop();
      }
    } else {
      cout << "Invalid"<<endl;
    }
  }
}
int main() {
  
  code();
  return 0;
}