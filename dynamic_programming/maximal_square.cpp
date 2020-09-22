class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nr = matrix.size();
        int nc  = 0;
        
        if (nr>0)
            nc = matrix[0].size();
        if (nr==0|| nc ==0)
            return 0;
        vector<vector<int>> dp(nr,vector<int>(matrix[0].size(),0));
        int maxVal = dp[0][0];
        for (int r =0;r< nr;r++) {
            dp[r][0] = matrix[r][0]=='1'?1:0;
            maxVal = max(dp[r][0],maxVal);
        }
        for (int c = 0;c < nc;c++) {
            dp[0][c] = matrix[0][c]=='1'?1:0;
            maxVal = max(dp[0][c],maxVal);
        }
        
        
        for (int r =1;r< nr;r++) {
            for (int c = 1;c < nc;c++) {
                if (matrix[r][c] == '1') {
                    int calc = min(dp[r-1][c-1],dp[r-1][c]);
                    int calc1 = min(calc,dp[r][c-1]);
                    dp[r][c] = calc1+1;
                    maxVal = max(maxVal,dp[r][c]);
                }else {
                    dp[r][c] = 0;
                }
                
            }
        }
        return maxVal*maxVal;
    }
};
