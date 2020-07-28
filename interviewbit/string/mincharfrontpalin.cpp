int Solution::solve(string A) {
    vector <int> lps;
    lps.push_back(0);
    int i,j,k;
    string B = A + "$";
    
    for(i=A.size()-1;i>=0;i--)
        B+=A[i];
    i = 0;
    for(j=1;j<B.size();j++){
        if(B[i]==B[j]){
            i++;
            lps.push_back(i);
        }
        else{
            
            while(i!=0){
                i = lps[i-1];
                if(B[i]==B[j]){
                    i++;
                    lps.push_back(i);
                    break;
                }
            }
            if(i==0)
                lps.push_back(0);
            
        }
    }
    
    return A.length()-lps[lps.size()-1];
}
