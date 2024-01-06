class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0;
                int cnt = 0;
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < n && l >= 0 && l < m)
                        {
                            cnt++;
                            sum += img[k][l];
                        }
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};