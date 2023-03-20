class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int c=n;
        for(int i=0;i<arr.size();++i){
            if(c<=0){
                return true;
            }
            if(arr[i]==1){
                ++i;
                continue;
            }
            else{
                if(i>=1){
                    if(i<(arr.size()-1)){
                        if(arr[i-1]==0&&arr[i+1]==0){
                            arr[i]=1;
                            c--;
                         }
                        else{
                            continue;
                        }
                    }
                    else{
                        if(arr[i-1]==0){
                            arr[i]=1;
                             c--;
                        }
                        
                    }
                }
                else{
                    if(i<(arr.size()-1)){
                        if(arr[i+1]==0){
                             arr[i]=1;
                             c--;
                        }
                    }
                    else{
                        arr[i]=1;
                        c--;
                    }
                    
                }
            }
        }
        if(c<=0)
            return true;
        return false;
    }
};