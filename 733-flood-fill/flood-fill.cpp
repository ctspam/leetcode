class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // check if theres anything in the image
        int origColor = image[sr][sc];
        if (origColor == color) return image; // edge case!
        dfs(image, sr, sc, origColor, color);
        return image;
    }
private: 
    void dfs(vector<vector<int>>& image, int sr, int sc, int origColor, int color)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != origColor )
        {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr-1, sc, origColor, color);
        dfs(image, sr+1, sc, origColor, color);
        dfs(image, sr, sc-1, origColor, color);
        dfs(image, sr, sc+1, origColor, color);

    }
};