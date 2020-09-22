class Solution {
public:
    int mydfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r ,int c, int nr, int nc) {
        if (r>=nr || c>=nc||r<0||c<0 || visited[r][c] == 1 ||grid[r][c] == 0)
            return 0;
        visited[r][c] = 1;
        
        return (1+ mydfs(grid,visited,r+1,c,nr,nc)+
                   mydfs(grid,visited,r,c+1,nr,nc)+
                   mydfs(grid,visited,r-1,c,nr,nc)+
                   mydfs(grid,visited,r,c-1,nr,nc)
               );
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc;
        if (nr > 0)
            nc = grid[0].size();
        
        vector<vector<int>> visited(nr,vector<int>(nc,0));
        int ar = 0;
        for (int r = 0;r < nr;r++) {
            for (int c = 0;c < nc;c++) {
                if (grid[r][c] == 1) {
                    int calcar = mydfs(grid,visited,r,c,nr,nc);
                    ar = max(ar,calcar);
                }
            }
        }
        return ar;
    }
};
