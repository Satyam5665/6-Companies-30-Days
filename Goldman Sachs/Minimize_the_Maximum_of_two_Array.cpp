class Solution
{
public:
    long long ggcd(int a, int b)
    {
        if (b == 0)
            return a;

        return ggcd(b, a % b);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long ans = INT_MAX;
        long long lo = 1, hi = INT_MAX;

        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long a = mid - mid / divisor1;
            long long b = mid - mid / divisor2;
            long long gcd = ggcd(divisor1, divisor2);
            long long lcm = (long long)((long long)divisor1 * (long long)divisor2) / gcd;

            long long temp = mid - mid / lcm;

            if (a >= uniqueCnt1 && b >= uniqueCnt2 && temp >= uniqueCnt1 + uniqueCnt2)
            {
                hi = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

// Leetcode submission : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/submissions/