#include <stdio.h>
#include <stdlib.h>
//二叉树的前序遍历,放在array,必须malloc出来,
struct TreeNode{
  int val;
  struct TreeNode*left;
  struct TreeNode*right;
};
int *array;
int size;
typedef struct Node{
  struct Node *left;
  struct Node*right;
  char val;
}Node;
void preordre(struct TreeNode*root){
  if(root!=NULL){
    //前序遍历先处理根
    array[size++]=root->val;
    preordre(root->left);
    preordre(root->right);
  }
  }
void postorder(Node*root){
  //后序
  if(root!=NULL){
    postorder(root->left);
postorder(root->right);
printf("%c",root->val);
  }
}
int heightree(struct TreeNode*root){
//特殊情况没有结点和和只有一个节点
  if(root==NULL){//一个节点普通情况能包含
    return 0;
  }
int left=heightree(root->left)+1;
int right=heightree(root->right)+1;
return 1+(left>right?left:right);
}
//求第k层结点数
//求第三层求b的第二层+c的第二层
int getsize(struct TreeNode*root){
//特殊情况为空和一个节点
  if(root==NULL){
    return 0;
  }
  int left=getsize(root->left);
  int right=getsize(root->right);
return left+right+1;
}
int getleafsize(TreeNode*root){
//叶子结点就是最下面那个结点底下为空
//判断特殊情况
  if(root==NULL){
    return 0;
  }
  else if(root->left==NULL||root->right==NULL){
return 1;
  }
return getleafsize(root->left)+getleafsize(root->right);

}
int *preorderTraversal(struct TreeNode*root,int* returnsize){
  int *array=(int*)malloc(100*10000*sizeof(int));
  preordre(root);
*returnsize=size;
return array;
}
//普通二叉树的查找
//如果找到了返回v的地址如果没有找到返回空先去根找再找左子树最后又子树
Node*find(Node*root,char v){
  if(root==NULL){
    return NULL;
  }
  else if (root->val==v){
    return root;
}
Node*left1 =find(root->left,v);
if(left1!=NULL){
  return left1;//左子树找到
}
Node*right1=find(root->right,v);
  if(right1!=NULL){
    return right1;//又子树找到
  }
else{
  return NULL;//都没有找到
}
}
//中序和后序
//检查两个树是否是相同的树
//根一样每个节点都一样
//根相同左子树和左子树相同右子树和右子树相同就是相同的两个树
//一个为空不是相同的两个为空就是相同的二叉树
bool issametree(struct TreeNode*p,struct TreeNode*q){
  if(q==NULL&&p==NULL){
    return true;
  }
  if(p==NULL||q==NULL){
    return false;
  }
  return p->val=q->val&&
    issametree(p->left,q->left)
    &&issametree(p->right,q->right);
}
//镜像树轴对称
//bool ismirror()
  bool preordre1(struct TreeNode*root,struct TreeNode*t){
    if(issametree(root,t)){
      return true;
    }
      if(preordre1(root->left,t)==true){
        return true;
      }
      
      return preordre1(root->left,t);
    }
  
  //给定两个非空二叉树s和t,检验s中是否包含t具有相同的结构和结点值的子树.s的一个子树包括s的一个节点和这个结点的所有子孙,s也可以看做它自身的一颗子树
  //s树中是否有一个子树和t相等的树
  bool issuntree(struct TreeNode*s,struct TreeNode*t){
//树中的每个节点是不是相同的二叉树--前中后序
return preordre1(s,t);
  }
//左子树是平衡二叉树右子树为平衡二叉树并且左右子树高度差不超过1
int heigh(struct TreeNode*root){
  if(root==NULL){
    return 0;
  }
int left=heigh(root->left)+1;
int right=heigh(root->right)+1;
return left>right? left:right;
}
bool isbanlanced(struct TreeNode*root){
  if(root==NULL){
    return false;
  }
  if(isbanlanced(root->left)==false){
    return false;
  }
  if(isbanlanced(root->right)==false){
    return false;
  }
int left=heigh(root->left);
int right=heigh(root->right);
int dif=left-right;
if(dif>1||dif<-1){
  return false;
}
return true;
}
//如何构建二叉树
//前a序ABDF####C#E#G
TreeNode* creattree(char preorder[],int size,int *pused){
  if(size==0){
    *pused=0;
   return NULL;
  }
  else if(preorder[0]=='#'){//前序
*pused=1;
return NULL;
  }
  else{
TreeNode*root=(TreeNode*)malloc(sizeof(TreeNode));
root->val=preorder[0];
int leftused;//左边用了多少,当成一个装返回值的空间
root->left=creattree(preorder+1,size-1,&leftused);//preordre根左右,
//前a序ABDF####C#E#G,左子树开始为B所以为preorder+1-->preorder[1]
//size为个数&leftused为左边用的
int rightused;//用来保存右子树用掉的个数
root->right=creattree(preorder+1+leftused,size-1-leftused,&rightused);
*pused=1+leftused+rightused;//根用掉的+左子树+右子树
  return root;
}
}
