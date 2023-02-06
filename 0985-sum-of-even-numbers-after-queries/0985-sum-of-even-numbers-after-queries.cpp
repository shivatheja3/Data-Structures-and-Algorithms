class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int evenSum=0;
        for(int i=0;i<nums.size();++i){
            if((nums[i]&1)==0){
                evenSum+=nums[i];
            }
        }
        for(int i=0;i<queries.size();++i){
            int a=queries[i][0];
            int b=queries[i][1];
            if(((nums[b]>0)?nums[b]:(-nums[b]))%2==0){
                if((a>0?a:(-a))%2==1){
                    evenSum-=nums[b];
                    cout<<evenSum<<" "<<i<<endl;
                    nums[b]+=a;
                }
                else{
                    evenSum-=nums[b];
                    nums[b]+=a;

                    evenSum+=nums[b];
                                    cout<<evenSum<<" "<<i<<endl;;

                }
                cout<<evenSum<<" "<<i<<endl;
                res.push_back(evenSum);
            }
            else{
                if(((a>0)?(a):(-a))%2==1){
                    nums[b]+=a;
                    evenSum+=nums[b];
                res.push_back(evenSum);
                }
                else{
                    nums[b]+=a;
                     res.push_back(evenSum);
                }
            }
        }
        return res;
    }
};