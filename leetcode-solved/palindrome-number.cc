class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    int t1 = x, t2 = 0;
    while(t1 > 0){
      t2 *= 10;
      t2 += t1%10;
      t1 /= 10;
    }
    if(t2 == x) return true;
    else return false;
  }
};
