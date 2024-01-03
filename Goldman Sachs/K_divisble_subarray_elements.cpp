class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<string> visited;
        for (int i = 0; i < nums.size(); i++)
        {
            string temp = "";
            int count = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % p == 0)
                {
                    count++;
                }
                if (count > k)
                {
                    break;
                }

                temp = temp + to_string(nums[j]);
                temp = temp + "_";
                visited.insert(temp);
            }
        }
        return visited.size();
    }
};