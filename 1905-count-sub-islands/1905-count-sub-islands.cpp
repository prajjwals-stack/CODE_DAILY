class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int &temp){
        if( !grid1[x][y]){
            temp=0;
        }
        grid2[x][y]=0;
        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(newx>=0 && newx<grid1.size() && newy>=0 && newy<grid1[0].size() && grid2[newx][newy]){
                dfs(newx,newy,grid1,grid2,temp);
            }
        }
    
            }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid2[i][j]){
                    int temp=1;
                    dfs(i,j,grid1,grid2,temp);
                    count=count+temp;
                    
                }
            }
        }
        return count;
    }
};