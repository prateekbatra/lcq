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
    int findVec(int st, int end, int srchVal, vector<int>& inorder) {
        for (int i=st;i<=end;i++) {
            if(inorder[i] == srchVal) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode *genTree(int st, int end, int &postidx, vector<int>& inorder, vector<int>& postorder) {
        if (st == end) {
            TreeNode *tmp = new TreeNode(inorder[st]);
            tmp->left=tmp->right=nullptr;
            return tmp;
        }else {
            int sidx = findVec(st,end,postorder[postidx], inorder);
            if(sidx ==-1){
                cout<<"There seems to be some issue"<<endl;
                return nullptr;
            }
            TreeNode *node = new TreeNode(postorder[postidx]);
            if(sidx!=end) {
                node->right = genTree(sidx+1,end,--postidx,inorder,postorder);
            }
            if (sidx!=st) {
                node->left = genTree(st,sidx-1,--postidx,inorder,postorder);
            }
            return node;
        }
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int st = 0, end = inorder.size()-1;
        int idx = end;
        if(end>=0) {
            return genTree(st,end,idx,inorder,postorder);
        }else{
            return nullptr;
        }
    }
};
