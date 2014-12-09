class Solution {
public:
  int climbStairs(int n) {
    if(n<=0) return 0;
        
    int f[10000] = {0};
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int i=3;i<10000;i++){
      f[i] = f[i-1] + f[i-2];
    }
    return f[n];
  }
};
