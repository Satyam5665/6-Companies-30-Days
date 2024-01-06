class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        if (s.length() <= 10)
            return ans;
        map<string, int> mp;
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            for (int j = i; j < min(n, i + 10); j++)
            {
                temp += s[j];
            }
            if (temp.length() == 10)
            {
                mp[temp]++;
            }
        }
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};