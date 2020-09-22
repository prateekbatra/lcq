class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*        
        L = Empty list that will contain the sorted elements
        S = Set of all nodes with no incoming edge

        while S is non-empty do
            remove a node n from S
            add n to tail of L
            for each node m with an edge e from n to m do
                remove edge e from the graph
                if m has no other incoming edges then
                    insert m into S

        if graph has edges then
            return error   (graph has at least one cycle)
        else 
            return L   (a topologically sorted order
          */      
                
        set<int> vdeg0;
        for (int i = 0;i < numCourses;i++) {
            vdeg0.insert(i);
        }
        unordered_map<int,pair<int,list<int>>> gr;
        for (int i = 0; i < prerequisites.size();i++) {
            gr[prerequisites[i][1]].second.push_back(prerequisites[i][0]);
            ++gr[prerequisites[i][0]].first;
            vdeg0.erase(prerequisites[i][0]);
        }
        vector<int> flist;
        while (!vdeg0.empty()) {
            set<int>::iterator vdegitr = vdeg0.begin();
            if (vdegitr != vdeg0.end()) {
                int v0 = *vdegitr;
                vdeg0.erase(vdegitr);
                flist.push_back(v0);
                list<int>::iterator litr = gr[v0].second.begin();
                for (;litr!= gr[v0].second.end();) {//
                    int elem = *litr;
                    --gr[elem].first;
                    gr[v0].second.erase(litr++);
                    if (gr[elem].first <= 0) {
                        //add to the set
                        vdeg0.insert(elem);
                    }
                }
            }
        }
        for (auto itr : gr) {
            if (!itr.second.second.empty()) {
                return false;
            }
        }
        return true;
    }
};
