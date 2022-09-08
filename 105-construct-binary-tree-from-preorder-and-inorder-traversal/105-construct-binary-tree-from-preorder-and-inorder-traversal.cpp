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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int startPre,int endPre,int startIn,int endIn, map<int,int>&m,int index){
        if(startPre>endPre || startIn>endIn)return NULL;
        
        
        int curr=preorder[startPre];
        TreeNode * node=new TreeNode(curr);
        
        int position= m[node->val];
        int numLeft=position-startIn;
        
        node->left= buildTreeHelper(preorder,inorder,startPre+1,startPre+numLeft,startIn,position-1,m,index);
        node->right=buildTreeHelper(preorder,inorder,startPre+numLeft+1,endPre,position+1,endIn,m,index);
        
        return node;
        
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        if(preorder.size()==0 && inorder.size()==0)return NULL;
        int startIn=0,endIn=inorder.size()-1;
        int startPre=0,endPre=preorder.size()-1;
        map<int,int>m;
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int index=0;
        TreeNode* root=buildTreeHelper(preorder,inorder,startPre,endPre,startIn,endIn,m,index);
        
        return root;
        
    }
};