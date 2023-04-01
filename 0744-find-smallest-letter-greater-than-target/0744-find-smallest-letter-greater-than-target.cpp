class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int a=target+1;
        // cout <<a<<endl;
        int l=0,h=letters.size()-1;
        int m=(l+h)/2;
        char res=letters[0];
        while(l<=h){
            m=(l+h)/2;
            if(letters[m]>=a){
                res=letters[m];
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};