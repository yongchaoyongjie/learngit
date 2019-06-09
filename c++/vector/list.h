#pragma once 
template<class T>
struct Listnode{
Listnode <T>* _next;
Listnode <T>*_preve;
T _data;
Listnode(const T& x=T()):
  //x=T()-->匿名对象做缺省值
  _next(nullptr),_preve(nullptr),_data(x)
  {}
};
template<class T,class Ref,class Ptr>
struct _Listiterator{
  typedef Listnode<T> Node;
typedef  _Listiterator<T,Ref,Ptr>Self;
Node* _node;
_Listiterator(Node* node):_node(node)
  {}
//*it
Ref operator *(){
return _node->_data;
}
Ptr operator->(){
return &_node->_data;
}
Self& operator++(){
_node=_node->_next;
return *this;
}
Self operator++(int){
  Self tmp(*this);
_node=_node->_next;
return tmp;
}
Self& operator--(){
_node=_node->_preve;
return *this;
}
Self& operator--(int){
Self tmp(*this);
_node=_node->_preve;
return tmp;
}
bool operator!=(const Self& it){
return _node!=it.node;
}
};
template<class T>
class List{
typedef  Listnode<T>Node;
  public:
typedef _Listiterator<T,T&,T*> iterator;
typedef _Listiterator<T,const T&,const T*> const_iterator;
List():_head(new Node){
_head->_next=_head;
_head->_preve=_head;
}
iterator begin(){
return _head->next;
}
const_iterator begin()const
{
return const_iterator(_head->next);
}

const_iterator end()const
{
return const_iterator(_head);
//return (iterator)_head;
}
iterator end(){
return iterator(_head);
}

void PushBack(const T& x){
  Node* tail=_head->preve;
  Node* newnode=new Node(x);
//尾插
tail->next=newnode;
newnode->preve=tail;
newnode->next=_head;
_head->preve=newnode;
}
  private:
Node*_head;
};
struct AA{
  int _a1;
  int _a2;
};
void test(){
List<int> l;
l.PushBack(1);
l.PushBack(2);
l.PushBack(3);
l.PushBack(1);
List<int>::iterator it=l.begin();
while(it!=l.end()){
cout<<*it<<endl;
++it;
}
for(auto e:l){
  cout<<e<<endl;
}
List<AA> aa1;
AA aa={1,2};//匿名对象赋值
  aa1.PushBack(aa);
  aa1.PushBack({3,4});
List<int>::iterator itt=aa1.begin();
while(itt!=aa1.end()){
cout<<itt->_a1<<itt->_a2<<endl;
++itt;
}
}
