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
    int maxsum=INT_MIN;
    int pathsum(TreeNode* root){
        if(root==NULL )return 0;
        
        // sum+=root->val; 
        // maxsum=max(sum,maxsum);
        // pathsum(root->left,sum);
        // pathsum(root->right,sum);
        int lsum=0;
        if(root->left)lsum=max(0,pathsum(root->left));
        int rsum=0;
        if(root->right)rsum=max(0,pathsum(root->right));
        
        maxsum=max(maxsum,lsum+rsum+root->val);
       
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int sum=0;
        pathsum(root);
        return maxsum;
        
    }
};