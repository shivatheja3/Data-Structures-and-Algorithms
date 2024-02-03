class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int> st;
        vector<int> arr1(2*arr.size(),-1);
        for(int i=0;i<arr.size();++i){
            arr1[i]=arr[i];
            arr1[i+arr.size()]=arr[i];
        }
        vector<int> res(arr1.size(),-1);
        for(int i=(arr1.size()-1);i>=0;--i){
            while(st.size()>0&&arr1[i]>=st.top()){
                st.pop();
            }
            res[i]=(st.size()==0?(-1):st.top());
            st.push(arr1[i]);
        }
        vector<int> r;
        for(int i=0;i<arr.size();++i){
            r.push_back(res[i]);
        }
        return r;
    }
};
// class Solution
// {
//     public:
//     //Function to find the next greater element for each element of the array.
//     vector<long long> nextLargerElement(vector<long long> arr, int n){
//         // Your code here
//         stack<long long> st;
//         vector<long long> res(arr.size(),-1);
//         for(long long i=(arr.size()-1);i>=0;--i){
//             while(st.size()>0&&arr[i]>=st.top()){
//                 st.pop();
//             }
//             res[i]=(st.size()==0?(-1):st.top());
//             st.push(arr[i]);
//         }
//         return res;
//     }
// };