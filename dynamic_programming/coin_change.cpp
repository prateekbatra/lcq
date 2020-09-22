class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(),coins.end());
        int max = amount+1;
        vector<int> dp(amount+1, max);
        dp[0]=0;
        for(int i=1;i<=amount;i++) {
            for(int j=0;j<coins.size();j++) {
                if(coins[j]<=i) {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1); 
                }
            }
        }
        return dp[amount]<max?dp[amount]:-1;
        
    }
};
