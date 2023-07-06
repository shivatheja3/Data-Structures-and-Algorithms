class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int sum1=0;
        int f=0,l=0;
        for(int i=0;i<nums.size();++i){
            sum1+=nums[i];
            l=i;
            if(sum1>=target){
                while(f<=l&&sum1>=target){
                    if(sum1>=target){
                        res=min(res,l-f+1);
                    }
                    sum1-=nums[f++];
                    
                     // cout<<sum1<<" "<<res<<endl;
                    
                }
                // res=min(res,l-f+1);
               
                // f=l+1;
                // l++;
                // sum1=0;
            }
        }
        
        return res==INT_MAX?0:res;
    }
};