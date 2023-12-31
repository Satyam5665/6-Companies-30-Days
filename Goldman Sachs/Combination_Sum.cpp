class Solution
{
public:
    void solve(int i, set<int> &st, vector<int> temp, vector<vector<int>> &ans, int n, int k)
    {
        if (n == 0)
        {
            if (temp.size() == k)
                ans.push_back(temp);
            return;
        }
        if (n < 0)
        {
            return;
        }
        for (int j = i; j <= 9; j++)
        {
            if (st.find(j) == st.end())
            {
                st.insert(j);
                temp.push_back(j);
                solve(j + 1, st, temp, ans, n - j, k);
                temp.pop_back();
                st.erase(j);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        set<int> st;
        solve(1, st, temp, ans, n, k);
        return ans;
    }
};

// Leetcode submission : https://leetcode.com/problems/combination-sum-iii/submissions/1132936243/