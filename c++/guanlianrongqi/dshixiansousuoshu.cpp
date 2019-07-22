#include<iostream>
//二叉搜索树实现
//二叉搜索树,左边的一定比根小右边的一定比根大
using namespace std;
template<class K,class V>
struct BStreeNode{//定义搜索树的结点
pair<K,V>_kv;//由键值对组成
BStreeNode *_left;
BStreeNode *_right;
BStreeNode(const pair<K,V>&kv):_left(nullptr),_right(nullptr),_kv(kv){}
};
template<class K,class V>
struct BSTree{
typedef  BStreeNode<K,V> Node;
  public:
BSTree():_root(nullptr){}
bool Insert(const pair<K,V>&kv){
  //插入时候先查找
  if(_root==nullptr){
    _root=new Node(kv);
  }
Node*cur=_root;
Node* parent=nullptr;
while(cur){
//两种情况,一种在左边小于根一种在右边大于根
  if(cur->_kv.first>kv.first){//kv>cur->first右边走kv.first>cur->_kv.first
    //新结点小于旧结点
    parent=cur;//更新
    cur=cur->_left;//比当前结点小走左边
  }
  else if(cur->_kv.first<kv.first){//向右边走
    parent=cur;
    cur=cur->_right;
  }
  else{
    return false;
  }
}
//查找遍历完插入新数据
cur=new Node(kv);
if(parent->_kv.first>kv.first){
  //父母的新结点比它大则朝左边走,左边的都小于父母
    parent->_left=cur;
}
else{
  parent->_right=cur;//右边的数字大于父母的
}
return true;
}
//Node* Find(const K&key){
Node* Find(const pair<K,V>&kv){
  if(_root==nullptr){
    return nullptr;
  }
  Node*cur=_root;
  while(cur){
    if(cur->_kv.first>kv.first){
//插入的数据小于parent向左边走
cur=cur->_left;
    }
   else  if(cur->_kv.first<kv.first){
//插入的数据小于parent向右边走
cur=cur->_right;
    }
    else{
      return cur;
    }
  }
  //都找完了没有找到则返回空
  return nullptr;
}
bool Remove(const K &key){
//移除只需要移除值就可以了
//移除的过程第一步还是查找
Node*parent=nullptr;
Node*cur=_root;
while(cur){
  //首先让其能够遍历走起来
  if(cur->_kv.first>key){
   //插入的值小于父母
   parent->_left=key;
  }
  else if(cur->_kv.first<key){
   //插入的值大于父母
   parent->_right=key;
  }
  else{
    //删除
    //1只有0-1个孩子
    //2有两个孩子
    //删除0-1个孩子
  Node*del=cur;
    if(cur->_left==nullptr){
      //左边为空,分两种,1树的左边parent左边cur的右边2树的右边parent右边cur右边
      //删除cur
      if(parent==nullptr){
        //特殊情况,cur为根没有parent
       _root=cur->_right; 
      }
      else {//非特殊情况有parent,而且cur->_left为空
        if(cur==parent->_left){
       parent->_left=cur->_right ;
        }
        else{
parent->_right=cur->_right;
        }
      }
    }
    else if(cur->_right==nullptr){
//右边为空,c(1)在左树,cur右边为空,parent的左边和cur的左边相连,(2)在右树,parent的
//右边和cur的左边相连接
      if(parent==nullptr){
_root=cur->_left;//特殊情况
      }
      //parent不为空
      else{
        if(cur==parent->_left){
          parent->_left=cur->_left;
        }
        else{
          parent->_left=cur->_left;
        }
      }
    }
    else{
//删除两个孩子
Node*rpParent=cur;
Node*replace1=cur->_right;
while(replace1->_left){//当replace1->left不为空时候
  rpParent=replace1;
  replace1=replace1->_left;
}
cur->_kv=replace1->_kv;
del=replace1;
if(rpParent->_left==replace1){
  rpParent->_left=replace1->_right;
}
else{
  rpParent->_right=replace1->_right;
}
    }
delete  del;
return true;
  }
}
return false;
}
void InOrder(){
  _InOrder(_root);
  cout<<endl;
}
void _InOrder(Node*root){
  if(root==nullptr){
    return ;
  }
  _InOrder(root->_left);
  cout<<root->_kv.first<<" ";
  _InOrder(root->_right);
}
  private:
Node* _root;
};
void testBtree1(){
  BSTree<int ,int>tree;
  tree.Insert(make_pair(1,1));
  tree.Insert(make_pair(3,1));
  tree.Insert(make_pair(4,1));
  tree.Insert(make_pair(6,1));
  tree.Insert(make_pair(1,1));
  tree.Insert(make_pair(2,1));
  tree.InOrder();
  tree.Remove(1);
  tree.Remove(3);
  tree.Remove(2);
  tree.Remove(6);
  tree.Remove(4);
  tree.Remove(1);
  tree.Remove(10);
  tree.InOrder();
}
int main(){
testBtree1();
 return 0; 
}
