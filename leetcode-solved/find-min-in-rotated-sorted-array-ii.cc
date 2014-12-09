class Solution {
public:
  int findMin(vector<int> &num) {
    if(num.empty()) return 0;
        
    int lo = 0, hi = num.size()-1;
    while(lo<hi){
      int mid = lo + (hi-lo)/2;
      if(num[lo] < num[mid] && num[mid] < num[hi]) break;
      if(num[lo] == num[mid] && lo<num.size()-1) lo++;
      if(num[hi] == num[mid] && hi>0) hi--;
      if(num[lo] > num[mid]) hi = mid;
      if(num[hi] < num[mid]) lo = mid + 1;
    }
    if(lo < hi) return num[lo];
    else return num[hi];
  }
};
