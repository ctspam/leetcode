class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        # ur starting from the center which in this case is (sr, sc)
        start_pixel = image[sr][sc]
        # starting always turns into new colo as well
        # image[sr][sc] = color # color is an int
        self.dfs(image, sr, sc, color, start_pixel)
        return image

        # we can use dfs to make sure to see adjacent values
        # takes in start pixel because it changes when you move
    def dfs(self, image, sr, sc, color, start_pixel):
        # given image at this neew color, move right left, up down
        # but alsso make sure that it doesn't go out of bounds
        if sr < 0 or sr > len(image)-1 or sc < 0 or sc > len(image[0])-1 or image[sr][sc] == color or image[sr][sc] != start_pixel:
            return 
        image[sr][sc] = color
        self.dfs(image, sr+1, sc, color, start_pixel)
        self.dfs(image, sr-1, sc, color, start_pixel)
        self.dfs(image, sr, sc+1, color, start_pixel)
        self.dfs(image, sr, sc-1, color, start_pixel)
