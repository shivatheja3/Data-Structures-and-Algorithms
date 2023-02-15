class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        int rem=0;
        while(k){
            if(i>=0){
                int x=rem+k%10+num[i];
                num[i]=x%10;
                --i;
                rem=x/10;
                k/=10;
            }
            else{
                int x=rem+k%10;
                num.insert(num.begin(),x%10);
                rem=x/10;
                k/=10;
            }
        }
        for(int j=i;j>=0&&rem!=0;--j){
            int x=num[j]+rem;
            num[j]=x%10;
            rem=x/10;
        }
        if(rem!=0){
            num.insert(num.begin(),rem);
        }
        return num;
    }
};