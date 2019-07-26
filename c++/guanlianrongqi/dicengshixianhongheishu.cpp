#include<iostream>
using namespace std;
enum Color{
  BLACK,
  RED
};
template<class K,class V>
struct RBtreenode{
  typedef  RBtreenode<K,V>Node;
  Node* _pleft=nullptr;
  Node*_pright=nullptr;
  Node* _pparent=nullptr;
  pair<K,V>_kv;//pair是自定义类型编译器会调用默认构造函数调用自定义构造函数进行初始化
  Color _color=RED;//默认刚开始插入红色
};
template<class K,class V>
class RBTree{
  public:
    typedef RBtreenode<K,V> node;
    typedef node* pnode;
    RBTree(){
      _header=new node;
      _header->parent=nullptr;
      _header->_pleft=_header;//只向它自己
      _header->_pright=_header;
    }
    bool Insert(const pair<K,V>&kv){
      if(_header->_pparent==nullptr){
        //是空树插入根
        pnode root=new node;
        root->_kv=kv;
        //根是黑色所以改色
        root->_color=BLACK;
        //连接关系
        root->_pparent=_header;
        _header->_pparent=root;
        _header->_pleft=root;
        _header->_pright=root;
        return true;
      }
      else{
        //不是空树从根开始找
        pnode cur=_header->_pparent;
        pnode parent=nullptr;
        while(cur){
          if(kv.first>cur->_kv.first){
            //比它大向右边走
            parent=cur;
            cur=cur->_pright;
          }
          else if(kv.first<cur->_kv.first){
            //比它大向左边走
            parent=cur;
            cur=cur->_pleft;
          }
          else{
            return false;
          }
          //创建新结点
          pnode newnode=new node;
          newnode->_kv=kv;
          if(kv.first>parent->_kv.first){
            parent->_pright=newnode;
          }
          else{
            parent->_pleft=newnode;
          }
          newnode->_pparent=parent;
          //插入完毕进行调整
          cur=newnode;
          //调整从叶子开始调整
          while(cur!=_header->_pparent&&cur->_pparent->_color==RED){
            //当前不为根父亲颜色是红色,两个红色连在一起--向上调整
            //父亲颜色是红色开始调整如果走到根停止,cur!=_header->parent,不能直接写成根,因为会
            //旋转,旋转后原来的根就不是现在的根了
            //cur.parent,gparent,uncle//cur存在,父亲存在,祖父存在
            pnode parent=cur->_pparent;
            pnode gparent=parent->_pparent;
            //叔叔存在不存在不一定要判断
            if(gparent->_pleft==parent){//父亲在左边则叔叔在右边
              pnode uncle=gparent->_pright;
              if(uncle&&uncle==RED){
                //叔叔存在而且为红色,修改颜色向上调整
                parent->_color=uncle->_color=BLACK;
                gparent->_color=RED;
                cur=gparent;//继续向上调整
              }
              else{
                //叔叔不存在/叔叔存在而且为黑
                //叔叔不存在以g为轴进行右旋
                //旋转,调色
                //判断是否需要双旋
                if(cur==parent->_pright){
                  Rotatel(parent);
                  swap(parent,cur);
                }
                //右单旋
                RotateR(gparent);
                parent->_color=BLACK;
                gparent->_color=RED;
                break;
              }
            }
            else{
              pnode uncle=gparent->_pleft;
              //对应
              if(uncle&&uncle->_color==RED){
                uncle->_color=parent->_color=BLACK;
                gparent->_color=RED;
                cur=gparent;
              }
              else{
                //1判断是否双旋
                if(cur==parent->_pleft){
                  RotateR(parent);
                  swap(cur,parent);
                }
                Rotatel(gparent);
                parent->_color=BLACK;
                gparent->_color=RED;
                break;
              }
            }
          }
          _header->_pparent->_color=BLACK;
          //如果是根,走到最后把根的颜色改为黑色就可以了
          //插入结点完要更新left和right
          _header->_pleft=leftmost();
          _header->_pright=rightmost();
        }
      }
    }
    pnode leftmost(){
      pnode cur=_header->_pparent;
      while(cur&&cur->_pleft){
        cur=cur->_pleft;
      }
      return cur;
    }
    pnode rightmost(){
      pnode cur=_header->_pparent;
      while(cur&&cur->_pright){
        cur=cur->_pright;
      }

      return cur;
    }
    void Rotatel(node*parent){
      node*subr=parent->_pright;
      node*subrl=subr->_pleft;
      subr->_pleft=parent;
      parent->_pright=subrl;
      if(subrl){
        subrl->_pparent=parent;
      }
      if(parent!=_header->_pparent){
        node* gparent=parent->_pparent;
        if(gparent->_pleft==nullptr){
          gparent->_pright=subr;
        }
        else{
          gparent->_pleft=subr;
        }
        subr->_pparent=gparent;
      }
      else{
        subr->_pparent=nullptr;
        _header->_pparent=subr;
      }
      parent->_pparent=subr;
    }
    void RotateR(node*parent){
      node* subl=parent->_pleft;
      node* sublr=subl->_pright;
      subl->_pright=parent;
      parent->_pleft=sublr;
      if(sublr){
        sublr->_pparent=parent;
      }
        if(parent!=_header->_pparent){
          node*gparent=parent->_pparent;
          if(gparent->_pleft==nullptr){
            gparent->_pright=subl;
          }
          else{
            gparent->_pleft=subl;
          }
          subl->_pparent=gparent;
        }
        else{
          subl->_pparent=nullptr;
          _header->_pparent=subl;
        }
        parent->_pparent=subl;
    }
    void inorder(pnode root){
      if(root){
        _inorder(root->_pleft);
        cout<<root->_kv.first<<" "<<root->_kv.second<<endl;
        _inorder(root->_pright);

      }
    }
    void _inorder(){
      inorder(_header->_pparent);
    }

  private:
    pnode* _header;
};
void testrbtree(){
  RBTree<int,int>rbtre;
  rbtre.Insert(1);
  rbtre.Insert(10);
  rbtre.Insert(2);
  rbtre.Insert(8);
  rbtre.Insert(9);
  rbtre.Insert(4);
}
