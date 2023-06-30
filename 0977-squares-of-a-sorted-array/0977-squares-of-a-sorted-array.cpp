class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp1,temp2;
        int c1=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0)
                temp1.push_back(nums[i]);
            else
                temp2.push_back(nums[i]);
        }
        for(int i=0;i<temp1.size();++i){
            temp1[i]=temp1[i]*temp1[i];
        }
        reverse(temp1.begin(),temp1.end());
        for(int i=0;i<temp2.size();++i){
            temp2[i]=temp2[i]*temp2[i];
        }
        int p1=0,p2=0;
        int c=0;
        while(p1<temp1.size()&&p2<temp2.size()){
            if(temp1[p1]<temp2[p2])
                nums[c++]=temp1[p1++];
            else
                nums[c++]=temp2[p2++];
        }
        while(p1<temp1.size()){
            nums[c++]=temp1[p1++];
        }
        while(p2<temp2.size()){
            nums[c++]=temp2[p2++];
        }
        return nums;
    }
};