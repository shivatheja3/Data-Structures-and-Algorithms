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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q1,q2;
        q1.push(root);
        int m=2;
        int m1=INT_MIN;
        int sum1=0;
        int l=1;
        int ans=1;
        TreeNode *temp=NULL;
        while(q1.size()!=0||q2.size()!=0){
            if(m==1){
                temp=q2.front();
                q2.pop();
                sum1+=temp->val;
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
                // cout<<sum1<<" "<<l<<endl;
                if(q2.size()==0){
                    m=2;
                    if(sum1>m1){
                        m1=sum1;
                        
                        ans=l;
                    }
                    sum1=0;
                    ++l;
                }
                
            }
            else{
                temp=q1.front();
                q1.pop();
                // cout<<temp->val<<endl;
                sum1+=temp->val;
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
                // cout<<sum1<<" "<<l<<endl;
                if(q1.size()==0){
                    m=1;
                    if(sum1>m1){
                        m1=sum1;
                        
                        ans=l;
                    }
                    sum1=0;
                    ++l;
                }
                cout<<m1<<" "<<l<<endl;
            }
        }
        return ans;
    }
};