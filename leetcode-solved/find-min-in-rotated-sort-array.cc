class Solution {
public:
  int findMin(vector<int> &num) {
    if(num.empty()) return 0;
    if(num.size() == 1) return num[0];
        
    int lo = 0, hi = num.size()-1;
    while(lo<=hi){
      int mid = lo+(hi-lo)/2;
      if(num[lo] <= num[mid] && num[mid] <= num[hi]) break;
      else if(num[mid] < num[lo]) hi = mid;
      else if(num[mid] > num[hi]) lo = mid+1;
    }
    return num[lo];
  }
};
