class Solution {
public:
    int myAtoi(string str) {
        
        int i = 0, sub = 0;
        long long int result = 0, check = 0;
        
        while(i<str.length()){
            if(str[i]==' ')
                i++;
            else
                break;
        }
        if(str.length()==0)
            return 0;
        
        if(str[i]=='+')
            i++;
        else if(str[i]=='-'){
            i++;
            sub = 1;
        }
        
        while(i<str.length()){
            if(str[i]>='0' && str[i]<='9'){
                result = result*10 + (str[i]-'0');
                if(result>INT_MAX && sub!=1)
                    return INT_MAX;
                else if(sub==1){
                    check = 0-result;
                    if(check<INT_MIN)
                    return INT_MIN;
                }
            }
            else
                break;
            i++;
        }
        if(result==0)
            return 0;
        
        if(sub==1)
            result = 0-result;
        
         
        return result;
    }
};