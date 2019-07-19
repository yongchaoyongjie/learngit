template<class T>
class bstree{
  public:
    typedefy bstnode<T>node;
    bstree(node*root==null):_root(root){}
  private:
    node* _root;
    //查找
    //node*find（const T&x）{
    ////空树
    //if(_root==null){
    //return null;
    //}
    //node *cur=_root;
    //while(cur){
    //if(cur->_data==x){
    //return cur;
    //}else if(x>cur->_data){
    ////当前值大于则走右边
    //cur=cur->_right;
    //}else{
    //小于左边
    //cur=cur->_left;
    //}
    //return null;没有找到
    //
    //
    //}
    //}
    //插入
    //bool insert(const T &x){
    ////当前结点和父亲结点，插入当前结点走到空上，插入是在父亲结点的下面进行插入
    //一开始当前结点是root
    //插入同理也是走查找
    //if(root==null)
    //root=new node(x);//根节点
    //刚开始从根节点开始走父亲结点为空
    //node* cur=_root;
    //node* parent=null;
    //while(cur){
    //if(cur->_data==x)
    //return false;
    //else if(x>cur->_data){
    //parent=cur;//更新
    //cur=cur->right;//比当前结点大走右边
    //}
    //else{
    //parent=cur;
    //cur=cur->left;//比当前结点小走左边
    //}
    //}
    //cur=new node(x);//新结点
    //if（parent->data>x）当前值比他小放在左边，当前值比他大放在叶子结点右边
    //parent->left=cur;
    //else
    //parent->right=cur;
    //return true;//插入成功，验证成功走中序遍历中序遍历有序则插入成功---左根右
    //}
    //void inorder(){
    //_inorder(_root);
    //}
    //void _inorder(node* root){
    ////中序遍历先左后中后右
    //if(root)不为空递归左边{
    //_inorder(root->left)；
    //cout<<root->_data;
    //_inorder(root->_right);
    //}
    //
    //}
    //pravite:
    //node* _root;
    // };
    //  int main(){
    //   
    //    bstree<int >bs;
    //     bs.insert(1);
    //      bs.insert(2);
    //       bs.insert(3);
    //        bs.insert(4);
    //
    //         }
    //          
    //           
    //            //删除
    //             bool  erase(const T& x){
    //              if(root==null)
    //               return false;
    //                node *cur =_root;
    //                 node *parent=null;
    //                  while(cur){
    //                   if(cur->_data==x){
    //                    break;//当前删除的数据刚好是找到了
    //                     }
    //                      else if(cur->data>x){
    //                       当前数据大于要找的数据,向左走
    //                        parent=cur;
    //                         cur=cur->_left;
    //                          }
    //                           else {
    //                            当前数据大于要找的数据,向右走
    //                             parent=cur;
    //                              cur=cur->_right;
    //                               }
    //                                }
    //                                 if(cur==null)//没有找到不用删除
    //                                  return false;
    //                                   1叶子节点
    //                                    if(cur->_left==null&&cur->right==null)
    //                                     {
    //                                      if(cur!=_root)
    //                                       {//判断不能是根
    //                                        //判断删除的结点是左边还是右边
    //                                         if(parent->_left==cur)
    //                                          parent->_left=null;//删除在左边
    //                                           else
    //                                            parent->right=null;
    //                                             }
    //                                              else
    //                                               _root=null;
    //                                                
    //                                                 delete cur;
    //                                                  cur=null;//删除cur让cur为空
    //                                                   }
    //                                                    //孩子结点不完整的
    //                                                     8右孩子不在，删除8，把7和9莲起来，没有
    //                                                      删除1 ，3的左等于1的右，删除8 7的右等于8的右判断删除的结点在它左边还是右边
    //                                                       
    //                                                        else if(cur->left==null){
    //                                                         //没有左孩子只有右孩子
    //                                                          if(cur!=root){
    //                                                           if(parent->left==cur)
    //                                                            parent->left=cur->right;???父亲的左等于我的右
    //                                                             else
    //                                                              parent->right=cur->right;父亲的右等于它的右
    //                                                               }
    //                                                                else{
    //                                                                 //是根，更新根只有右孩子
    //                                                                  root=cur->right;
    //                                                                   }
    //                                                                    //删除
    //                                                                     delete cur;
    //                                                                      cur=null;
    //                                                                       }
    //                                                                        else if(cur->right==null){
    //                                                                         有右孩子没有左孩子  删除1 3 的左连接到1的左 删除7 ， 5的右连接7的左
    //                                                                          if（cur！=root）{
    //                                                                           if(parent->right==cur){
    //                                                                            //父亲的右边等则连接都左边
    //                                                                             parent->right=cur->left;
    //                                                                              }else
    //                                                                               parent->left=cur->right;
    //                                                                                }else{
    //                                                                                 根
    //                                                                                 root=cur-》left;
    //                                                                                  }
    //                                                                                   delete cur;
    //                                                                                    cur=null;
    //                                                                                     }
    //                                                                                      else{
    //                                                                                       //左右都有
    //                                                                                        删除3
    //                                                                                         node *leftmost=cur->left;
    //                                                                                          parent=cur;//走到
    //                                                                                           找到左边最大
    //                                                                                            while(leftmost->right){
    //                                                                                             删除5左边找到最大的然后拿到左子树最大的结点，parent走到3 cur走到4   4为leftmost
    //                                                                                              不为空向右边走
    //                                                                                               parent=leftmost;
    //                                                                                                leftmost=leftmost->right;
    //                                                                                                 置换
    //                                                                                                  cur->data=leftmost->data;
    //                                                                                                   parent->right=null;
    //                                                                                                    删除结点
    //                                                                                                     delete leftmost;
    //                                                                                                      leftmost=null;
    //                                                                                                       }
    //                                                                                                        }
    //                                                                                                         return ture;
    //                                                                                                          
    //                                                                                                           }
    //                                                                                                            
    //                                                                                            }
    //                                                                                      }
    //                                                                                }
    //                                                                           }
    //                                                                          }
    //                                                                        }
    //                                                                }
    //                                                          }
    //                                                        }
    //                                     }
    //                           }
    //                      }
    //                   }
    //                  }
    //             }
    //  }
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    //}
    }
