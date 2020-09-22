// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {// Apply BFS - with a trick 
        Node *root = nullptr;
        map<Node*, Node*> grtbl;// mapping storage between two graphs
        queue<Node *> qu;
        if (node != nullptr) {
            Node *tmp = new Node(node->val);
            root = tmp;
            grtbl[node] = tmp;
            qu.push(node);
        }
        while (!qu.empty()) {
            Node *tmp = qu.front();
            qu.pop();
            auto itr = grtbl.find(tmp);
            if (itr != grtbl.end()) {
                Node *clptr = itr->second;
                for (Node *proc : tmp->neighbors){
                    Node *cltmp;
                    auto itr2 = grtbl.find(proc);
                    if (itr2 !=grtbl.end()) {
                        cltmp = itr2->second;//grtbl[proc];
                    }else {
                        cltmp = new Node(proc->val);
                        //push them back to queue to process again, only if it was not visited
                        qu.push(proc);
                        grtbl[proc] = cltmp;
                    }
                    clptr->neighbors.push_back(cltmp);   
                }
            }else {
                cout<<"Prateek ERROR : "<<tmp->val;
            }
        }
        return root;
    }
};
