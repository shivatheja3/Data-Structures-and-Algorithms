class Solution {
public:
    int trap(vector<int>& a) {
        // int mL,mR,c=0;
        // int n=a.size();
        // for(int i=1;i<(n-1);++i){
        //     mL=a[i];
        //     mR=a[i];
        //     for(int l=(i-1);l>=0;--l){
        //         if(a[l]>mL){
        //             mL=a[l];
        //         }
        //     }
        //     for(int r=(i+1);r<n;++r){
        //         if(a[r]>mR){
        //             mR=a[r];
        //         }
        //     }
        //     c+=min(mL,mR)-a[i];
        // }
        // return c;
        vector<int> ML,MR;
        ML.push_back(a[0]);
        MR.push_back(a[a.size()-1]);
        for(int i=1;i<a.size();++i){
            if(a[i]>ML[ML.size()-1]){
                ML.push_back(a[i]);
            }
            else{
                ML.push_back(ML[ML.size()-1]);
            }
        }
        for(int i=(a.size()-2);i>=0;--i){
            if(a[i]<MR[MR.size()-1]){
                MR.push_back(MR[MR.size()-1]);
            }
            else{
                MR.push_back(a[i]);
            }
        }
        reverse(MR.begin(),MR.end());
        int c=0;
        for(int i=1;i<(a.size()-1);++i){
            c+=min(ML[i],MR[i])-a[i];
            cout<<c<<endl;
        }
        return c;
    }
};