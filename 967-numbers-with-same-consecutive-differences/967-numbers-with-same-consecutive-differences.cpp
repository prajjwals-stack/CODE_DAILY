class Solution {
public:
    void dfs(int i,int ind,int k,vector<int>&result,int n){
        if(ind==n){
            result.push_back(i);
            return ;
        }
        int lastdigit=i%10;
        
        if(lastdigit>=k)dfs(i*10+lastdigit-k,ind+1,k,result,n);
        if(k>0 && lastdigit+k<10)dfs(i*10+lastdigit+k,ind+1,k,result,n);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>result;
        if(n==1)result.push_back(0);
        for(int i=1;i<10;i++){
            dfs(i,0,k,result,n-1);
        }
        return result;
                                                                                                                                                                                                                                                                                                                                             
    }
};