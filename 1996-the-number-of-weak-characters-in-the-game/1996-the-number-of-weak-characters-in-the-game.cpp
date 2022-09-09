class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        int size=v.size();
        int count=0;
        sort(v.begin(),v.end(),cmp);
        int maxi=INT_MIN;
        for(int i=size-1;i>=0;i--){
            if(v[i][1]<maxi){
                count++;
            }
            maxi=max(maxi,v[i][1]);
        }
        return count;
    }
};