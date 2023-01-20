class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long res=0;
        // for(int i=0;i<nums.size();++i){
        //     long long sum1=0;
        //     for(int j=i;j<nums.size();++j){
        //         sum1+=nums[j];
        //         if(sum1%k==0){
        //             ++res;
        //         }
        //     }
        // }
        long long sum1=0;
        unordered_map<int,int> h1;
        for(int i=0;i<nums.size();++i){
            sum1+=nums[i];
            h1[(sum1%k+k)%k]++;
        }
        
        for(auto i:h1){
            if(i.first==0){
                res+=(i.second)*(i.second-1)/2+i.second;
            }
            else{
                 res+=(i.second)*(i.second-1)/2;
            }
        }
        return res;
    }
};