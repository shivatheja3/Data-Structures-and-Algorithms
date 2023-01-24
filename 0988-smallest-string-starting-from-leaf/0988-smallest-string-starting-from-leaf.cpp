/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
class Solution {
public:
    void findString(TreeNode *p,string &res,string temp,vector<string> &res1){
        if(p){
            if(p->left==NULL&&p->right==NULL){
                char s1='a'+p->val;
                // string s1=temp+'a'+p->val;
                res1.push_back(temp+s1);
        }
        char t='a'+p->val;
        findString(p->left,res,temp+t,res1);
        findString(p->right,res,temp+t,res1);
        }
    }
    void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
  
}
    string smallestFromLeaf(TreeNode* root) {
        string res="",temp="";
        vector<string> res1;
        findString(root,res,temp,res1);
        for(int i=0;i<res1.size();++i){
            reverseStr(res1[i]);   
            cout<<res1[i]<<endl;
        }
        // cout<<res1[0]<<endl;
        temp=res1[0];
        for(int i=1;i<res1.size();++i){
            // cout<<res1[i]<<" ";
            if(temp>res1[i]){
                temp=res1[i];
            }
        }
        cout<<endl;
        return temp;
    }
};