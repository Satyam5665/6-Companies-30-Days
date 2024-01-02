class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1002];
    int solve(int i, int delay, int f , int n){
        if(i+delay > n) return 1;
        int res =1;
        if(dp[i]!=-1) return dp[i];
        for(int j = i+delay;j<=min(n,i+f);j++){
            if(j==i+f){
                res -=1;
                break;
            }
            res = res%MOD + solve(j,delay,f,n)%MOD;
        }
        return dp[i] = res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return solve(1,delay,forget,n)%MOD;
    }
};

//This question is Very Good.
//Revisit It for revision.
//Leetcode: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/