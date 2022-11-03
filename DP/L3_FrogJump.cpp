

Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

#include <bits/stdc++.h>
using namespace std;

// memoization 
int f(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int l = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int r = INT_MAX;
    if (n > 1)
    {
        r = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(l, r);
}

// Tabulation Approach 

int f(int n, vector<int> &heights)
{
    vector<int> dp{n,-1};
    dp[0] = 0;
    int jumpTwo = INT_MAx;
    for(int ind=1;ind<n;i++)
    {
        int jumpOne = dp[ind-1] + abs(heights[ind]-heights[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] +abs(heights[ind]-heights[ind-2]);
        dp[ind] = min(jumpOne,jumpTwo);
    }
    cout<<dp[n-1];
}


//Space Optimization
int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss =  prev2 + abs(heights[i]-heights[i-2]);
        int curri = min(fs,ss);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp{n + 1, -1};
    return f(n - 1, heights, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights{n+1,-1};
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        for(auto x : heights)cout<<x<<" ";
        // cout<<frogJump(n, heights)<<endl;
    }
}