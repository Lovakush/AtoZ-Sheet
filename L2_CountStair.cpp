#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n, int dp[])
    {
        
        //Using Recursion 
        /*
        if(n<=1)return 1;
        int l = countWays(n-1,dp);
        int r =  countWays(n-2,dp);
        return l+r;
        */
        

        //  Using Memoization 
        /*
        if(dp[n]!=-1)return dp[n];
        if(n<=1)return 1;
        int l = countWays(n-1,dp);
        int r = countWays(n-2,dp);
        return dp[n]=l+r;
        */

        // Using Tabulation
        int prev = 1;
        int prev2 = 1;
        int curri;
        for(int i=2;i<=n;i++)
        {
            curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        int dp[m+1];
        for(int i=0;i<m+1;i++)dp[i]=-1;
        Solution ob;
        cout<<ob.countWays(m,dp)<<endl; // Print the output from our pre computed array
    }
    return 0;
}