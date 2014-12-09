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
  int ss(TreeNode *r, int x){
    if(!r) return 0;
    x*=10;
    x+=r->val;
    if(!r->left && !r->right) return x;
    return ss(r->left,x)+ss(r->right,x);
  }
  int sumNumbers(TreeNode *root) {
    return ss(root,0);
  }
};
