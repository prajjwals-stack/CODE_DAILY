class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int ans=0;
        int cnt=0;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]!=0)count++;
            }
        }
       
        while(q.empty()==false){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            cnt++;
            ans=max(time,ans);
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]==1){
                   grid[newx][newy]=2;
                    q.push({{newx,newy},time+1});
                }
            }
        }
        if(count==cnt)return ans;
        return -1;
    }
};