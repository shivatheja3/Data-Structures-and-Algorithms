class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size()-2;
        double res=0;
        for(int i=0;i<salary.size();++i){
            res+=salary[i];
        }
        res-=*min_element(salary.begin(),salary.end());
        res-=*max_element(salary.begin(),salary.end());
        return res/n;
    }
};