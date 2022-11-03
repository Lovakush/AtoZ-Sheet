/*

A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

*/

#include <bits/stdc++.h>
using namespace std;

// Memoization

int f(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return dp[n][last] = maxi;
    }
    if (dp[n][last] != -1)
        return dp[n][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int activity = points[n][task] + f(n - 1, points, task, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[n][last] = maxi;
}

// Tabulation approach

int Tabulation(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// Space Optimization

int SpaceOptimazation(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {

        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }

    return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, points, 3, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    // cout<<ninjaTraining(n,points);
    // cout << Tabulation(n, points);
    cout << SpaceOptimazation(n, points);
    return 0;
}