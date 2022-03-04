class Solution {
public:
    void boundarydfs(int x,int y, vector<vector<int>>& grid, int row, int col){
        grid[x][y]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy]==0){
                    boundarydfs(newx,newy,grid,row,col);
                }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        //running over the boundries on all 4side to convert 0 to 1s on the boundary and connected to boundary
        for(int i=0;i<row;i++){
            if(grid[i][0]==0) boundarydfs(i,0,grid,row,col);
            
            if(grid[i][col-1]==0) boundarydfs(i,col-1,grid,row,col);
        }
        for(int j=0;j<row;j++){
            if(grid[0][j]==0) boundarydfs(0,j,grid,row,col);
            
            if(grid[row-1][j]==0) {
                boundarydfs(row-1,j,grid,row,col);
            }
        }
        
        
        //checking inside boundary to find islands
        int cnt=0;
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j]==0){
                    boundarydfs(i,j,grid,row,col);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};