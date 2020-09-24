// LC problem : 39. Combination Sum
// Link : https://leetcode.com/problems/combination-sum/
class Solution {
public:
    /*vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<vector<int>>> comb (target+1,vector<vector<int>>());
        int len = candidates.size();
        comb[0].push_back(vector<int>());
        for (int i = 0; i< len;i++) {
            // for eachcandidates[i]
            for (int tgtSum = 0;tgtSum <= target-candidates[i];tgtSum++) {
                // for each tgt sum
                if (comb[tgtSum].size()>0) {
                    vector<vector<int>> tmp = comb[tgtSum];
                    for (auto &vec : tmp) {
                        vec.push_back(candidates[i]);    
                    }
                    comb[tgtSum+candidates[i]].insert(comb[tgtSum+candidates[i]].end() ,tmp.begin(),tmp.end());
                }
            }
        }
        // the op -> comb[sum]
        return comb[target];
    }*/
    //backtracking
    void helper1(vector<int>& candidates, int i, int j, int remSum, vector<int> &subop,vector<vector<int>> &op) {
        
        if (remSum == 0) {
            op.push_back(subop);
            return;
        }else if (i>j) {
            return;
        }
        
            
        if (remSum >= candidates[i] ) {
            // consider i, and move forward
            subop.push_back(candidates[i]);
            //helper(candidates,i+1,j,remSum-candidates[i],subop,op);
            // consider i, and dont move forward
            helper1(candidates,i,j,remSum-candidates[i],subop,op);
            subop.pop_back();
        }
        // dont consider i and move forward - whether remSum < or >=
        helper1(candidates,i+1,j,remSum,subop,op);
        
    }
    //op -> output
    void helper2(vector<int> &candidates, int i, int j, int remSum, vector<int> &subop, vector<vector<int>> &op) {
        
        if (remSum == 0) {
            op.push_back(subop);
            return;
        }

        for (int idx = i;(idx<=j) && (remSum>=candidates[idx]);idx++) {
            subop.push_back(candidates[idx]);
            helper2(candidates,idx,j,remSum-candidates[idx],subop,op);
            subop.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> op;
        vector<int> subop;
        int remSum = target;
        sort(candidates.begin(),candidates.end());
        //helper1(candidates,0,candidates.size()-1,remSum,subop,op);
        helper2(candidates,0,candidates.size()-1,remSum,subop,op);
        
        return op;
        
    }
};
