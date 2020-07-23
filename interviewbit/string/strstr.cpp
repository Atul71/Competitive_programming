nt Solution::strStr(const string A, const string B) {
    
    string needle = B;
    string haystack = A;
    vector <int> kmp;
        kmp.push_back(0);
        //kmp.push_back(0);
        if(haystack.length()<needle.length())
            return -1;
        if(haystack.length()==0 && needle.length()==0)
            return 0;
        if(needle.length()==0)
            return 0;
        
        int i,j;
        i = 0;
        for(j=1;j<needle.length();j++){
            if(needle[i]==needle[j]){
                
                kmp.push_back(i+1);
                i++;
            }
            else if(i==0){
                kmp.push_back(0);
            }
            else{
                i = kmp[i-1];
                j--;
            }
        }
        
        i = 0;
        j = 0;
        for(i=0;i<haystack.length();i++){
            if(haystack[i]==needle[j]){
                j++;
                if(j==needle.length())
                    return i-j+1;
            }
            else if(j==0){
                continue;
            }
           else{
               i--;
               if(j-1<0)
                    j=kmp[0];
               else
               j = kmp[j-1];
           }
        }
        return -1;
}