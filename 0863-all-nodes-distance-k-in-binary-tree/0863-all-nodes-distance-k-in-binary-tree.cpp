class Solution {
public:
    void Traverse(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>> &h1){
        if(!root)
            return;
        h1[root]={};
        Traverse(root->left,h1);
        Traverse(root->right,h1);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,vector<TreeNode *>> h1;
        Traverse(root,h1);
        queue<TreeNode *> q1;
        q1.push(root);
        TreeNode *x=NULL;
        while(q1.size()!=0){
            x=q1.front();
            q1.pop();
            if(x->left){
                h1[x].push_back(x->left);
                h1[x->left].push_back(x);
                q1.push(x->left);
            }
            if(x->right){
                h1[x].push_back(x->right);
                h1[x->right].push_back(x);
                q1.push(x->right);
            }
        }
        q1={};
        q1.push(target);
        queue<TreeNode *> q2;
        int control=2;
        int c=0;
        unordered_map<TreeNode *,int> h2;
        vector<int> res;
        while(q1.size()!=0||q2.size()!=0){
            if(control==1){
                if(c==k){
                    while(q2.size()!=0){
                        res.push_back(q2.front()->val);
                        q2.pop();
                    }
                    return res;
                }
                x=q2.front();
                h2[x]=1;
                // cout<<x->val<<endl;
                q2.pop();
                if(q2.size()==0){
                    control=2;
                    ++c;
                }
                for(int i=0;i<h1[x].size();++i){
                    if(h2[h1[x][i]]!=1){
                        q1.push(h1[x][i]);
                    }
                }
            }
            else{
                if(c==k){
                    while(q1.size()!=0){
                        res.push_back(q1.front()->val);
                        q1.pop();
                    }
                    return res;
                }
                x=q1.front();
                h2[x]=1;
                // cout<<x->val<<endl;
                q1.pop();
                if(q1.size()==0){
                    control=1;
                    ++c;
                }
                for(int i=0;i<h1[x].size();++i){
                    if(h2[h1[x][i]]!=1){
                    q2.push(h1[x][i]);
                        }
                }
            }
        }
        return res;
    }
};