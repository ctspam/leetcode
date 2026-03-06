class Solution {
    int d4i[4] = {0,0,1,-1};
    int d4j[4] = {1,-1,0,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j]&&grid[i][j]=='1') {  
                    queue<pair<int,int>> q;
                    q.push({i,j}); 
                    cnt++;
                    while(q.size()) {
                        auto [x,y]=q.front();q.pop();
                        if(visited[x][y]) continue;
                        visited[x][y]=1;
                        for(int k=0;k<4;k++) {
                            int newX=x+d4i[k];
                            int newY=y+d4j[k];
                            if(newX<n&&newX>=0&&newY<m&&newY>=0&&!visited[newX][newY]&&grid[newX][newY]=='1') {
                                q.push({newX,newY});
                            }
                        }
                    } 
                    

                }
            }
        }
        return cnt;
    }
};