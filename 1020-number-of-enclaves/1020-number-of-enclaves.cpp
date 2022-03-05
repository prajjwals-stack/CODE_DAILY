class Solution {
public:
    void DFS(vector<vector<int>> &grid, int m, int n, int i, int  j)
    {
        grid[i][j]=0;
        int dir[5] = {-1,0,1,0,-1};
        
        for(int d=0;d<4;d++)
        {
            int x = i + dir[d];
            int y = j + dir[d+1];
            
            if(x>=0 && x<m && y>=0 && y <n && grid[x][y]==1)
            {
                DFS(grid,m,n, x,y);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int m =grid.size();
        int n = grid[0].size();
         int enclaves =0;
        if(m==1 && n==1)
        {
            return enclaves;
        }
       
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                
                DFS(grid,m,n,i,0);
            }
            if(grid[i][n-1]==1)
            {
                DFS(grid,m,n,i,n-1);
            }
        }
        for(int j=0;j<n;j++)
        {
         
            if(grid[0][j]==1)
            {
                DFS(grid,m,n,0,j);
            }
            if(grid[m-1][j]==1)
            {
                DFS(grid,m,n,m-1,j);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    enclaves++;
                }
            }
            
        }
        return enclaves;
        
    }
};