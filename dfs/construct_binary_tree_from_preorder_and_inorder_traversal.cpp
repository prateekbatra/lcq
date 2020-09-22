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
    
    int findVec(int st,int end, int srchVal, vector<int>& inorder) {
        for (int i=st;i<=end;i++) {
            if(inorder[i]==srchVal){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode * genTree(int &idx, int st, int end,vector<int>& preorder, vector<int>& inorder) {
        cout<<"Start of genTree : st:"<<st<<"end:"<<end<<"preorder idx:"<<idx<<endl;
        if(end==st) {
            TreeNode *tmp = new TreeNode(inorder[end]);
            tmp->left =nullptr,tmp->right=nullptr;
            cout <<"end node:"<<inorder[end]<<endl;
            return tmp;
        }else { 
            int sidx= findVec(st,end,preorder[idx],inorder);
            cout<<"sidx:"<<sidx<<endl;
            if(sidx==-1){
                cout<<"There seems to be issue"<<endl;
                return nullptr;
            }
            {
                cout <<"start:"<<st<<" end:"<<end<<endl;
                TreeNode *self;
                self = new TreeNode(inorder[sidx]);
                self->left =nullptr,self->right=nullptr;
                if(st!=sidx) {
                    self->left = genTree(++idx,st,sidx-1,preorder, inorder);
                }
                if(sidx!=end) {
                    self->right = genTree(++idx,sidx+1,end,preorder, inorder);
                }
                return self;
            }
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int st=0, end = preorder.size()-1,idx=0;
        if(end >=0)
            return genTree(idx,st,end,preorder, inorder);
        else 
            return nullptr;
    }
    
};
