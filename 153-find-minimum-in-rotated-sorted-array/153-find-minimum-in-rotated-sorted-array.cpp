class Solution {
public:
    int findMin(vector<int>& a) {
        if(a.size()==1){
            return a[0];
        }
        if(a.size()==2){
            if(a[0]>a[1]){
                return a[1];
            }
            return a[0];
        }
        if(a.size()==3){
            if(a[0]<=a[1]&&a[0]<=a[2]){
                return a[0];
            }
            else if(a[1]<=a[2]&&a[1]<=a[0]){
                return a[1];
            }
            return a[2];
        }
        int l=0;
        int r=a.size()-1;
        int m=(l+r)/2;
        
        while(l<=r){
            m=(l+r)/2;
            cout<<"m="<<m<<" l="<<l<<" r="<<r<<endl;
            // cout<<(l==r)<<endl;
            if(l==r){
                cout<<"yes";
                return a[m];
            }
            if(m==0){
                if(a[m]<a[m+1]&&a[m]<a[r]){
                    return a[m];
                }
                else{
                    return a[m+1];
                }
            }
            if(m==a.size()-1){
                if(a[m]<a[m-1]&&a[m]<a[0]){
                    return a[m];
                }
            }
            if(a[m]<a[m-1]&&a[m]<a[m+1]){
                return a[m];
            }
            else if(a[l]<=a[m-1]){
                if(a[l]>a[r]&&a[m]>a[r]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            else if(a[m+1]<=a[r]){
                if(a[r]<a[l]&&a[m-1]<=a[m+1]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return 0;
    }
};