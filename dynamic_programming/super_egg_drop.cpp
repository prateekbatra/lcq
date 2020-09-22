class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        //m -> moves, k ->eggs
        //dp[m][k] -> max number of floors , which can be checked
        //dp[m][k] = dp[m-1][k-1]+dp[m-1][k]+1
       
        
        
        /*dp[M][K]means that, given K eggs and M moves,
        what is the maximum number of floor that we can check.
        The dp equation is:
        dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
        which means we take 1 move to a floor,
        if egg breaks, then we can check dp[m - 1][k - 1] floors.
        if egg doesn't breaks, then we can check dp[m - 1][k] floors.
        dp[m][k] is the number of combinations and it increase exponentially to N*/
        
        
        int m =0;
        for (m = 0;dp[m][K] < N;) {
            m++;
            for (int k=1;k<=K;k++) {
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k]+1;
            }
        }
        return m;
    }
};
