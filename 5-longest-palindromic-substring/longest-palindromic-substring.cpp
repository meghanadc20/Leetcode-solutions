class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
       int start = 0;
       int end = 0;
       for(int i=0; i < n; i++) {
        auto odd = expand(s,i,i);
        auto even = expand(s,i,i+1);    
        // to store length of longest sub string 
        if(odd.second-odd.first > end - start) {
              start = odd.first; 
              end = odd.second;
        }
        if(even.second-even.first > end - start) {
            start = even.first;
            end = even.second;
        }
       }
       return s.substr(start,end-start+1);
    }
     pair<int,int> expand( const string &s, int left, int right){
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--;
                right++;
            }
            return {left+1,right-1};
        }
};