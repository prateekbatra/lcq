class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
                return vector<int>(0);
            }
        }
        return flist;
    }
};
