"""link:https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S?fbclid=IwAR1qi6o8WBDOrdzcZ--U5YO_40SSQmmLbZ8jggB6CFIRqog1ukVL_Z2wK2s
S. Max Split
time limit per test1 second
memory limit per test256 megabytes
Given a balanced string S
 consists of ['R', 'L'] characters. Split it into maximum number of strings such that the new strings are also balanced.

Note:

Balanced strings are those who have equal quantities of 'L' and 'R' characters.
You can not remove or reorder the characters while making the new strings.
Input
Only one line contains a string S
 (2≤|S|≤1000)
 where |S| is the length of the string.

It's guaranteed that S
 consists of only ['L', 'R'] letters, S
 is balanced and |S|
 is even.

Output
Print maximum number of balanced strings then the balanced strings in any order.

Examples
InputCopy
LLRRLLLRRR
OutputCopy
2
LLRR
LLLRRR
InputCopy
LLLRRR
OutputCopy
1
LLLRRR
"""
s = input()
cnt = 0
splits = []
last_position = 0

for i in range(len(s)):
    if s[i] == 'L':
        cnt += 1
    elif s[i] == 'R':
        cnt -= 1
    
    if cnt == 0:
        splits.append(s[last_position:i+1])
        last_position = i + 1

print(len(splits))
for part in splits:
    print(part)
