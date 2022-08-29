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
    void path(TreeNode* root,int targetSum,vector<int>v,int sum){
        if(root==NULL)return;
        
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==targetSum ){
            ans.push_back(v);
        }
        path(root->left,targetSum,v,sum);
        path(root->right,targetSum,v,sum);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        int sum=0;
        path(root,targetSum,v,sum);
        return ans;
    }
};