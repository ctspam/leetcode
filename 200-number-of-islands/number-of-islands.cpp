class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        // check the cases first
        if(grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }

        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++count;
                }   
            }
        }

        return count;
    }

private: void dfs(vector<vector<char>>& grid, int i, int j)
    {
        // these check if the dfs is going to be out of bounds when traversing
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }

        // this will mark the cells visited
        grid[i][j] = '0';

        // NOW explore all four directions
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};