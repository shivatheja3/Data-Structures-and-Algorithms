class Solution {
public:
    int maxArea(vector<int>& h) {
        int left=0,right=h.size()-1;
        int max1=0;
        while(left<right){
            if((right-left)*min(h[left],h[right])>max1){
                max1=(right-left)*min(h[left],h[right]);
            }
            if(h[left]<h[right]) left++;
            else right--;
        }
        return max1;
    }
};