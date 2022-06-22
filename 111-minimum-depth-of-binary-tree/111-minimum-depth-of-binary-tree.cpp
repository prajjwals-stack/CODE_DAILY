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
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        
        int Depth=0;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            Depth++;
            while(len--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL)return Depth;
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            
            }
        }
        return Depth;
    }
};