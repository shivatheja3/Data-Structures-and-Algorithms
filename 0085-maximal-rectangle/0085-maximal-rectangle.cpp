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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> a(matrix[0].size(),0);
        int ans=0;
        
        for(int i=0;i<matrix[0].size();++i){
            a[i]=matrix[0][i]=='0'?0:1;
        }
        ans=max(ans,largestRectangleArea(a));
        for(int i=1;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][j]=='1') a[j]++;
                else a[j]=0;
            }
            ans=max(ans,largestRectangleArea(a));
        }
        return ans;
    }
};