class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    if(!A || !B) return;
    if(m<0 || n<0) return;
    if(m==0){
      for(int i=0;i<n;i++) A[i]=B[i];
      return;
    }
    if(n==0) return;
        
    int e1 = m-1, e2 = n-1, index = m + n - 1;
    while(e1 >= 0 && e2 >= 0){
      if(A[e1] > B[e2]){
	A[index] = A[e1];
	index--;
	e1--;
      }
      else{
	A[index] = B[e2];
	index--;
	e2--;
      }
    }
    while(e2 >= 0){
      A[index] = B[e2];
      index--;
      e2--;
    }
        
    return;
  }
};
