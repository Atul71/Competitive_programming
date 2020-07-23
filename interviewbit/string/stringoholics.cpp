#define m 1000000007
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int km(string &A){
    int i, j;
    i = 0;
    vector <int> kmp(A.size());
    kmp[0] = 0;
    
    for(j=1;j<A.size();j++){
        if(A[i]==A[j]){
            i++;
            kmp[j] = i;        
        }
        else{
            
            while(i!=0){
                i = kmp[i-1];
                if(A[i]==A[j]){
                    i++;
                    kmp[j] = i;
                    break;
                }
            }
                if(i==0){
                    kmp[j] = 0;
                }
            
        }
    }
    
    return kmp[A.size()-1];
}
int Solution::solve(vector<string> &A) {
    int i,j,n,l,left = 1;
    long long ans = 1, sum,k;
    vector <long long int> res(A.size());
    
    for(i=0;i<A.size();i++){
        l = km(A[i]);
        n = A[i].size();
        if(n==1){
            res[i] = 1;
            continue;
        }
        if(n%(n-l)==0)
            n = n-l;
        for(k=1; (k*(k+1)/2) % n != 0; k++);
        
        res[i] = k;
    }
    
 //   ans = res[0];
    for(int i=0; i<res.size(); i++)
    {
        for(int j=i+1; j<res.size(); j++)
            res[j] = res[j]/__gcd(res[i], res[j]);
            
        ans = (ans*res[i])%m;
    }
    return ans;
}
