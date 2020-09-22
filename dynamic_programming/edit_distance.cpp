class Solution {
public:
    int min(int x , int y, int z){
        if(x<y){
            if(x<z){
                return x;
            }
            else{
                return z;
            }
        }
        else{
            // y is smaller
            if(y<z){
                return y;
            }
            else{
                return z;
            }
        }
    }
    int minDistance(string word1, string word2) {
        //ed[i][j]= min number of operations required to convert word1[i] to word2[j]
        //ed[i]
        int m = word1.size();
        int n = word2.size();
        
        int idx1=-1,idx2=-1;
        bool found1=false,found2=false;
        if(m==0 && n==0){
            return 0;
        }
        else{
            if(m==0){
                return n;
            }
            else if(n==0){
                return m;
            }
        }
        int ed[m][n];
        if(m>=1){
            for(int idx=0;idx<n;idx++){
                if(word1[0]==word2[idx]){
                    idx1=idx;
                    found1= true;
                }
                if(idx1>=0){
                    ed[0][idx]=idx;
                }
                else{
                    ed[0][idx]=idx+1;
                }
            }
            for(int idx=0;idx<m;idx++){
                if(word1[idx]==word2[0]){
                    idx2=idx;
                    found2= true;
                }
                if(idx2>=0){
                    ed[idx][0]=idx;
                }
                else{
                    ed[idx][0]=idx+1;
                }
                //if(found1 == true && found2== true){
                  //  break;
                //}
            }
        }
        //actual logic
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int tmp = (word1[i]==word2[j]?ed[i-1][j-1]:ed[i-1][j-1]+1);
                ed[i][j]=min(tmp,
                             (ed[i-1][j]+1),(ed[i][j-1]+1));
               // cout<<"tmp|i-1,j|i,j-1|i,j"<<tmp<<","<<ed[i-1][j]<<","<<ed[i][j-1]<<","     <<ed[i][j]<<std::endl;
            }
        }
        return ed[m-1][n-1];
    }
};
