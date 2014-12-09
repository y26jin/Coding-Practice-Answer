/*
 * a^a = 0, a^b = 1, therefore do exclusive or to all elements then the result is that one extradinary number
 */

class Solution {
public:
  int singleNumber(int A[], int n) {
    int temp = A[0];
    for(int i=1;i<n;i++){
      temp = temp ^ A[i];
    }
    return temp;
  }
};
