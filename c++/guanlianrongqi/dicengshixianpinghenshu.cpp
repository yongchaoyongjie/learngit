#include<iostream>
using namespace std;
template<class K,class V>
struct AVLTreeNode{
  pair<K,V>_kv;
  AVLTreeNode *_right;
  AVLTreeNode *_left;
  AVLTreeNode *_pparent;
  int _bf;//平衡因子
  AVLTreeNode(const pair<K,V>&kv)
    :_kv(kv),
    _right(nullptr),
    _left(nullptr),
    _pparent(nullptr),
    _bf(0)
  {}
};
template<class K,class V>
class AVLtree{
  public:
    typedef AVLTreeNode<K, V>Node;
    bool Insert(const pair<K,V>&kv){
      //建立遍历方式
      if(_root==nullptr){
        _root=new Node(kv);
        _root->_bf=0;
        return true;
      }
        Node*parent=nullptr;
        Node*cur=_root;
        while(cur){
          if(cur->_kv.first<kv.first){
            //左边如何实现遍历,值小于放在左边
            parent=cur; 
            cur=cur->_left;//cur=parent->_left??可以吗
          }
          else if(cur->_kv.first>kv.first){
            parent=cur;
            cur=cur->_right;
          }
          else {
            return false;
          }
        }
        cur=new Node(kv);
        if(parent->_kv.first<kv.first){
          //三项链
          parent->_right=cur;//如果此时插的数比parent的大则数插在右边的树
          cur->_parent=parent;
        }
        else {
          parent->_left=cur;//此时插入的数比parent的小,则插在左孩子
          cur->_pparent=parent;
        }
        //调平衡
        //调节平衡因子
        while(cur){
          if(cur==parent->_right){
//如果cur在右边插入
parent->_bf++;//parent为node*所以用->
          }
          else{
parent->_bf--;
          }
          if(parent->_bf==0){
break;
          }
          else if(parent->bf==-1){
//高度变了继续调整
//如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被
//更新成正负1此时以pParent为根的树的高度增加，需要继续向上更新
cur=parent;
parent=parent->_pparent;
          }
          else if(parent->bf==1){
cur=parent;
parent=parent->_pparent;
          }
          else if(parent->bf==2){

          }
          else if(parent->bf==-2){

          }

        }
}
void youxuan(Node*parent){
Node*subl=parent->_left;
Node*sublr=subl->_right;
parent->_left=subl;//三项链
if(sublr){
  subl->_right=parent;
  parent->_pparent=subl;
  parent->_left=sublr;
  sublr->_parent=parent;
  Node*pparent=parent->_pparent;
  if(parent==_root){//parent为根
    subl=_root;
_root->_pparent=nullptr;
  }
  else{
    if(pparent->_right==nullptr){
      pparent->_left=subl;
    }
    else{
      pparent->_right=subl;
    }
    subl->_pparent=pparent;
  }
//保证平衡因子等于0
subl->_bf=sublr->_bf=0;
}
}
void zuoxuan(Node*parent){
  Node*subr=parent->_right;
  Node*subrl=subr->_right;
  parent->_right=subr;//向上连接
  if(subrl){//subrl不为空
    subrl->_pparent=parent;
//subr-_left=parent;
parent->_pparent=subr;
subr->_left=parent;
Node*pparent=subr->_pparent;
if(parent==_root){//特殊情况parent为根
  _root=subr;
  _root->_pparent=nullptr;
}
else {
  if(pparent->_left==nullptr){//旋转后的顶的母亲,subr在母亲的右边
pparent->_right=subr;
  }
 else {
pparent->_left=subr;
  }
subr->_pparent=pparent;
}
parent->_bf=subr->_bf=0;//最后保证parent的平衡因子和subr的平衡因子为0才算调整完毕
  }
}
void zuoxuanyyouxuan(Node*parent){
Node*subr=parent->_right;
Node*subrl=subr->_right;
int bf=subrl->_bf;
zuoxuan(parent->_left);
youxuan(parent);
if(bf==0){
  parent->_bf=subr->_bf=subrl->bf=0;
}
else if(bf==1){
 subr->_bf=-1; 
}
else if(bf==-1){
 parent->bf=1; 
}

}
void youxuanzuoxuan(Node*parent){
  //旋转前保存平衡因子旋转完成后对相应的平衡因子进行调整
Node*subr=parent->_right;
Node*subrl=subr->_left;
int bf=subrl->_bf;
youxuan(parent->_right);
zuoxuan(parent);
//旋转前sublr的平衡因子可能是0,-1,1
//调整后parent右树,subl左树
if(bf==0){
  parent->_bf=subr->_bf=subrl->bf=0;
}
else if (bf==1){
 parent->_bf=-1;
 subrl->_bf=0;
 subr->bf=0;
}
else if(bf==-1){
  parent->_bf=0;
  subr->_bf=1;
  subrl->_bf=0;
}
}
void InOrder(){
  _InOrder(_root);
  cout<<endl;
}
void _Inorder(Node*root){
  if(root==nullptr){
    return ;
  }
  else{
    InOrder(root->_left);
    cout<<root->_kv.first<<" ";
    InOrder(root->_right);
  }
}
int height(Node*root){
  if(root==nullptr){
    return 0;
  }
  int leftheight=height(root->_left);
  int rightheight=height(root->_right);
  if(leftheight>rightheight){
  return leftheight+1;
  }
  return rightheight+1;
}
bool isbalancetree(){
  return _isbalancetree(_root);
}
bool _isbalancetree(Node*root){
  if(root==nullptr){
    return true;
  }
  int leftheight=height(root->_left);
  int rightheight=height(root->_right);
  if(rightheight->leftheight!=root->_bf){
cout<<root->_kv.first<<"平衡因子异常"<<endl;
return false;
  }
  
    if((leftheight-rightheight<2)&&(leftheight-rightheight>-2)&&
        isbalancetree(root->_left)&&isbalancetree(root->_right)){
 return true;     
    }
}
  private:
    Node* _root;
};
