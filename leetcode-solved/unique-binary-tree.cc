/*
 * The numebr of unique binary tree is catalan number
 * cat(n) = (2(2n+1)/(n+2))*cat(n-1)
 */

class Solution {
public:
  int numTrees(int n) {
    int cat[100000] = {0};
    cat[0] = 1;
    for(int i=1;i<100000;i++){
      cat[i] = cat[i-1] * (4*i+2) / (i+2);
    }
    return cat[n-1];
  }
};
