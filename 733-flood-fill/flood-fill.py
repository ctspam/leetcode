class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        # ur starting from the center which in this case is (sr, sc)
        start_pixel = image[sr][sc]

        # we can use dfs to make sure to see adjacent values
        # takes in start pixel because it changes when you move
        def dfs(r,c):
            # given image at this neew color, move right left, up down
            # but alsso make sure that it doesn't go out of bounds
            if r < 0 or r > len(image)-1 or c < 0 or c > len(image[0])-1 or image[r][c] == color or image[r][c] != start_pixel:
                return 
            image[r][c] = color
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)

        # starting always turns into new colo as well
        # image[sr][sc] = color # color is an int
        dfs(sr,sc)
        return image
