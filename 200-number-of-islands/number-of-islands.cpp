class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        // in the upper one u want to traverse the grid
        // first u want to check if there are anything in the grid

        if(grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }

        // now u want to keep track of the num of islands
        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                // now check that if it does have a 1 or not
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

private: 
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // this is the dfs 
        // so we first need to check if its out of bounds when traversing
        // so we can avoid of all of that

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0')
        {
            return;
        }

        // now everytime we visit a '1' we want to mark it as '0'
        grid[i][j] = '0';

        // now we grow our search in the dfs going top down right left
        dfs(grid, i-1, j); // top
        dfs(grid, i+1, j); // bottom
        dfs(grid, i, j-1); // right
        dfs(grid, i, j+1); // left
    }
};