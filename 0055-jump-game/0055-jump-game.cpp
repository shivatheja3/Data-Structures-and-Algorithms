class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        else if(nums.size()==2){
            if(nums[0]==0)
                return false;
            else
                return true;
        }
        for(int i=0;i<(nums.size()-1);++i){
            int max1=0;
            int nextInd=-1;
            for(int j=(i+1);j<=(nums[i]+i);++j){
                if(j==(nums.size()-1)){
                    return true;
                }
                if((nums[j]+j)>max1){
                    cout<<j<<" "<<j<<" "<<nums[j]<<endl;
                    max1=nums[j]+j;
                    nextInd=j;
                }
            }
            if(nextInd!=(-1)){
                cout<<nextInd<<endl;
                i=nextInd;
                --i;
            }
            else{
                return false;
            }
        }
        return false;
    }
};