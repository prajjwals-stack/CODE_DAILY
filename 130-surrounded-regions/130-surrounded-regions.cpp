class Solution {
public:
    
    void boundarydfs(int x,int y, vector<vector<char>>& board, int row, int col){
        board[x][y]='$';
        
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<row && newy>=0 && newy<col && board[newx][newy]=='O'){
                boundarydfs(newx,newy,board,row,col);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++){
            if(board[i][0]=='O') boundarydfs(i,0,board,row,col);
            
            if(board[i][col-1]=='O') boundarydfs(i,col-1,board,row,col);
            
        }
        
        for(int j=0;j<col;j++){
            if(board[0][j]=='O') boundarydfs(0,j,board,row,col);
            
            if(board[row-1][j]=='O') boundarydfs(row-1,j,board,row,col);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='$') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};