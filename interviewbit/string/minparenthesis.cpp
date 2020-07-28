nt Solution::solve(string A) {
   
    int open = 0,i,close=0;
    for(i=0;i<A.size();i++){
        if(A[i]=='(')
            open++;
        else{
            if(open>0)
                open--;
            else
                close++;
        }
    }
    return close+open;
}
