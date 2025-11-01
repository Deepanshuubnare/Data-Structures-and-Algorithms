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
   bool f(TreeNode*root,long long mini,long long maxi){
     if(root==NULL) return true;
     if(root->val<=mini || root->val>=maxi) return false;
     return f(root->left,mini,root->val) && f(root->right,root->val,maxi);
   }
    bool isValidBST(TreeNode* root) {
        return f(root,-1e15,1e15);
    }
};