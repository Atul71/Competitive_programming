class Solution {
public:
    int lencheck(string s, int left, int right){
        if(left>right || s.length()==0)
           return 0;
        while(left>=0 && s[left]==s[right] && right<s.length()){
            left--;
            right++;
        }
        return right-left-1;
           
    }
    string longestPalindrome(string s) {
        int i, start = 0, end =0, len1, len2, len;
        
        for(i=0;i<s.length();i++){
            len1 = lencheck(s,i,i);
            len2 = lencheck(s,i,i+1);
            len = max(len1,len2);
            if(len>end-start+1){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};