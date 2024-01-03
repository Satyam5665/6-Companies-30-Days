class Solution
{
public:
    void rev(int i, int j, vector<int> &t)
    {
        while (i <= j)
        {
            swap(t[i], t[j]);
            i++;
            j--;
        }
    }
    string smallestNumber(string pattern)
    {
        int n = pattern.size() + 1;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(i + 1);
        }

        for (int i = 0; i < n; i++)
        {
            int idx = i;
            while (idx < n && pattern[idx] == 'D')
            {
                idx++;
            }
            rev(i, idx, temp);
            if (idx != i)
                i = idx - 1;
        }

        string ans;
        for (int i : temp)
        {
            ans = ans + char(i + '0');
        }
        return ans;
    }
};