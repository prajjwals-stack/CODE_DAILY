class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // int n=speed.size();
        vector<vector<int>>v(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            v[i][0]=efficiency[i];
            v[i][1]=speed[i];
        }
        sort(v.begin(),v.end(),cmp);
        // sort(v.cbegin(),v.cend());
        for(int i=0;i<n;i++){
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
         long long sum=0,ans=0;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++){
            sum+=v[i][1];
            q.push(v[i][1]);
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            // cout<<sum*v[i][0]<<endl;
            ans=max(ans,sum*v[i][0]);
            // cout<<ans<< " ";
        }
        
        return ans % int(1e9+7);
    }
};