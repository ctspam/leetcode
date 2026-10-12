class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        
    # using bfs hwere u scan the grid and put every rotten orange in th equeue and count only the fresh ones
    # want to process the queue at each level which each level rrepesents one minute, 
    # when the queue is empty if any fresh orange remai, return -1
        row, col = len(grid), len(grid[0])
        queue = deque()
        num_fresh_orange, count = 0,0

        # fnind the starting point of every rotting orrange
        for r in range(row):
            for c in range(col):
                # 2 == the rotten orange
                if grid[r][c] == 2:
                    queue.append((r,c))
                elif grid[r][c] == 1:
                    num_fresh_orange+=1
        directions = [(1,0),(-1,0),(0,1),(0,-1)]

        # need ot go through each level with bfs and stop when nothing is fresh
        while queue and num_fresh_orange > 0:
            count+=1
            for _ in range(len(queue)):
                r, c = queue.popleft()
                # need to show how far to move in each direciton
                for row_step, col_step in directions:
                    neighbor_row = r + row_step
                    neighbor_col = c + col_step

                # neighbor must be in bounds and fresh
                    if(0 <= neighbor_row < row and 0<=neighbor_col < col and grid[neighbor_row][neighbor_col] == 1):
                        grid[neighbor_row][neighbor_col] = 2
                        num_fresh_orange -=1
                        queue.append((neighbor_row, neighbor_col))

        return count if num_fresh_orange == 0 else -1

            