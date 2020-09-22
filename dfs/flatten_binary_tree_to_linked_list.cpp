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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *node = nullptr;
        if (root){
            node = root;
            stk.push(node);
        }
            
        while (!stk.empty()) {
            TreeNode* tmp = stk.top();
            stk.pop();
            if (tmp->right)
                stk.push(tmp->right);
            if (tmp->left)
                stk.push(tmp->left);
            
            
            /*if (tmp->left) {
                tmp->right = tmp->left;    
            }else if (!stk.empty()) {
                tmp->right = stk.top();
            }else{
                tmp->right = nullptr;    
            }*/
            
            tmp->right = tmp->left?tmp->left:(!stk.empty()?stk.top():nullptr);
            tmp->left = nullptr;
        }
    }
};
