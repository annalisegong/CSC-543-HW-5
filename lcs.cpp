#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

string longestCommonSubstring(string a, string b, int l1, int l2)
{
    int LCS[l1 + 1][l2 + 1]; //creates 2D look up table keeps track of previous matches
    int longest = 0; //tracks length of longest common substring
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
                LCS[i][j] = LCS[i - 1][j - 1] + 1; //if chars match, record in table by inc previous # of matches by 1
                if(longest < LCS[i][j]) //if current # of matches > current longest substring
                {
                    longest = LCS[i][j];// updates longest
                    row = i; //tracks row or longest
                    column = j;//tracks column of longest
                }
            }
            else
            {
                LCS[i][j] = 0; //no matches indicate w 0
            } 
        }
    }

    if(longest == 0)
    {
        result = "no common substrings";
        return result;
    }
    else
    {
        //traverse look up table diagonally starting at location of longest substring
        while(LCS[row][column] != 0)
        {
            result[--longest] = a[row -1 ];//stores chars in longest substring (building last to first char)
            row--;
            column--;
        }
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