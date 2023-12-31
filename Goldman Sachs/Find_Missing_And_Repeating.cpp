class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here
        int i = 0;
        while (i < n)
        {
            int current_element = arr[i];

            if (current_element != -1)
            {
                int swap_element = arr[current_element - 1];
                if (swap_element != -1)
                {
                    swap(arr[current_element - 1], arr[i]);
                    arr[current_element - 1] = -1;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                return {arr[i], i + 1};
            }
        }

        return {0, 1};
    }
};
