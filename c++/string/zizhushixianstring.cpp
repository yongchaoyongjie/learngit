#include<iostream>
#include <string.h>
#include<assert.h>
using namespace std;
class String{
  public:
    //实现迭代器:string 
      typedef char* iterator;
typedef const char* const_iterator;
iterator begin(){
  return _str;
}
iterator end(){
  return _str+_size;
}
const_iterator begin() const {
  return _str;
}
const_iterator end()const {
  return _str+_size;
}
//传统写法的string类
//String(const char*str =""){
//  if(nullptr==str){
//assert(false);
//return;
//  }
//  _str=new char [strlen(_str)+1];//有\0
//  strcpy(_str,str);//str-->_str
//}
//String(const String&s):_str(new char[strlen(s._str)+1]){
//strcpy(_str,s._str);
//  }
//String& operator=(const String& s){
//  if(this!=&s){
// char* pstr=new char[strlen(s._str)+1] ;
// strcpy(_str,s._str);
// delete []_str;
// _str=pstr;
//  }
//  return *this;
//}
//~String(){
//  if(_str){
//    delete[] _str;
//    _str=nullptr;
//  }
//}
//现代写法
    String(const char* str=""):_str(nullptr),_capacity(0){
_size=strlen(str);
Reserve(_size);
strcpy(_str,str);
    }
//s2(s1)-->拷贝构造
String (const String& s):_str(nullptr),_capacity(0),_size(0){
String temp(s._str);
//s1.swap(s2);-->s2(*this)  --(s1(temp)
temp.Swap(*this);//成员变量之间的交换
}
//s1=s3 
String& operator=(String s){
 Swap(s);
 return *this;
}
void Swap(String& s){
  std::swap(_str,s._str);
  std::swap(_capacity,s._capacity);
  std::swap(_size,s._size);
}
~String(){
  if(_str){
    delete []_str;
    _str=nullptr;
    _size=_capacity=0;
  }
}
void Reserve(size_t n){
  if(n==0||n>_capacity){
size_t newsize=n;
if(n%8!=0){
  newsize=(n/8-1)*8;
}
else{
  newsize=n+8;
}
char*newstr=new char(newsize);

  }
}
private:
char* _str;
size_t _capacity;
size_t _size;
static size_t npos;
};
size_t String::npos=-1;
