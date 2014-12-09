class Solution {
public:
  bool search(int A[], int n, int target) {
    if(!A || n<0) return false;
        
    int lo = 0, hi = n-1;
    while(lo<hi){
      int mid = lo + (hi-lo)/2;
      if(A[mid] == target) return true;
      if(A[lo]==A[mid] && A[lo] != target) lo++;
      if(A[hi]==A[mid] && A[hi] != target) hi--;
      else if(A[lo]<=A[mid]){
	if(A[lo]<=target && target<=A[mid]) hi = mid - 1;
	else lo = mid + 1;
      }
      else{
	if(A[lo]<= target || A[mid] >=target) hi = mid - 1;
	else lo = mid + 1;
      }
    }
    if(A[lo] == target || A[hi] == target) return true;
    else return false;
  }
};
