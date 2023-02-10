#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

string longestCommonSubstring(string a, string b)
{
    int strLength1;
    int strLength2;

    if(a.length() == b.length())
    {
        strLength1 = strLength2 = a.length() + 1;
    }
    else
    {
        strLength1 = a.length() + 1;
        strLength2 = b.length() + 1;
    }

    int LCS[strLength1][strLength2];
    int longest = 0;
    int row;
    int column;
    string result = "";

    for(int i = 0; i <= strLength1; i++)
    {
        for(int j = 0; j <= strLength2; j++)
        {
            if(i == 0 || j == 0)
            {
                LCS[i][j] = 0;//makes 1st row and 1st column all 0s
            }
            else if(a[i -1] == b[j - 1])  
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

    //string result;

    if(longest == 0)
    {
        result = "no common substrings";
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
        return result;
    }
}

int main()
{
    string a = "hannah";
    string b = "savana";
    
    cout << longestCommonSubstring(a, b);

    return 0;
}