class DataStream
{
public:
    int val;
    int K;
    int cnt = 0;
    DataStream(int value, int k)
    {
        K = k;
        val = value;
    }

    bool consec(int num)
    {
        if (num == val)
            cnt++;
        else
            cnt = 0;
        return cnt >= K;
    }
};

// Leetcode submission: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/submissions/1132944426/