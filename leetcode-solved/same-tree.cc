/*
 * isSame(p->left,q->left), isSame(p->right,q->right)
 */

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if(!p && !q) return true;
    if(!p && q) return false;
    if(p && !q) return false;
    if(p->val != q->val) return false;
        
    bool left = isSameTree(p->left, q->left), right = isSameTree(p->right, q->right);
    if(left && right) return true;
    else return false;
  }
};
