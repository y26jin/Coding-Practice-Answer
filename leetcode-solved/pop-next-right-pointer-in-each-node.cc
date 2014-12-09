class Solution {
public:
  void connect(TreeLinkNode *root) {
    if(!root) return;
        
    connect(root->left);
    connect(root->right);
        
    TreeLinkNode *l = root->left, *r = root->right;
    while(l && r){
      l->next = r;
      l = l->right;
      r = r->left;
    }
  }
};
