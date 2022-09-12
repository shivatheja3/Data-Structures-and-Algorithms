class Solution {
public:
    void traverse(TreeNode *p,vector<int> &status1){
        if(p){
            status1.push_back(p->val);
            traverse(p->left,status1);
            traverse(p->right,status1);
        }
    }
    void traverse(TreeNode *p,TreeNode *q,vector<int> &status){
        if(p&&q){
            status.push_back(q->val);
            traverse(p->left,q->left,status);
            traverse(p->right,q->right,status);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL&&q!=NULL){
            return false;
        }
        vector<int> status,status1,status2;
        traverse(p,q,status);
        traverse(p,status1);
        traverse(q,status2);
        if(status.size()!=status1.size()||status.size()!=status2.size()){
            return false;
        }
        int i=0;
        int j=0;
        while(i<status.size()&&j<status1.size()){
            cout<<status[i]<<" "<<status1[j]<<endl;
            if(status[i]!=status1[j]||status[i]!=status2[j]){
                return false;
            }
            ++i;
            ++j;
        }
        
        return true;
    }
};