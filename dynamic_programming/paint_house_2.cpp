class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        int n = costs.size();
        int k =0;
        if (n > 0) {
            k = costs[0].size();
        }
        if (n==0) 
            return 0;
        vector<int> dp(2,INT_MAX);
        int minidx = -1;
        
        for (int i = 0;i < k;i++) {
               int x = min(costs[0][i],dp[0]);
               if (x < dp[0]) {
                   dp[1] = dp[0];
                   dp[0] = x;
                   minidx = i;
               }else {
                   dp[1] = min(dp[1],costs[0][i]);
               }
        }
        
        for (int i = 1;i < n;i++) {
            int mincolor = INT_MAX;
            int secmincolor = INT_MAX;
            int previdx = minidx;
            
            for (int j = 0;j < k;j++) {
                int procidx = -1;
                if (j !=previdx) {
                    procidx = 0;
                }else {
                    procidx = 1;
                }
                int x = min(mincolor,costs[i][j]+dp[procidx]);
                if (x < mincolor) {
                    secmincolor = mincolor;
                    mincolor = x;
                     minidx = j;        
                }else {
                    secmincolor = min(secmincolor,dp[procidx]+costs[i][j]);
                }
            }
            dp[0] = mincolor;
            dp[1] = secmincolor;
        }
        return dp[0];
        
    }
};
