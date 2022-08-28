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
    bool flag=false;
    void pathsum(TreeNode* root,int target,int sum){
        if(root==NULL)return;
        
        sum+=root->val;
        if(sum==target && root->left==NULL && root->right==NULL)flag=true;
        pathsum(root->left,target,sum);
        pathsum(root->right,target,sum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0; 
        pathsum(root,targetSum,sum);
        return flag;
    }
};