//         j++;
//     }
//     cout<<endl;
// }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
vector<TreeNode *> k;
vector<vector<TreeNode *>> res;
traverse(root,k,p,q,res);
int i=0;
TreeNode *z=res[0][0];
int j=0;
i=0;
j=0;
while(i<res[0].size()&&j<res[1].size()){
cout<<res[0][i]->val<<" "<<res[1][j]->val<<endl;
if(res[0][i]!=res[1][j]){
break;
}
else{
z=res[0][i];
}
i++;
j++;
}
return z;
}
};