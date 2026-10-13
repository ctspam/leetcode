class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        # get the number of rows and columns in the grid
        rows, cols = len(heights), len(heights[0])
        # separate visited sets for each ocean so neither search doesnt block the other
        pac, atl = set(), set()
        # regular dictionary that counts how many oceans can reach each cell (i want to see if theres multiple counts of a certain coordinate then thats what i return)
        count = {}
        # cleaner way in the neetcode sln vid says to starts climbs uphill from a cell and marks every cell this ocean can reach
        def dfs(r: int, c: int, visited: set[tuple[int, int]], prev_height: int) -> None:
            # stop if out of bounds, already visited for this ocean,
            # or lower than the cell we came from since water can't flow up to it
            if (r < 0 or c < 0 or r == rows or c == cols
                    or (r, c) in visited
                    or heights[r][c] < prev_height):
                return
            # mark this cell as reached by this ocean
            visited.add((r, c))
            # if another ocean already reached this cell, add 1 to its count
            if (r, c) in count:
                count[(r, c)] += 1
            # first ocean to reach this cell, so start its count at 1
            else:
                count[(r, c)] = 1
            # go down, pass this cell's height so the next cell has to be the same or higher
            dfs(r + 1, c, visited, heights[r][c])
            # go up
            dfs(r - 1, c, visited, heights[r][c])
            # go right
            dfs(r, c + 1, visited, heights[r][c])
            # go left
            dfs(r, c - 1, visited, heights[r][c])

        # loop through every column to hit the top and bottom rows
        for c in range(cols):
            # top row touches the pacific, pass its own height so it always gets added
            dfs(0, c, pac, heights[0][c])
            # bottom row touches the atlantic
            dfs(rows - 1, c, atl, heights[rows - 1][c])
        # loop through every row to hit the left and right columns
        for r in range(rows):
            # left column touches the pacific
            dfs(r, 0, pac, heights[r][0])
            # right column touches the atlantic
            dfs(r, cols - 1, atl, heights[r][cols - 1])
        # a count of 2 means both oceans reached the cell, so return those
        return [[r, c] for (r, c), k in count.items() if k == 2]