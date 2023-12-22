class Solution {
public:
    int maxScore(string s) {
        int left=0;
        int right=0;
        int m1=0;
        int n=s.size()-1;
        left+=(s[0]=='0')?1:0;
        for(int i=1;i<n+1;++i)
            if(s[i]=='1') right++;
        m1=max(m1,left+right);
        int i=1;
        while(i<n){
            if(s[i]=='0'){
                left++;
            }
            else{
                right--;
            }
            i++;
            m1=max(m1,left+right);
        }
        return m1;
    }
};