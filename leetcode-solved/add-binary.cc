class Solution {
public:
  string addBinary(string a, string b) {
    string c;
    if(a.empty() || b.empty()) return c;
        
    int carry = 0;
    if(a.length() < b.length()){
      for(int i=0;i<a.length();i++){
	int temp = a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0' + carry;
	carry = temp/2;
	c += temp%2 + '0';
      }
      for(int i=0;i<b.length()-a.length();i++){
	int temp = b[b.length()-a.length()-1-i] - '0' + carry;
	carry = temp/2;
	c += temp%2 + '0';
      }
    }
    else{
      for(int i=0;i<b.length();i++){
	int temp = a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0' + carry;
	carry = temp/2;
	c += temp%2 + '0';
      }
      for(int i=0;i<a.length()-b.length();i++){
	int temp = a[a.length()-b.length()-1-i] - '0' + carry;
	carry = temp/2;
	c += temp%2 + '0';
      }           
    }
    if(carry) c += '1';
    reverse(c.begin(), c.end());
    return c;
  }
};
