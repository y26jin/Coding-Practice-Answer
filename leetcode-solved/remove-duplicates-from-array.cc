class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n<=1) return n;
        
    int index = 0;
    for(int i=1;i<n;i++){
      if(A[index] != A[i]){
	index++;
	A[index] = A[i];
      }
    }
    return index+1;
  }
};
