/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int prev;
    bool trav (TreeNode *node, int *low, int *high) {
        if(node ==nullptr)
            return true;
        if (low != nullptr && (node->val<= *low)) {
            return false;
        }
        if (high != nullptr && (node->val>= *high)) {
            return false;
        }
        if(!trav(node->left,low,&node->val))
            return false;
        
        if(!trav(node->right,&node->val,high))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }else {
            return trav(root,nullptr,nullptr);
        }
    }
};
