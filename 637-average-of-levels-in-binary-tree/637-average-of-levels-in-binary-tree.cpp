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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> res;
        vector<double> res1;
        vector<TreeNode *> q;
        q.insert(q.begin(),root);
        while(q.size()!=0){
            int s=q.size();
            vector<int> cL;
            for(int i=0;i<s;i++){
                int a=q[0]->val;
                if(q[0]->left){
                    q.insert(q.end(),q[0]->left);
                }
                if(q[0]->right){
                    q.insert(q.end(),q[0]->right);
                }
                q.erase(q.begin());
                cL.push_back(a);
            }
            res.push_back(cL);
        }
        for(int j=0;j<res.size();j++){
            double sum1=0;
            for(int k=0;k<res[j].size();k++){
                sum1+=res[j][k];
            }
            res1.push_back(sum1/res[j].size());
        }
        return res1;
    }
};