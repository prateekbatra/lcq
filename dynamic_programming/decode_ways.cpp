class Solution {
public:
    int numDecodings(string s) {
        
        int len = s.size();
        vector<int> dp(len+1);
        if (len ==0 ) {
            return 0;
        }
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0:1;
        for (int i = 2; i <= len;i++) {
            if (s[i-1]!='0'){
                dp[i] += (dp[i-1]);    
            }
            int td = (s[i-2]-'0')*10+(s[i-1]-'0');
            if ( td>=10 && td<=26) {
                dp[i] += dp[i-2];
            }
            
        }
        return dp[len];
    }
};
