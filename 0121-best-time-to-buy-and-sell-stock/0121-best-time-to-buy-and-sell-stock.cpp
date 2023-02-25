class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min1=prices[0];
        int i;
        int pr=0;
        for(i=1;i<prices.size();i++){
            if(prices[i]<min1){
                min1=prices[i];
            }
            else{
                if(prices[i]>pr+min1){
                    pr=prices[i]-min1;
                }
            }
        }
        return pr;
    }
};