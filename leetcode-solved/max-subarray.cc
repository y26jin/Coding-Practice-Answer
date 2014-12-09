class Solution {
public:
  int maxSubArray(int A[], int n) {
    if(!A || n<0) return 0;
        
    int max = -0xFFFFFF,sum=0;
    for(int i=0;i<n;i++){
      sum = sum+A[i];
      if(sum > max) max = sum;
      if(sum < 0) sum = 0;
    }
    return max;
  }
};
