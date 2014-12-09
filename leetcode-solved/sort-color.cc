class Solution {
public:
  void sortColors(int A[], int n) {
    if(!A || n<0) return;
        
    int r=0,g=0,b=0;
    for(int i=0;i<n;i++){
      if(A[i] == 0) r++;
      else if(A[i] == 1) g++;
      else if(A[i] == 2) b++;
    }
    for(int i=0;i<r;i++) A[i]=0;
    for(int i=r;i<r+g;i++) A[i]=1;
    for(int i=r+g;i<r+g+b;i++) A[i]=2;
  }
};
