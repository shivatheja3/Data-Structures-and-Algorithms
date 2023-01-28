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
    void f(TreeNode *p,unordered_map<int,vector<pair<int,int>>> &h1,int v,int &min1,int &max1,int d){
        if(p==NULL) return;
        h1[v].push_back({d,p->val});
        min1=min(v,min1);
        max1=max(v,max1);
        f(p->left,h1,v-1,min1,max1,d+1);
        f(p->right,h1,v+1,min1,max1,d+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int v=0,d=0;
        unordered_map<int,vector<pair<int,int>>> h1;
        TreeNode *p=root;
        int min1=100001;
        int max1=-100001;
        f(p,h1,v,min1,max1,d);
        vector<vector<int>> res1;
        // for(auto i:h1){
        //     res1.push_back(i.second);
        // }
        // cout<<min1<<" "<<max1<<endl;
        for(int i=min1;i<=max1;++i){
            sort(h1[i].begin(),h1[i].end());
            // res1.push_back(h1[i]);
            vector<int> r;
            for(int j=0;j<h1[i].size();++j){
                r.push_back(h1[i][j].second);
            }
            res1.push_back(r);
        }
        
        return res1;
    }
};