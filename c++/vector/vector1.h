#include<iostream>
#include<assert.h>
template<class T>
class vector1{
  public:
    typedef T* iterator;
typedef const T* const_iterator;
vector1():_start(nullptr),_finish(nullptr),_end_of_storge(nullptr)
  {}
vector1(const vector1<T>&v):_start(nullptr),_finish(nullptr),
  _end_of_storge(nullptr){
  Reserve(v.Size());
  for(size_t i=0;i<v.Size();++i){
   this->Pushback(v[i]);
  }
}
//v1=v2
vector1<T> &operator=(vector1<T>&v){
Swap(v);
return *this;
}
void Swap(vector1<T> &v){
std::swap(_start,v._start);
std::swap(_finish,v._finish);
std::swap(_end_of_storge,v._end_of_storge);
}
~vector1(){
  if(_start) {
    delete []_start;
    _start=nullptr;
   _finish=nullptr;
   _end_of_storge=nullptr;
  }
}
const_iterator begin()const{
  return _start;
}
const_iterator end()const{
  return _finish;
}
iterator begin(){
  return _start;
}
iterator end(){
  return _finish;
}
T& operator[](size_t pos){
  assert(pos<Size());
return _start[pos];
}
const T& operator[](size_t pos)const
{
  assert(pos<Size());
return _start[pos];
}
void Reserve(size_t n){
  //开空间-->提前开好空间
  if(n>Capacity()){
size_t size=Size();
T*newarray=new T[n];
if(_start){
  //开新空间
  memcpy(newarray,_start,sizeof(T)*Size());
}
delete[]_start;
//释放旧空间
//将指向旧空间的位置指向新空间
_start=newarray;
_finish=newarray+size;
_end_of_storge=_start+n;
  }
}
void Resize(size_t n,const T& val=T()){
  //开空间的同时初始化(给缺省值)
  if(n<=Size()){
    _finish=_start+n;
  }
  Reserve(n);
  while(_finish!=_start+n){
    *_finish=val;
    ++_finish;
  }
}
void Pushback(const T x){
  if(_finish==_end_of_storge){
 size_t newcapacity; 
 if((newcapacity=Capacity()==0)||(newcapacity=Capacity()==4)){
newcapacity=Capacity()*2;
Reserve(newcapacity);
*_finish=x;//最后一个插入的是x
++*_finish;//finish变成finish+1的位置
 }
  }
}
//中间插入
void Insert(iterator pos,const T&x){
assert(pos<_finish);
if(_finish==_end_of_storge){
  //插入的数据刚到等于容量大小时候-->需要扩容
  size_t n=pos-_start;//记录插入的位置--->从第几个位置插入的数据
  size_t newcapacity;
 if((newcapacity=Capacity()==0)||(newcapacity=Capacity()==4)){
newcapacity=Capacity()*2;
  Reserve(newcapacity);
  pos=_start+n;
  //在扩容以后pos位置指向的是原来旧的位置然后找到扩容后pos要变成新位置的第几个
  //位置插入数据的位置
}
}
//在扩容后找到之前end的位置把end位置上的元素移动到end+1上
iterator end=_finish-1;
while(end>=pos){
  *(end+1)=*end;//扩容后end位置元素变成end+1了
  --end;
}
*pos=x;
++_finish;
//在将数据移动完后将将迭代器end(finish+1)
}
//迭代器删除会失效解决迭代器的失效问题,返回的是删除pos点的位置
iterator Erase (iterator pos){
assert(pos<_finish);
iterator it=pos;
while(pos<_finish-1){
*it=*(it+1);
++it;
}
--_finish;
return pos;
}
//最后删除一个元素
void Popback(){
  assert(_finish>_start );
    --_finish;
}
size_t Capacity()const
{
  return _end_of_storge-_start;
}
size_t Size()const
{
return _finish-_start;
}
  private:
iterator _start;//指向数据开始位置
iterator _finish;//指向数据结束的位置
iterator _end_of_storge;//指向存储容量的尾部
};
