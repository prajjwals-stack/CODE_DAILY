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
    bool help(TreeNode* root,int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            return targetSum==sum?true:false;
        }
        return help(root->left,targetSum,sum) || help(root->right,targetSum,sum);
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return help(root,targetSum,0);
    }
};