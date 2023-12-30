class Solution {
public:
    void func1(vector<int> &nextSmaller,vector<int>& heights){
        stack<int> st;
        for(int i=(heights.size()-1);i>=0;--i){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.size()>0)
                nextSmaller[i]=st.top()-1;
            st.push(i);
        }
    }
    void func2(vector<int> &prevSmaller,vector<int>& heights){
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<n;++i){
            while(st.size()>0&&heights[st.top()]>=heights[i])
                st.pop();
            if(st.size()>0)
                prevSmaller[i]=st.top()+1;
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nextSmaller(n,heights.size()-1),prevSmaller(n,0);
        func1(nextSmaller,heights);
        func2(prevSmaller,heights);
        int maxAns=*max_element(heights.begin(),heights.end());
        for(int i=0;i<n;++i)
            maxAns=max(maxAns,heights[i]*(nextSmaller[i]-prevSmaller[i]+1));
        return maxAns;
    }
};



// next smaller element
// stack<int> st;
//         vector<int> res(arr.size(),-1);
//         for(int i=(arr.size()-1);i>=0;--i){
//             while(st.size()>0&&arr[i]<=st.top()){
//                 st.pop();
//             }
//             res[i]=(st.size()==0?(-1):st.top());
//             st.push(arr[i]);
//         }
//         return res;



// previous small element
// vector<int> help_classmate(vector<int> arr, int n) 
//     { 
//         // Your code goes here
//         stack<int> st;
//         vector<int> res(arr.size(),-1);
//         for(int i=0;i<n;++i){
//             while(st.size()>0&&arr[i]<=st.top()){
//                 st.pop();
//             }
//             res[i]=(st.size()==0?(-1):st.top());
//             st.push(arr[i]);
//         }
//         return res;
//     } 