class Solution {
    vector<int> parent;
public:
    int findP(int v) {
        while (parent[v] !=v) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n;i++) {
            parent[i] = i;
        }
        for (auto &edge : edges) {
            int pv1 = findP(edge[0]);
            int pv2 = findP(edge[1]);
            
            if (pv1 == pv2) {
                // detected a cycle
                return false;
            }else{
                //do union
                parent[pv1] = pv2;
            }
        }
        int count = 0;
        for (int i = 0; i < n;i++) {
            if (parent[i]==i) {
                count++;
            }
        }
        return (count > 1)?false:true;
        
        
    }
};
