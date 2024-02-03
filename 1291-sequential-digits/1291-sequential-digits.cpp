class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a;
        a.push_back(12);
        a.push_back(123);
        a.push_back(1234);
        a.push_back(12345);
        a.push_back(123456);
        a.push_back(1234567);
        a.push_back(12345678);
        a.push_back(123456789);
        vector<int> res;
        int a1=11;
        for(int i=0;i<a.size();++i){
            int x=a[i];
            
            while(x<=high){
                if(x>=low&&x<=high){
                    res.push_back(x);
                    
                }
                if(x%10==9) break;
                else if(x>high){
                    break;
                }
                x+=a1;
                // cout<<x<<endl;
            }
            a1=a1*10+1;
        }
        return res;
    }
};