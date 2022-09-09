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
    TreeNode* helper(vector<int>&post,unordered_map<int,int>&in,int &post_ind,int st,int en){
        if(st>en){
        return NULL;
    }
    
    // create node for current post ind
    TreeNode* root = new TreeNode(post[post_ind]);
    
    // position in inorder
    int k = in[root->val];
    
    // increament index
    post_ind--;
    
    root->right = helper(post,in,post_ind,k+1,en);        
    root->left = helper(post,in,post_ind,st,k-1);
    
    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
           unordered_map<int,int>in;
    
    int n = postorder.size();
    
    for(int i=0;i<n;i++){
        in[inorder[i]] = i;
    }
    
    int post_ind = n-1;        
    return helper(postorder,in,post_ind,0,n-1);
       
      
    }
};