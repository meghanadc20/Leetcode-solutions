class Solution {
public:
    string reverseWords(string s) {
         int n = s.length();
       //reverse entire string
       reverseString(s,0,n-1);
       int start = 0, end = 0, i=0, j=0;
       while(j<n){
        while(j < n && s[j] == ' ') j++;
        if(j==n)break;
        start = i;
        while(j < n && s[j] != ' '){
            s[i++]=s[j++];
        }
        end = i-1; // because i will be incremented by 1 after reaching end of the word
        reverseString(s,start,end);
        if(j < n) {
            s[i]=' ';
            i++;
        }
     }
       if(i > 0 && s[i-1]==' ') i--;
       return s.substr(0,i);
    }
     void reverseString(string &s, int start, int end){
        while(start < end){
            swap(s[start++],s[end--]);
        } 
     }
};