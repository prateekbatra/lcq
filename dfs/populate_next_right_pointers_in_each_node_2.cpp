/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
         if (root == nullptr) {
            return root;
        }else {
            queue<Node *> qu;
            qu.push(root);
            while (!qu.empty()) {
                int len = qu.size();
                Node *prev = nullptr;
                for (int i = 0;i < len;i++) {
                    if (prev != nullptr) {
                        prev->next = qu.front();
                    }
                    if(qu.front() !=nullptr) {
                        prev = qu.front();
                        qu.push(prev->left);
                        qu.push(prev->right);
                    }
                    qu.pop();
                    
                }
                if (prev !=nullptr)
                    prev->next = nullptr;
            }
        }
        return root;
    }
};
