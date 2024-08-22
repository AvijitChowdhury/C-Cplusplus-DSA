"""
link: https://atcoder.jp/contests/arc087/submissions/me
Time Limit: 2 sec / Memory Limit: 256 MB

Score : 
300 points

Problem Statement
You are given a sequence of positive integers of length 
N, 
a=(a 
1
​
 ,a 
2
​
 ,...,a 
N
​
 ). Your objective is to remove some of the elements in 
a so that 
a will be a good sequence.

Here, an sequence 
b is a good sequence when the following condition holds true:

For each element 
x in 
b, the value 
x occurs exactly 
x times in 
b.
For example, 
(3,3,3), 
(4,2,4,1,4,2,4) and 
() (an empty sequence) are good sequences, while 
(3,3,3,3) and 
(2,4,1,4,2) are not.

Find the minimum number of elements that needs to be removed so that 
a will be a good sequence.

Constraints
1≤N≤10 
5
 
a 
i
​
  is an integer.
1≤a 
i
​
 ≤10 
9
 
Input
Input is given from Standard Input in the following format:

N
a 
1
​
  
a 
2
​
  
... 
a 
N
​
 
Output
Print the minimum number of elements that needs to be removed so that 
a will be a good sequence.

Sample Input 1
Copy
4
3 3 3 3
Sample Output 1
Copy
1
We can, for example, remove one occurrence of 
3. Then, 
(3,3,3) is a good sequence.

Sample Input 2
Copy
5
2 4 1 4 2
Sample Output 2
Copy
2
We can, for example, remove two occurrences of 
4. Then, 
(2,1,2) is a good sequence.

Sample Input 3
Copy
6
1 2 2 3 3 3
Sample Output 3
Copy
0
Sample Input 4
Copy
1
1000000000
Sample Output 4
Copy
1
Remove one occurrence of 
10 
9
 . Then, 
() is a good sequence.

Sample Input 5
Copy
8
2 7 1 8 2 8 1 8
Sample Output 5
Copy
5
"""
n=int(input())
a=list(map(int,input().split()))
a.sort()
mp={}
for i in a:
    if i in mp:
        mp[i]+=1
    else:
        mp[i]=1
#iterate over the dictionary
ans=0
for i in mp:
    if mp[i]>i:
        ans+=mp[i]-i
    elif mp[i]<i:
        ans+=mp[i]
print(ans)
