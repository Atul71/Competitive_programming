class Solution {
public:
    int calculate(string s) {
        int i,res = 0, tmp = 0, k;
        char sign = '+';
        stack <int> mystack;
        
        for(i=0;i<s.length();i++){
            if(isdigit(s[i])){
                tmp = tmp*10+(s[i]-'0');
                
            }
            if((!isdigit(s[i])&&!isspace(s[i]))||i==s.length()-1){
              //  cout<<tmp;
                if(sign=='+')
                    mystack.push(tmp);
                else if(sign=='-')
                    mystack.push(-tmp);
                else{
                    if(sign=='*'){
                        k = tmp*mystack.top();
                        mystack.pop();
                        mystack.push(k);
                        }
                    else if(sign=='/'){
                        k = mystack.top()/tmp;
                        mystack.pop();
                        mystack.push(k);
                    }
                }
                sign = s[i];
                
                tmp = 0;
            }
             
        }
        while(!mystack.empty()){
            res = res+mystack.top();
            mystack.pop();
        }
        return res;
    }
};