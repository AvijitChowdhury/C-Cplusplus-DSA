/*
Problem Statement

Arif, the magician is putting some magic colors in a box serially. But he is not providing any divider between the colors. So, the color may be mix up instantly.

There are three types of colors- Red, Green and Blue. How they could mix up is given below -

Red+Blue = Purple
Red+Green = Yellow
Blue+Green = Cyan
And there are some other problems. If two same type of colors mix up, they will vanish each other. For example if two Purple colors get together, both of them will be vanished.

Can you help the magician to get the final colors that will be in the box?

Input Format

First line will contain T, the number of test cases.
Next line will contain n, number of colors in the box.
Next line will contain n characters (R,G,B only) , first capital letter of the color.
Constraints

0 < T <= 100
0 < n <= 100
Output Format

Output the first capital letter of the colors that are saved finally. If there are no colors in the box, the output could be empty in that case.
Sample Input 0

2
3
RBG
4
RGBB
Sample Output 0

PG
Y
Sample Input 1

6
6
RGGRRG
6
RGRGRG
4
RGGR
5
RGGGR
4
RGGB
18
RBRBRBGRBRRGBGGBGB
Sample Output 1

Y
Y

YR
YC
PYPYC


*/
#include<bits/stdc++.h>
using namespace std;

char colorCheck(char a, char b)
{
    if ((a == 'R' && b == 'B') || (a == 'B' && b == 'R'))
        return 'P';
    if ((a == 'R' && b == 'G') || (a == 'G' && b == 'R'))
        return 'Y';
    if ((a == 'B' && b == 'G') || (a == 'G' && b == 'B'))
        return 'C';
    return '\0';
}
void reverse(string str)
{
    int len = str.length();
    int n = len; 
    while(n--)
        cout << str[n];
}
void code(){

        int n;
        cin >> n;
        string colors;
        cin >> colors;

        stack<char> colorStock;

        for (char color : colors)
        {
            if (!colorStock.empty())
            {
                char topColor = colorStock.top();
                if (topColor == color)
                {
                    colorStock.pop();
                }
                else
                {
                    
                    char mixedColor = colorCheck(topColor, color);
                    if (mixedColor != '\0')
                    {
                     
                        colorStock.pop();
                     
                        if (!colorStock.empty() && colorStock.top() == mixedColor)
                        {
                            colorStock.pop();
                        }
                        else
                        {
                            colorStock.push(mixedColor);
                        }
                    }
                    else
                    {
         
                        colorStock.push(color);
                    }
                }
            }
            else
            {
                colorStock.push(color);
            }
        }

        string OutputString = "";
        while (!colorStock.empty())
        {
            OutputString += colorStock.top();
            colorStock.pop();
        }
        cout << reverse(OutputString.begin(),OutputString.end()) << endl;
    
}

 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        code();
    }
    return 0;
}