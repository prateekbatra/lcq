class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        
        grid[r][c] = '0';
        if(r>=1 && grid[r-1][c] == '1') dfs(grid,r-1,c);
        if(c>=1 && grid[r][c-1] == '1') dfs(grid,r,c-1);
        if(r<nr-1 && grid[r+1][c] == '1')dfs(grid,r+1,c);
        if(c<nc-1 && grid[r][c+1] == '1') dfs(grid,r,c+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
            int nr = grid.size();
        int nc=0;
        if (nr>0)
            nc = grid[0].size();
        int nis=0;
        
        for (int r =0; r < nr ;r++) {
            for (int c =0;c < nc;c++) {
                if (grid[r][c] == '1') {
                    nis++;
                    dfs(grid,r,c);
                }
            }
        }
        return nis;
    }
};
