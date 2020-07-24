int Solution::solve(vector<int> &A) {
    
    stack <int> s;
    int i,root = INT_MIN;
    
    for(i=0;i<A.size();i++){
        if(A[i] < root)
            return 0;
        while(!s.empty() && A[i]>s.top()){
            root = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return 1;
    
}
