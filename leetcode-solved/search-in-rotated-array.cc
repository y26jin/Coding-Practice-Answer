class Solution {
public:
  int search(int A[], int n, int target) {
    if(!A || n<0) return -1;
        
    int lo = 0, hi = n-1;
    while(lo<hi){
      int mid = lo+(hi-lo)/2;
      if(A[mid] == target) return mid;
      if(A[lo]<=A[mid]){
	if(A[lo] <= target && target <= A[mid]) hi = mid - 1;
	else lo = mid + 1;
      }
      else{
	if(A[lo] <= target || target <= A[mid]) hi = mid - 1;
	else lo = mid + 1;
      }
            
    }
    if(A[lo] == target) return lo;
    else if(A[hi] == target) return hi;
    else return -1;
  }
};
