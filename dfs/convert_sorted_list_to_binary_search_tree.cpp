/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *node;
public:
    TreeNode *helper(int l, int r) {
        if (l>r)
            return nullptr;
        int m = l+ (r-l)/2;
        TreeNode *tnode = new TreeNode();
        tnode->left = helper(l,m-1);
        tnode->val= node->val;
        node = node->next;
        tnode->right = helper(m+1,r);
        return tnode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode *trav=head;trav!=nullptr;trav=trav->next) {
            len++;
        }
        node = head;
        cout<<"length:"<<len<<endl;
        return helper(0,len-1);
    }
};
