//Lc problem : 78. Subsets
//Link : https://leetcode.com/problems/subsets/
class Solution {
public:
    void helper1(vector<int>& nums, int st, int end,vector<int> &subop ,vector<vector<int>> &op) {
        
        if (st > end) {
            return;
        }
        
        for (int i = st;i <=end;i++ ) {
            
            subop.push_back(nums[i]);
            op.push_back(subop);
            helper1(nums,i+1,end,subop,op);
            subop.pop_back();
        }
    }
    
    void helper2(vector<int>& nums, int st, int end,vector<int> &subop ,vector<vector<int>> &op) {
        
        if (st > end) {
            op.push_back(subop);
            return;
        }
        
        subop.push_back(nums[st]);
        helper2(nums,st+1,end,subop,op);
        subop.pop_back();
        
        helper2(nums,st+1,end,subop,op);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subop;vector<vector<int>> op;
        //op.push_back(subop);
        helper2(nums,0,nums.size()-1,subop,op);
        return op;
        
    }
};
