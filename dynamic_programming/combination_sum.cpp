//LC problem : 39. Combination Sum
// Link : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
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
    }
};
