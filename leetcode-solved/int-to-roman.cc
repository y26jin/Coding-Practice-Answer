class Solution {
public:
  string intToRoman(int num) {
    int thousand=0, hundred=0, ten=0, one=0;
    thousand = (num - num%1000) / 1000;
    hundred = (num%1000 - num%100) / 100;
    ten = (num%100 - num%10) / 10;
    one = num%10;
        
    string output;
    if(thousand > 0){
      if(thousand == 1) output += "M";
      if(thousand == 2) output += "MM";
      if(thousand == 3) output += "MMM";
    }
        
    if(hundred > 0){
      if(hundred == 1) output += "C";
      if(hundred == 2) output += "CC";
      if(hundred == 3) output += "CCC";
      if(hundred == 4) output += "CD";
      if(hundred == 5) output += "D";
      if(hundred == 6) output += "DC";
      if(hundred == 7) output += "DCC";
      if(hundred == 8) output += "DCCC";
      if(hundred == 9) output += "CM";
    }
        
    if(ten > 0){
      if(ten == 1) output += "X";
      if(ten == 2) output += "XX";
      if(ten == 3) output += "XXX";
      if(ten == 4) output += "XL";
      if(ten == 5) output += "L";
      if(ten == 6) output += "LX";
      if(ten == 7) output += "LXX";
      if(ten == 8) output += "LXXX";
      if(ten == 9) output += "XC";
    }
        
    if(one > 0){
      if(one == 1) output += "I";
      if(one == 2) output += "II";
      if(one == 3) output += "III";
      if(one == 4) output += "IV";
      if(one == 5) output += "V";
      if(one == 6) output += "VI";
      if(one == 7) output += "VII";
      if(one == 8) output += "VIII";
      if(one == 9) output += "IX";
    }
    return output;
  }
};
