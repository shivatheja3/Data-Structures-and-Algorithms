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
    bool isEvenOddTree(TreeNode* root) {
        int control=1;
        vector<TreeNode *> q1,q2;
        vector<vector<int>> res;
        vector<int> cL;
        q1.insert(q1.begin(),root);
        if(q1[0]->val%2==0){
            return false;
        }
        while(q1.size()!=0||q2.size()!=0){
            if(control==1){
                if(q1[0]->left){
                    if(q1[0]->left->val%2==1){
                        return false;
                    }
                    q2.insert(q2.end(),q1[0]->left);
                }
                if(q1[0]->right){
                    if(q1[0]->right->val%2==1){
                        return false;
                    }
                    q2.insert(q2.end(),q1[0]->right);
                }
                cL.push_back(q1[0]->val);
                q1.erase(q1.begin());
                if(q1.size()==0){
                    control=2;
                    res.push_back(cL);
                    for(int i=0;i<(cL.size()-1);++i){
                        cout<<cL[i]<<" "<<cL[i+1]<<" ";
                        if(cL[i]>=cL[i+1]){
                            cout<<"false"<<endl;
                            return false;
                        }
                    }
                    cout<<endl;
                    // if(cL.size()>1){
                    //     for(int i=0;i<(cL.size()-1);++i){
                    //         if(cL[i]<cL[i+1]){
                    //             return false;
                    //         }
                    //     }
                    // }
                    cL={};
                }
            }
            else{
                if(q2[0]->left){
                    if(q2[0]->left->val%2==0){
                        return false;
                    }
                    q1.insert(q1.end(),q2[0]->left);
                }
                if(q2[0]->right){
                    if(q2[0]->right->val%2==0){
                        return false;
                    }
                    q1.insert(q1.end(),q2[0]->right);
                }
                cL.push_back(q2[0]->val);
                q2.erase(q2.begin());
                if(q2.size()==0){
                    control=1;
                    for(int i=0;i<(cL.size()-1);++i){
                        // cout<<cL[i]<<" ";
                        cout<<cL[i]<<" "<<cL[i+1]<<" ";
                        if(cL[i]<=cL[i+1]){
                            cout<<"false"<<endl;
                            return false;
                        }
                    }
                    cout<<endl;
                    // if(cL.size()>1){
                    //     for(int i=0;i<(cL.size()-1);++i){
                    //         if(cL[i]>cL[i+1]){
                    //             return false;
                    //         }
                    //     }
                    // }
                    res.push_back(cL);
                    cL={};
                }
            }
        }
        // for(int i=0;i<res.size();++i){
        //     for(int j=0;j<res[i].size();++j){
        //         cout<<res[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return true;
    }
};