/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // it is a BFS problem , with a hashmap<vertical_idx, value> and then go over it to return it in given output format
        // You dont need to specify any initalization, if we know what we are going to access based on the logic of insertion to map
        TreeNode *node = root;
        vector<vector<int>> op;
        queue<pair<TreeNode *,int>> q;
        unordered_map<int,vector<int>> mp;
        if (node) {
            // add the node along with idx 
            q.push(make_pair(node,0));
        }
        int minVal=INT_MAX, maxVal=INT_MIN;
        while (!q.empty()) {
            int nq = q.size();
            for (int i = 0;i < nq;i++) {
                pair<TreeNode *,int> tmp = q.front();
                q.pop();
                if (tmp.first) {
                    int idx = tmp.second;
                    mp[idx].push_back(tmp.first->val);
                    //store min, max val
                    minVal = min(tmp.second,minVal);
                    maxVal = max(tmp.second,maxVal);
                    q.push(make_pair(tmp.first->left,tmp.second-1));
                    q.push(make_pair(tmp.first->right,tmp.second+1));         
                }
            }
        }
        for (int i = minVal;i <= maxVal;i++) {
            op.push_back(mp[i]);
        }
        return op;
    }
};
