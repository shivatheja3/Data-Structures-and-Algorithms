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
class Solution {
public:
    void findSum(TreeNode *p,string temp,int &res){
        if(p){
            if(p->left==NULL&p->right==NULL){
                temp=temp+to_string(p->val);
                long long x=0;
                for(int i=0;i<temp.size();++i){
                    x=x*10+temp[i]-48;
                }
                res+=x;
            }
            findSum(p->left,temp+to_string(p->val),res);
            findSum(p->right,temp+to_string(p->val),res);
        }
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        string temp="";
        findSum(root,temp,res);
        return res;
    }
};