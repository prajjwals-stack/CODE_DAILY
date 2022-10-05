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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL && depth==1){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        if(root!=NULL && depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(q.empty()==false){
            if(level==depth-1)break;
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                 
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                            
            }
            level++;
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            TreeNode* left=node->left;
            TreeNode* right=node->right;
            TreeNode* newleft=new TreeNode(val);
            TreeNode* newright=new TreeNode(val);
            node->left=newleft;
            node->right=newright;
            newleft->left=left;
            newleft->right=NULL;
            newright->left=NULL;
            newright->right=right;
        }
        return root;
    }
};