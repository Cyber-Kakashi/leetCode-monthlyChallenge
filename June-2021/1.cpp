// Max Area of Island
class Solution {
public:
    int maxSize = 0;
    int size = 1;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col]) {
                    size = 0;
                    dfs(row, col, grid);
                }
            }
        }
        
        return maxSize;
    }
    
    
    void dfs(int row, int col, vector<vector<int>>& grid) {
        if ((row >= 0 && row < grid.size()) && (col >= 0 && col < grid[0].size())) {
            if (grid[row][col]) {
                grid[row][col] = 0;
                size += 1;
                maxSize = max(size, maxSize);
                dfs(row, col - 1, grid);
                dfs(row, col + 1, grid);
                dfs(row - 1, col, grid);
                dfs(row + 1, col, grid);
            }
        }
    }
};