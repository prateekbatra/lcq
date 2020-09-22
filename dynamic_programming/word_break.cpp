class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        int n = s.size();
        bool dp[n+1];
        //Initialize
        for(int i=0;i<=n;i++){
            dp[i] = false;
        }
        dp[0] = true;
        if(n==1){
            if(dict.find(s)!=dict.end()){
                return true;
            }
            else
                return false;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                auto const &itr=dict.find(s.substr(j,i-j));
                if((dp[j]==true) && (itr!=dict.end())){
                    //cout<<"idx:"<<i<<endl;
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
