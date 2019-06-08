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
  //开空间
  if(n>Capacity()){
size_t size=Size();
T*newarray=new T[n];
if(_start){
  //开新空间
  memcpy(newarray,_start,sizeof(T)*Size());
}
delete[]_start;
//赋值
_start=newarray;
_finish=newarray+size;
_end_of_storge=_start+n;
  }
}
void Resize(size_t n,const T& val=T()){
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
*_finish=x;
++*_finish;//后面添加成x
 }
  }
}
//中间插入
void Insert(iterator pos,const T&x){
assert(pos<_finish);
if(_finish==_end_of_storge){
  size_t n=pos-_start;
  size_t newcapacity;
 if((newcapacity=Capacity()==0)||(newcapacity=Capacity()==4)){
newcapacity=Capacity()*2;
  Reserve(newcapacity);
  pos=_start+n;
}
}
iterator end=_finish-1;
while(end>=pos){
  *(end+1)=*end;
  --end;
}
*pos=x;
++_finish;
}
iterator Erase  (iterator pos){
assert(pos<_finish);
iterator it=pos;
while(pos<_finish-1){
*it=*(it+1);
++it;
}
--_finish;
return pos;
}
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
iterator _start;
iterator _finish;
iterator _end_of_storge;
};
