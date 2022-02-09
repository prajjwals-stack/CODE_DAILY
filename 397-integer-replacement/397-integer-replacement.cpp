class Solution {
public:
    int integerReplacement(int n) {
        int cur=0;
        long int N=n;
        while(N!=1){
            if(N%2==0){
                N=N/2;
                cur++;
            }
            else if (N==3){
                N=N-1;
                cur++;
            }
            else{
                if((N-1)%4==0){
                    N--;
                }
                else{
                    N++;
                }
                cur++;
                
            }
        }
        return cur;
        
    }
};