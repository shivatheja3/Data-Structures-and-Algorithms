class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int i=0,j=n,k=0;
        while(k<2*n){
            res.push_back(nums[i++]);
            res.push_back(nums[j++]);
            k++;
            k++;
        }
        for(i=0;i<2*n;i++){
            nums[i]=res[i];
        }
        return nums;
    }
};