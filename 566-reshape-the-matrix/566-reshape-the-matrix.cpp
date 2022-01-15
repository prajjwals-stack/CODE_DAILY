class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if(row*col!=r*c){
            return mat;
        }
        vector<vector<int>> NewMat(r,vector<int>(c,0));
        int NewRow=0,NewCol=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                NewMat[NewRow][NewCol]=mat[i][j];
                NewCol++;
                if(NewCol==c){
                    NewCol=0;
                    NewRow++;
                }
                
            }
        }
        return NewMat;
    }
};