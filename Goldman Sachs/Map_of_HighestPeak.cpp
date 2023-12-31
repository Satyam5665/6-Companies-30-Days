class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    mat[i][j] = 0;
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        int temp = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;

                if (i > 0 && mat[i - 1][j] == -1)
                {
                    mat[i - 1][j] = temp + 1;
                    q.push({i - 1, j});
                }
                if ((i < n - 1) && (mat[i + 1][j] == -1))
                {
                    mat[i + 1][j] = temp + 1;
                    q.push({i + 1, j});
                }
                if (j > 0 && (mat[i][j - 1]) == -1)
                {
                    mat[i][j - 1] = temp + 1;
                    q.push({i, j - 1});
                }
                if ((j < m - 1) && (mat[i][j + 1] == -1))
                {
                    mat[i][j + 1] = temp + 1;
                    q.push({i, j + 1});
                }
            }
            temp++;
        }
        return mat;
    }
};

// Leetcode Submission : https://leetcode.com/problems/map-of-highest-peak/submissions/1133176684/