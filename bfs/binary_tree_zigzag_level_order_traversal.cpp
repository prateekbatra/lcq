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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // This is a DFS question
        queue<TreeNode*> qu;
        vector<vector<int>> op;
        if (root) {
            qu.push(root);
        }
        int d=1;
        while (!qu.empty()) {
            int sz = qu.size();
            d=(d+1)%2;
            //op.push_back(vector<int>);
            
            list<int> li;
            for (int i = 0;i < sz;i++) {
                
                TreeNode *tmp = qu.front();
                qu.pop();
                //subop.push_back(tmp->val);
                if (d ==1) {
                    li.push_front(tmp->val);
                }
                else{
                    //left to right
                    li.push_back(tmp->val);
                }
                if (tmp->left)
                   qu.push(tmp->left);
                if (tmp->right)
                   qu.push(tmp->right);
            }
            vector<int> subop(li.begin(),li.end());
            op.push_back(subop);
        }
        return op;
    }
};
