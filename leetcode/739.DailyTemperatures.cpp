class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> daily(T.size(),0);
        map <int,int> m;
        stack <int> s;
        int i,j=0;
        for(i=0;i<T.size();i++){
            
            while(!s.empty() && T[i]>T[s.top()]){
                daily[s.top()] = i-s.top();
                
                s.pop();
                
            }
            j++;
            s.push(i);
        }
        return daily;
    }
};