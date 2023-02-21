class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1){
            return a[0];
        }
        else if(a.size()==3){
            if(a[0]==a[1]){
                return a[2];
            }
            else{
                return a[0];
            }
        }
        else{
            if(a[0]!=a[1]){
                return a[0];
            }
            if(a[a.size()-1]!=a[a.size()-2]){
                return a[a.size()-1];
            }
            int l=0,r=a.size()-1,m;
        m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(a[m]==a[m+1]){
                if((r-m+1)%2==0){
                    r=m-1;
                }
                else{
                    l=m+2;
                }
            }
            else if(a[m]==a[m-1]){
                if((m-l+1)%2!=0){
                    r=m-2;
                }
                else{
                    l=m+1;
                }
            }
            else{
                return a[m];
            }
        }
        return a[m];
        }
    }
};