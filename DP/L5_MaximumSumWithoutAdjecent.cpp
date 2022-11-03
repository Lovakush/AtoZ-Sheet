#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	

    // Memoization 
    int f(int *arr,int n,vector<int> &dp)
    {
        if(n==0)return arr[n];
	    if(n<0)return 0;
	    if(dp[n]!=-1)return dp[n];
	    int pick = arr[n] + f(arr,n-2,dp);
	    int notPick = 0 + f(arr,n-1,dp);
	    return dp[n] = max(pick,notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    return f(arr,n-1,dp);
	}

    // TC -- O(n);
    // SC -- O(n) + O(n) = O(n) // stack space + array space 

    // Tabulation 

	int findMaxSum(int arr[], int n) {
	    int dp[n];
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++)
	    {
	        int take = arr[i];
	        if(i>1)take+=dp[i-2];
	        int notTake = dp[i-1];
	        dp[i] = max(take,notTake);
	    }
	    return dp[n-1];
	}

    // TC -- O(n);
    // TC -- O(n) // we are using array 

    // Space optimazation 
    	int findMaxSum(int arr[], int n) {
	    int prev = arr[0];
	    int prev2 = 0;
	    for(int i=1;i<n;i++)
	    {
	        int take = arr[i];
	        if(i>1)take+=prev2;
	        int notTake = prev;
	        int curri = max(take,notTake);
	        prev2 = prev;
	        prev = curri;
	    }
	    return prev;
	}

    // TC -- O(n);
    // SC -- O(1);


};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}