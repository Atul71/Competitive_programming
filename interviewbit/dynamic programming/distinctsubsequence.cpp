int Solution::numDistinct(string A, string B) {
    
    vector <vector<int>> dp(B.length()+1, vector <int> (A.length()+1,0));
    int i,j;
    
    for(i=0;i<A.length()+1;i++) 
        dp[0][i] = 1;
        
    for(i=1;i<B.length()+1;i++){
        for(j=1;j<A.length()+1;j++){
            if(A[j-1]==B[i-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[B.length()][A.length()];
    
}
