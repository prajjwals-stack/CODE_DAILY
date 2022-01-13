class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int p=0,q=numbers.size()-1;
        while(p<q){
            int sum=numbers[p]+numbers[q];
            if(target>sum){
                p++;
            }
            else if(target<sum){
                q--;
            
            }
            else{
                return {p+1,q+1};
            }
        }
        return {};
    }
};