**
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
    vector<int> largestValues(TreeNode* root) {
        TreeNode *node = root;
        queue<TreeNode *> q;
        if (node) {
            q.push(node);
        }
        vector<int> op;
        while (!q.empty()) {
            int nq = q.size();
            int maxelem = q.front()->val;
            for (int i = 0;i < nq;i++) {
                TreeNode *tmp = q.front();
                maxelem = max(maxelem,tmp->val);
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            op.push_back(maxelem);
            
        }
        return op;
    }
};
