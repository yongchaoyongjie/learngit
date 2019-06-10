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
//拷贝构造赋值析构都可以不写默认生成都可以搞定都是浅拷贝
};
template<class T>
struct _Listiterator{
  typedef Listnode<T> Node;
Node* _node;
_Listiterator(Node* node):_node(node)
  {}
//*it
T& operator *(){//出了作用域对象还在,T是结点里面的数据
return _node->_data;
}
T* operator->(){
return &_node->_data;//*it是解引用取了里面的数据,->不是取data是取data里面的数据,T自定义类型才要箭头,迭代器取的是数据(解引用),相当于数据的指针
//->取data里面数据,data是自定义类型所以要用箭头,迭代器代表指向数据的指针,但是在
//链表中指向的是结点通过自定义类型云算符重载改变其行为,在链表opertator*是
//结点里面的data,*it取结点里面的数 it->取结点里面数据(AA)的再数据,如果数据不是
//自定义类型是基本类型就不需要了AA* pa=new AA; pa->_a1=10;cout<<(*pa).a1<<endl
//pa->a1也可以
//
}
_Listiterator<T>& operator++(){//迭代器++还是迭代器,返回++以后的值
_node=_node->_next;//迭代器的结点指针指向1,加加it  -->it.operator++(&it),
///this->_node    --->this->_node=this->_node->next
//加引用的作用一个迭代器4个字节存的指针不加引用拷贝构造一下一次空间比较小也没事,迭代器的拷贝是浅拷贝,两个迭代器对象指向同一个结点不会释放两次不管结点的释放
//结点迭代器通过重载实现变量结点释放申请是列表管 的和自己没有关系,所以是浅拷贝
//结点指针不归迭代器管规链表管所以迭代器是浅拷贝
return *this;
}
//it1!=it2
bool operator !=(const _Listiterator<T>& it){//!=可以让迭代器跑起来,迭代器是否相等是迭代器对象比较
return _node!=it.node;
}

_Listiterator<T> &operator++(int){//必须传值返回
  _Listiterator<T> tmp(*this);
_node=_node->_next;
return tmp;
}
_Listiterator<T>& operator--(){
_node=_node->_preve;
return *this;
}
_Listiterator<T>& operator--(int){
_Listiterator<T> tmp(*this);
_node=_node->_preve;
return tmp;
}
};
template<class T>
class List{
typedef  Listnode<T>Node;
  public:
typedef _Listiterator<T> iterator;
List():_head(new Node){
_head->_next=_head;
_head->_preve=_head;
}
iterator begin(){
return _head->next;
}
iterator end(){
return iterator(_head);
}
void PopBack(){
Erase(--end());//临时对象返回值的临时对象的迭代器,对迭代器里面值--然后还给erase
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
typedef _Listiterator<const T> constiterator;
constiterator begin() const {
return _head->next;
}
constiterator end()const
{
return iterator(_head);
}
  private:
Node*_head;
};
struct AA{
  int _a1;
  int _a2;
};
//在用const的时候本来需要将const拷一份但是通过泛型进行复用
//template<class T,class Ref,class Ptr>
//ref,ptr是魔板形参的名称,不知道什么类型传什么类型变成什么类型,和函数参数类似
// 返回指针  ptr   返回引用ref
// 然后普通迭代器 typedef _Listiterator<T,T&,T*> iterator 
// typedef_Lis...<T,constT&,constT*>const_iterator
// 通过控制模板参数普通迭代器可读可写,const只读
// 代码第二层
// _Listiterator<T,T&,T*>-->所有的都得变成这样
// 所以为了增强程序可维护性   typedef _Listiterator<T,ref,ptr> self;
// 后面如果再增加模板参数只需要改这里就好
