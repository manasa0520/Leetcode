int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    void dfs(int i, int j, vector < vector <char> >& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int k = 0; k < 4; k++){
            dfs(i + dir[k][0], j + dir[k][1], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int n = grid.size();
        int m = n ? grid[0].size() : 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ret++;
                    dfs(i, j, grid);
                }
            }
        }
        return ret;
    }
};
