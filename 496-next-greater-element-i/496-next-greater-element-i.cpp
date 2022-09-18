class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>v;
        int n=nums2.size();
        while(n--){
            if(s.empty()){
                v.push_back(-1);
            }
            else if(s.top()>nums2[n] && !s.empty()){
                v.push_back(s.top());
                
            }
            else if(!s.empty() && s.top()<=nums2[n]){
                while(!s.empty() && s.top()<=nums2[n]){
                    s.pop();
                }
                if(!s.empty()){
                    v.push_back(s.top());
                    
                }
                else{
                   v.push_back(-1); 
                }
            }
            s.push(nums2[n]);
            cout<<nums2[n]<<" ";
        }
        reverse(v.begin(),v.end());
        map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
            
         
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(v[m[nums1[i]]]);
        }
        
        return ans;
    }
};