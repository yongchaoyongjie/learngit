#include<iostream>
#include <stack>
using namespace std;
struct TreeNode{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
  public:
    bool getpath(TreeNode*root,TreeNode*x,stack<TreeNode>&path1){
      if(root==nullptr) {
        return false;
      }
      path1.push(root);
      if(root==x){
return true;
      }
      if(getpath(root->left,x,path1)==true){
return true;
      }
      if(getpath(root->right,x,path1)==true){
return true;
      }
      path1.pop();
    }
    TreeNode*zuijingonggongzuxian(TreeNode*root,TreeNode*p,TreeNode*q){
stack<TreeNode*>ppath;
stack<TreeNode*>qpath;
getpath(root,p,ppath);
getpath(root,q,qpath);
while(ppath.size()!=qpath.size()){
  if(ppath.size()>qpath.size()){
    ppath.pop();
  }
  else
    qpath.pop();
  }
  while(ppath.top()!=qpath.top()){
    ppath.pop();
    qpath.pop();
  }
    }
};
