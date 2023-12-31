class Solution
{
public:
    const int MOD = 1e9 + 7;
    map<pair<int, int>, int> dp;
    int solve(int i, int n, int k)
    {
        if (k == 0)
        {
            return i == n;
        }
        if (abs(i - n) > k)
            return 0;
        if (dp.find({i, k}) != dp.end())
            return dp[{i, k}];
        return dp[{i, k}] = (solve(i - 1, n, k - 1) + solve(i + 1, n, k - 1)) % MOD;
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        dp.clear();
        return solve(startPos, endPos, k) % MOD;
    }
};

// Leetcode submission: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/submissions/1132919572/