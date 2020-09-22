class Solution {
public:
    
    void helper(string &s, int idx, int lefto_rm, int rghto_rm, int pair, string path,unordered_set<string> &op) {
        // base condition
        if (idx == s.size()) {
            if (lefto_rm ==0 && rghto_rm ==0 && pair == 0) {
                op.insert(path);
            }
            // if index has crossed limit, return no matter if the valid string can be inserted or not
            return;
        }
        
        if (s[idx] != '(' && s[idx] != ')') {
            helper(s,idx+1,lefto_rm,rghto_rm,pair,path+s[idx],op);
        }else {
            if (s[idx] == '(') {
                // there are two options , whether to include s[i] in final output or not
                if (lefto_rm > 0) {
                    helper (s,idx+1,lefto_rm-1,rghto_rm,pair,path,op);
                }
                helper (s,idx+1,lefto_rm,rghto_rm,pair+1,path+s[idx],op);
            }else { //s[i] == ')' case
                if (rghto_rm > 0) {
                    helper (s,idx+1,lefto_rm,rghto_rm-1,pair,path,op);
                }
                if (pair > 0)
                    helper(s, idx+1,lefto_rm,rghto_rm,pair-1,path+s[idx],op);
            }
        }
        
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> op;
        int lefto_rm = 0,rghto_rm = 0;
        // calculate how many left and right braces needs to be dropped
        for (char c : s) {
            if (c == '(') {
                lefto_rm++;
            }else if (c == ')') {
                if (lefto_rm > 0) {
                    lefto_rm--;
                }else {
                    rghto_rm++;
                }
            }
        }
        int st_idx = 0;
        int mismacth_pair = 0;
        helper(s,st_idx,lefto_rm,rghto_rm,mismacth_pair,"",op);
        
        return vector<string>(op.begin(),op.end());
    }
};
