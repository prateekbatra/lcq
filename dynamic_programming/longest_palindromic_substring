class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0|| len == 1)
            return s;
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        //Initialization
        for (int i = 0; i< len ;i++) {
            dp[i][i] = true;
            if (i+1<len && s[i]==s[i+1]) {
                dp[i][i+1] = true;
            }
        }
        //dp[i][j] - true, if the substring i to j is palindome
        for (int d = 2; d < len;d++) { // diff between idx i.e. j-i
            for (int i = 0;i+d < len;i++) {// for each diff val, iterate diagonally
                if (s[i]==s[i+d]) {
                    if (dp[i+1][i+d-1] == true) {
                        dp[i][i+d] = true;
                    }
                }
            }
        }
        // Extract the final op
        for (int d = len-1;d >=0;d-- ) {
            for (int i = 0 ;i+d< len;i++) {
                if (dp[i][i+d] == true) {
                    return s.substr(i,d+1);
                    //break;
                }
            }
        }
        return 0;    
    }
};
