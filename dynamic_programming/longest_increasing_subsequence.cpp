class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Let dp[i] stores the number of increasing sequences, which has last sequence ending at i
        int len = nums.size();
        if (len ==0 || len ==1) {
            return len;
        }
        vector<int> dp(len);
        dp[0] = 1;
        int maxVal=1;
        for (int i = 1;i< len;i++) {
            int srchelem = 0;
            for (int j = i-1;j >= 0;j--) {
                if (nums[j]<nums[i]) {
                    srchelem = max(dp[j],srchelem);
                }
            }
            dp[i] = srchelem + 1;
            maxVal = max(dp[i],maxVal);
        }
        return maxVal;
    }
};
