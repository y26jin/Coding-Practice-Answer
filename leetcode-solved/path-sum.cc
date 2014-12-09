class Solution {
public:
  void helper(unordered_set<int> &hash, TreeNode *t, int sum){
    if(!t->left && !t->right){
      sum += t->val;
      hash.insert(sum);
      return;
    }
        
    if(t->left) helper(hash,t->left,sum+t->val);
    if(t->right) helper(hash,t->right,sum+t->val);
  }
    
  bool hasPathSum(TreeNode *root, int sum) {
    if(!root) return false;
        
    unordered_set<int> hash;
    helper(hash,root,0);
        
    if(hash.find(sum) == hash.end()) return false;
    else return true;
  }
};
