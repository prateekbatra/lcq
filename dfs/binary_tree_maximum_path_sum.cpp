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
    int maxsum=INT_MIN;
    int trav(TreeNode* node) {
        if (node == nullptr){
            return 0;
        }
        int l = trav(node->left);
        int r = trav(node->right);
        
        int pathsum = node->val;
        if (l>0) {
            pathsum+=l;
        }
        if (r > 0) {
            pathsum +=r;
        }
        
        maxsum = max(maxsum, pathsum);
        if (l>0||r>0) {
            return max(l+node->val,r+node->val);    
        }else {
            return node->val;
        }
        
        
    }
    int maxPathSum(TreeNode* root) {
        if (root != nullptr) {
            trav(root);
            return maxsum;
        }else {
            return 0;
        }
        
    }
};
