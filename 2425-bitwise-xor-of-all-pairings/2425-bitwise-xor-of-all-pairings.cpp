class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        int n1=nums1.size(),n2=nums2.size();
        if((n1%2==0)&&(n2%2==0)){
            return 0;
        }
        else if(n1&1==1&&n2&1==1){
            for(int i=0;i<nums1.size();++i){
                res^=nums1[i];
            }
            for(int i=0;i<nums2.size();++i){
                res^=nums2[i];
            }
            return res;
        }
        else{
            if(n1&1==1){
                for(int i=0;i<nums2.size();++i){
                    res^=nums2[i];
                }
                return res;
            }
            else{
                for(int i=0;i<nums1.size();++i){
                    res^=nums1[i];
                }
                return res;
            }
        }
        return res;
    }
};