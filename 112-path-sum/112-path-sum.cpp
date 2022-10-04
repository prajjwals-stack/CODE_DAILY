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
    bool ans=false;
    void helper(TreeNode* root, int targetSum,int sum){
        if(root==NULL)return;
        
        sum+=root->val;
        if(!root->left && !root->right && sum==targetSum){
            ans=true;
        }
        helper(root->left,targetSum,sum);
        helper(root->right,targetSum,sum);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0);
        return ans;
    }
};