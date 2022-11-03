// Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Memoization
    int memoization(int a, int b, vector<vector<int>> &dp)
    {
        if (a == 0 && b == 0)
            return 1;
        if (a < 0 || b < 0)
            return 0;
        if (dp[a][b] != -1)
            return dp[a][b];
        int up = memoization(a - 1, b, dp);
        int left = memoization(a, b - 1, dp);
        return dp[a][b] = up + left;
    }

    // Tabulation

    int Tabulation(int a, int b)
    {
        int dp[a][b];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[a - 1][b - 1];
    }

    int SpaceOptimazation(int a, int b)
    {
        vector<int> prev(b, 0);
        for (int i = 0; i < a; i++)
        {
            vector<int> curr(b, 0);
            for (int j = 0; j < b; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[b - 1];
    }

    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // vector<vector<int>> dp(a,vector<int>(b,-1));
        // return memoization(a-1,b-1,dp);
        // return  Tabulation(a,b);
        return SpaceOptimazation(a, b);
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        // calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}