class Solution {
public:
    int dfs(int i, int j, vector < vector <int> >& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return 1;
        if(grid[i][j] == 2) return 0;
        if(grid[i][j] == 0){
            
            return 1;
        }
        grid[i][j] = 2;
        int ret = 0;
        ret = dfs(i + 1, j, grid) + dfs(i, j + 1, grid) +  dfs(i - 1, j, grid) + dfs(i, j - 1, grid);
        return  ret;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) return dfs(i, j, grid);
            }
        }
        return 0;
    }
};
