class Solution
{
public:
    void solve(int i, string s, vector<string> &ans, string t, map<char, string> &mp)
    {
        if (i == s.length())
        {
            cout << t;
            ans.push_back(t);
            return;
        }

        for (char ch : mp[s[i]])
        {
            solve(i + 1, s, ans, t + ch, mp);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        solve(0, digits, ans, "", mp);
        return ans;
    }
};

// Leetcode submission : https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1132866492/