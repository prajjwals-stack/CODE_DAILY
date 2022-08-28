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
    int sum=0;
    int nodesum(TreeNode* root){
        if(root==NULL)return 0;
        
        return nodesum(root->left)+nodesum(root->right)+root->val;
        
    }
    
    int findTilt(TreeNode* root) {
        if(root==NULL)return 0;
        
        int left=nodesum(root->left);
        int right=nodesum(root->right);
        
        sum+=abs(left-right);
        findTilt(root->left);
        findTilt(root->right);
        return sum;
    }
};