class Solution {
public:
    int arr[20];
    int help(int n){
        if(n==0 ||n==1){
            return 1;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        int res=0;
        
        for(int i=0;i<n;i++){
            res+=help(i)*help(n-i-1);
        }
        arr[n]=res;
        return arr[n];
    }
    int numTrees(int n) {
       
        for(int i=0;i<20;i++){
            arr[i]=-1;
            
        }
        return help(n);
        
    }
};