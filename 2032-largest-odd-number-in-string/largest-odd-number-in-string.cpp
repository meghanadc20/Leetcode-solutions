class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length()-1;i>=0;i--){
             string res = "";
             int x = num[i] - '0'; // Since both operands are char, C++ performs integer promotion automatically.
             if(x % 2 != 0)
             {
                int start = 0;
               while (num[start] == '0') {
                  start++;
                    }
               return  res = num.substr(start,i-start+1);
             }  
        }
         return "";
    }
};