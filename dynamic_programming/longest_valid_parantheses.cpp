class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stor;
        for(int tmpIdx=0; tmpIdx<s.length();tmpIdx++){
            if(s[tmpIdx]=='('){
                stor.push_back(0);
            }
            else{
                if(tmpIdx>=1){ 
                   if(s[tmpIdx-1]=='('){
                       int tmpVal=0;
                       if(tmpIdx>=2)
                           tmpVal = stor[tmpIdx-2];
                       stor.push_back(2+tmpVal);
                   }
                   else if(s[tmpIdx-1]==')'){
                        if((tmpIdx>=1+stor[tmpIdx-1]) && (s[tmpIdx-1-stor[tmpIdx-1]]=='(')){
                            int tmpVal=0;
                            if(tmpIdx>=stor[tmpIdx-1]+2){
                                tmpVal = stor[tmpIdx-1-stor[tmpIdx-1]-1];
                            }
                            stor.push_back(stor[tmpIdx-1]+2+tmpVal);
                        }
                        else{
                            stor.push_back(0);
                        }
                   }
               }
                else{
                    stor.push_back(0);
                }
            }
        }
        int max=0;
        for(int idx=0;idx<stor.size();idx++ ){
            if(stor[idx]>max)
                max=stor[idx];
        }
        return max;
   }
};
