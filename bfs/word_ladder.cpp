class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // make a graph
        // edge between words, which are one char difference away
        //min distance between word given
        
        // if not present
        wordList.push_back(beginWord);
        
        int len = wordList.size();
        vector<vector<int>> gr(len);
        vector<bool> visited(len,false);
        int diff = 0;
        for (int i = 0; i < len;i++) {
            for (int j = i+1; j< len;j++) {
                diff = 0;
                for (int k = 0;k < wordList[j].size();k++) {
                    
                    if (wordList[i][k] != wordList[j][k]) {
                        diff++;
                        if (diff > 1){
                            break;
                        }
                    }
                }
                if (diff == 1) {
                    // i & j
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                    //cout <<"Graph"<<i<<"-->"<<j<<endl;
                }
            }
        }
        
        // do a BFS to graph and find minimum path - abort when endWord is found
        visited[len-1] = true;
        queue<int> q;
        q.push(len-1);
        int level = 0;
        while (!q.empty()) {
            
            int sz = q.size();
            level++;
            for (int i = 0; i < sz;i++) {
                int node = q.front();
                if (wordList[node]== endWord) {
                    return level;
                }
                q.pop();
                visited[node] = true;
                for (int j = 0;j < gr[node].size();j++) {
                    if (visited[gr[node][j]] == false) {
                        q.push(gr[node][j]);    
                    }
                }
            }    
        }
        return 0;
        
    }
};  
