class Solution {
public:
    
    int bfs(int i ,int j, int n, int m, vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=-1;
        int area=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            area++;
            
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1){
                    q.push({newx,newy});
                    grid[newx][newy]=-1;
                }
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=bfs(i,j,n,m,grid);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};