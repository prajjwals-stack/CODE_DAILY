/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    vector<long long >v;
    void helper(TreeNode* root,int target){
        if(root==NULL)return;
        
        
        v.push_back(root->val);
        helper(root->left,target);
        helper(root->right,target);
        
        long long sum=0;
        
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i];
            
            if(sum==target)
                cnt++;
        }
        v.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        
        helper(root,targetSum);
        return cnt;
        
    }
};