class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        
        vector<int>ngr;
        vector<int>copy(2*n,-1);
        for(int i=0;i<2*n;i++){
            copy[i]=nums[i%n];
        }
        for(int i=copy.size()-1;i>=0;i--){
            if(s.empty()){
                ngr.push_back(-1);
            }
            else if(s.empty()==false && s.top()<=copy[i]){
                while(s.empty()==false && s.top()<=copy[i]){
                    s.pop();
                }
                if(s.empty()==false){
                    ngr.push_back(s.top());
                }
                else {
                    ngr.push_back(-1);
                }
                
            }
            else if(s.empty()==false && s.top()>copy[i]){
                ngr.push_back(s.top());
            }
            s.push(copy[i]);
        }
        reverse(ngr.begin(),ngr.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(ngr[i]);
        }
        return ans;
        
    }
};