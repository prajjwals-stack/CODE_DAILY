class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int oldcolor){
        grid[x][y]=-oldcolor;
        int count=0;
        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || abs(grid[newx][newy])!=oldcolor){
                continue;
            }
            count++;
            if(grid[newx][newy]==oldcolor){
                dfs(grid,newx,newy,oldcolor);
            }
        }
        if(count==4){
            grid[x][y]=oldcolor;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int oldcolor=grid[row][col];
        dfs(grid,row,col,oldcolor);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};