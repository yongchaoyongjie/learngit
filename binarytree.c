#pragma  one
#include <stdlib.h>
#include <stdio.h>
typedef struct  Node{
  int val;
  struct Node *left;
  struct Node* right;
}Node;
void preorderTraversal(Node*root){
  //空树
  if(root==NULL){
  return ;
  }
//  //只有一个节点的树
//  if(root->right==NULL&&root->left==NULL){
//  printf("%d",root->val);
//  }
//  //只有根加左子树
//  if(root->right==NULL){
// printf("%d",root->val) ;
// preorderTraversal(root->left);
//  }
////只有根+右子树
//if(root->left==NULL){
//printf("%d",root->val);
//preorderTraversal(root->right);//左子树遍历
//}
////根+左子树+右子树
//else{
//printf("%d",root->val);
//preorderTraversal(root->left);
//preorderTraversal(root->right);
//}
////化简打印除了为空都不需要所以可以放在最前面
////只要左子树不为空都需要遍历左子树同样只要右子树不为空需要遍历右子树,
////所以化解结果如下
//printf("%d",root->val);
//if(root->left!=NULL){
//  preorderTraversal(root->left);
//}else{
//  preorderTraversal(NULL);//左子树为空
//}
//if(root->right!=NULL){
//  preorderTraversal(root->right);
//}else{
//  preorderTraversal(NULL);
//}
//所以可以简化为:
printf("%d",root->val);
preorderTraversal(root->left);
preorderTraversal(root->right);
//根+左子树+右子树为前序打印
}
void inorderTraversal(Node*root){
//左子树+根+右子树:为中序打印
  if(root==NULL){
    return ;
  }
inorderTraversal(root->left);
printf("%d",root->val);
inorderTraversal(root->right);
}
void postorderTraversal(Node*root){
  //左子树+右子树+根:为后序打印
  if(root==NULL){
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d",root->val);
}
//求一下树中的结点个数利用遍历方式求解,遇到一个非空的结点cout++
int cout=0;
void Size(Node*root){
  if(root==NULL){
    return ;
  }else{
    //用前序进行计算二叉树的结点数
    //cout++;
  //  Size(root->left);
   // Size(root->right);
   // 用中序进行计算结点数为:
//   Size(root->left);
 // cout++;
  //Size(root->right);
//用后序计算结点数
Size(root->left);
Size(root->right);
cout++;
  }
}
//法2另一种求结点个数,利用递归1:找递推公式2找 终止条件
//1找递推公式怎么找?假设已知左子树的结点个数为left,右子树的结点个数为right
//整颗数的结点个数=left+right+1;
//2终止条件往往是从树的前两种形态考虑(1)空树 return0;个结点
//(2)一个节点return1;这个可以写可以不写可以看成0个左子树和0个右子树0+0+1
int Size1(Node*root){
  if(root==NULL){
    return 0;
  }
  return Size1(root->left)+Size1(root->right)+1;
//左+右+根为后序
//return Size1(root->left)+1+Size1(root->right),中序,左+根+右
//return 1+Size1(root->left)+Size1(root->right);//前序,根+左+右
//写的时候局部站定理解的时候全局思考
}
