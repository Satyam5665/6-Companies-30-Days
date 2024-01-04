class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto query : queries)
        {
            int k = query[0];
            int trim = query[1];
            vector<pair<string, int>> temp;
            int i = 0;
            for (string num : nums)
            {
                temp.push_back({nums[i].substr(nums[i].size() - trim), i});
                i++;
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp[k - 1].second);
        }
        return ans;
    }
};