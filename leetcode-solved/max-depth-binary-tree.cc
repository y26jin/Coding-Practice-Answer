/*
 * max{left-depth, right-depth} + 1
 */

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
        
    int left = maxDepth(root->left), right = maxDepth(root->right);
    if(left<right) return right+1;
    else return left+1;
  }
};
