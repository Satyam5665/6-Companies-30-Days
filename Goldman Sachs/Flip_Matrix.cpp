class Solution
{
public:
    int total;
    int r, c;
    set<int> st;
    Solution(int m, int n)
    {
        r = m;
        c = n;
        total = r * c;
    }

    vector<int> flip()
    {
        if (st.size() == total)
            return {};
        int random = rand() % total;
        while (st.find(random) != st.end())
        {
            random = ++random % total;
        }
        st.insert(random);
        return {random / c, random % c};
    }

    void reset()
    {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */