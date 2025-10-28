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
    int level(TreeNode*root){
if(root==NULL) return 0;
int ans=1+max(level(root->left),level(root->right));
return ans; 
}
void nlevellr(TreeNode*root,int curr,int level,vector<int>&v){
if(root==NULL) return;
if(curr==level){ 
v.push_back(root->val);
return;                           // left to right
}
nlevellr(root->left,curr+1,level,v);
nlevellr(root->right,curr+1,level,v);
}
    void nlevelrl(TreeNode*root,int curr,int level,vector<int>&v){
 if(root==NULL) return;
   if(curr==level){ 
    v.push_back(root->val);
    return;                           // right to left
    }
    nlevelrl(root->right,curr+1,level,v);
    nlevelrl(root->left,curr+1,level,v);

}
void levelorder(TreeNode*root, vector<vector<int>>&ans){
int n=level(root);
for(int i=1;i<=n;i++){
    vector<int>v;
   if(i%2!=0){
    nlevellr(root,1,i,v);
    ans.push_back(v);
   }
    else{
 nlevelrl(root,1,i,v);
    ans.push_back(v);
    } 
}
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelorder(root,ans);
        return ans;
    }
};