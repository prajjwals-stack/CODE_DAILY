class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int color=grid[sr][sc];
        if(color==newColor){
            return grid;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(q.empty()==false){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            grid[x][y]=newColor;
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0 || newx>=grid.size() || newy<0 || newy>=grid[0].size() || grid[newx][newy]!=color){
                    continue;
                }
                    q.push({newx,newy});
            }
        }
        return grid;
        
    }
};