/*
 * take every digit out
 */

class Solution {
public:
  int reverse(int x) {
    if(x < 0) return -reverse(-x);
        
    int digits[100] = {0};
    int len = 0, temp = x;
    while(x > 0){
      digits[len] = x%10;
      x=(x-x%10)/10;
      len++;
    }
    int out = 0;
    for(int i=0;i<len;i++){
      out = out + pow(10,len-i-1)*digits[i];
    }
    return out;
  }
};
