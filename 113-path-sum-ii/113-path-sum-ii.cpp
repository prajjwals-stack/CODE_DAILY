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
    vector<vector<int>>ans;
    void helper(TreeNode* root,int target,int sum,vector<int>&v){
        if(root==NULL)return;
        
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                ans.push_back(v);
            }
        }
        helper(root->left,target,sum,v);
        helper(root->right,target,sum,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return {};
        vector<int>v;
        helper(root,targetSum,0,v);
        return ans;
    }
};