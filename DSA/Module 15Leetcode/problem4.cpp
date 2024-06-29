/*problem link; https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571
Given three filled stacks namely ‘stack1’ ‘stack2’ and ‘stack3’ of positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed.

For example, let the stacks be:


We can see that currently,

the sum of stack 1 is: 8+5+3 = 16

the sum of stack 2 is: 2+2+4+9+6 = 23

the sum of stack 3 is: 2+1+2+3 = 8

So they are not equal.

However, if we pop {8} from stack 1, {6,9} from stack 2 and nothing from stack 3,

We get the sum as :

Stack 1: 16-8=8

Stack 2: 23-15=8

Stack 3: 8-0=8

We can see that now the sum of all three stacks are equal which is 8 and it is the highest possible, hence we return 8.

Note:
1. Do not print anything, just return an integer which is the maximum possible sum for the three stacks.
2.It is guaranteed that the elements in the stack are positive integers.
3.It can be proved that a non-negative integer answer always exists.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1<= N <=10^4
1<= stackData <=10^9

Where ‘T’ is the total number of test cases, ‘N’ denotes the number of elements in any of the stacks and ‘stackData’ represents the data in the stacks.
Time limit: 1 second
Sample Input 1:
2
2 4 1 9 -1
1 6 3 -1
5 2 1 -1
8 2 1 -1 
1 1 1 -1 
6 3 -1
Sample Output 1:
7
0 
Explanation of sample input 1 :
Test Case 1:
The stacks are:

We can see that currently,
the sum of stack 1 is:9+1+4+2=16
the sum of stack 2 is: 3+6+1=10
the sum of stack 3 is: 5+2+1=8

So they are not equal.
However, if we pop {9,1} from stack 1 {3} from stack 2 and {1} from stack 3,

We get the sum as :

Stack 1: 16-9-1=7
Stack 2: 10-3=7
Stack 3: 8-1=7

We can see that now the sum of all 3 stacks are equal which is 7 and it is the highest possible, hence we return 7.

Test Case 2: 

We can see that currently,
the sum of stack 1 is: 6+3=9
the sum of stack 2 is: 1+1+1=3
the sum of stack 3 is: 1+2+8=11

So they are not equal.

Now, no matter what we do we can never make the sum equal to any number for all the three stacks except 0. So, in this case, we return 0.
Sample Input 2:
2
2 2 4 6 -1
14 6 8 1 -1
7 7 6 4 -1
9 9 9 9 -1
20 7 -1
5 6 7 9 -1
Sample Output 2:
14
27
*/
#include <bits/stdc++.h> 
int Sum(stack<int> st){
    int x=0;
    while(!st.empty()){
        x+=st.top();
    }
    return x;
}
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3) {
    // Write your code here
    int sum1 = Sum(stk1);
    int sum2 = Sum(stk2);
    int sum3 = Sum(stk3);
    while(true){
        if(sum1==sum2 && sum2==sum3){
            break;
        }
        if(sum1>=sum2 && sum1>=sum3){
            sum1 -= stk1.top();
            stk1.top();
        }
        else if(sum2>=sum1 && sum2 >=sum3){
            sum2 -= stk2.top();
            stk2.pop();
        }else{
            sum3 -= stk3.top();
            stk3.pop();
        }
    }
    return sum1;
}