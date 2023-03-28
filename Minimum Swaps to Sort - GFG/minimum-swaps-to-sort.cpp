//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> temp=nums;
	    sort(temp.begin(),temp.end());
	    unordered_map<int,int> h1;
	    for(int i=0;i<temp.size();++i){
	        h1[nums[i]]=i;
	    }
	    int c=0;
	    for(int i=0;i<nums.size();++i){
	        if(nums[i]!=temp[i]){
	           // cout<<i<<" "<<c<<endl;
	            int ind=h1[temp[i]];
	            int te=nums[i];
	            nums[i]=nums[ind];
	            nums[ind]=te;
	            h1[nums[i]]=i;
	            h1[nums[ind]]=ind;
	            ++c;
	            
	        }
	    }
	    return c;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends