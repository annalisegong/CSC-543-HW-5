#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

string longestCommonSubstring(string a, string b, int l1, int l2)
{
    int LCS[l1 + 1][l2 + 1];
    int longest = 0;
    int row;
    int column;
    string result = "                           ";

    for(int i = 0; i <= l1; i++)
    {
        for(int j = 0; j <= l2; j++)
        {
            if(i == 0 || j == 0)
            {
                LCS[i][j] = 0;//makes 1st row and 1st column all 0s
            }
            else if(a[i - 1] == b[j - 1])  
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1; //if chars match, indicate by inc matches by 1
                if(longest < LCS[i][j])
                {
                    longest = LCS[i][j];//track longest set of substrings
                    row = i;
                    column = j;
                }
            }
            else
            {
                LCS[i][j] = 0;
            } 
        }
    }

    if(longest == 0)
    {
        result = "no common substrings";
        //cout << result << endl;
        return result;
    }
    else
    {
        while(LCS[row][column] != 0)
        {
            result[--longest] = a[row -1 ];
            row--;
            column--;
        }
        //cout << result << endl;
        return result;
    }
}

int main()
{
    string a = "abcdde";
    string b = "dabcde";
    
    int l1;
    int l2;

    if(a.length() == b.length())
    {
        l1 = l2 = a.length() + 1;
    }
    else
    {
        l1 = a.length() + 1;
        l2 = b.length() + 1;
    }

    cout << longestCommonSubstring(a, b, l1, l2) << endl;

    return 0;
}