class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int count=0;
        int check=0;
        queue<vector<int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j,count});
                    check++;
                }
            }
        }
        
        while(q.empty()==false){
            int x=q.front()[0];
            int y=q.front()[1];
            int cnt= q.front()[2];
            q.pop();
            int dx[]={0,-1,0,1};
            int dy[]={-1,0,1,0};
            for(int k=0;k<4;k++){
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0){
                    grid[newx][newy]=1;
                    q.push({newx,newy,cnt+1});
                    
                    count=cnt+1;
                }
            }
        }
        if(check==0 || check==grid.size()*grid[0].size()) return -1;
        return count;
    }
};