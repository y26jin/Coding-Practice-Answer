/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void flatten(TreeNode *root) {
    if(!root) return;
        
    flatten(root->left);
    flatten(root->right);
    TreeNode *l = root->left, *r = root->right;
    if(!l){
      root->right = r;
      return;
    }
    else{
      TreeNode *tl = l;
      while(tl->right) tl = tl->right;
      tl->right = r;
      root->right = l;
      root->left = NULL;
      return;
    }
  }
};
