class Solution {
public:
    int minDistance(string word1, string word2) {
        vector <vector<int>> dp(word2.length()+1, vector <int> (word1.length()+1,0));
        int i,j;
        for(i=0;i<word2.length()+1;i++){
            dp[i][0] = i;
        }
        for(i=0;i<word1.length()+1;i++){
            dp[0][i] = i;
        }
        for(i=1;i<word2.length()+1;i++){
            for(j=1;j<word1.length()+1;j++){
                if(word2[i-1]==word1[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[word2.length()][word1.length()];
    }
};