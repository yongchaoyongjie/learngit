#include<iostream>
#include <string.h>
#include<string.h>
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
    const_iterator begin() const
    {
      return _str;
    }
    const_iterator end()const 
    {
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
    String(const char* str=""):_str(NULL),_capacity(0){
      _size=strlen(str);
      Reserve(_size);
      strcpy(_str,str);
    }
    //s2(s1)-->拷贝构造
    String (const String& s):_str(NULL),_capacity(0),_size(0){
      String temp(s._str);
      //s1.swap(s2);-->s2(*this)  --(s1(temp)
      //temp.Swap(*this);//成员变量之间的交换
      Swap(temp);
    }
    void Swap(String& s){
      std::swap(_str,s._str);
      std::swap(_capacity,s._capacity);
      std::swap(_size,s._size);
    }

    //s1=s3 
    String& operator=(String s){
      Swap(s);
      return *this;
    }
    ~String(){
      if(_str){
        delete []_str;
        _str=NULL;
        _size=_capacity=0;
      }
    }
    char& operator[](size_t pos){
      assert(pos<_size);
      return _str[pos];
    }
    char& operator[](size_t pos)const
    {
      assert(pos<_size);
      return _str[pos];
    }

    //c1+ch
    String operator+(char ch) const
    {
      String tmp(*this);
      tmp.Pushback(ch);
      return tmp;
    }
    String& operator+(char* s)
    {
      String tmp(*this);
      tmp.Append(s);
      return tmp;
    }
    char* c_str()const
    {
      return _str;
    }

    //c1+=ch
    String& operator+=(char ch){
      Pushback(ch);
      return *this;
    }
    //c1+=zifuchuan 
    String& operator+=(char *s){
      Append(s);
      return *this;
    }
    //strlen( const char *__s  ) 
    void Insert(size_t pos,char ch){
      assert(pos<=_size);
      if(_size==_capacity){
        Reserve(2*_capacity);
      }
      //怎么插?-->找到要插入的位置-->从插入的位置后后面的数全部向后移动1个位置
      //前面的保持不变
      for(int i=_size;i>=(int)pos;--i){
        _str[i+1]=_str[i];
      }
      _str[pos]=ch;
      _size++;
    }
    void Insert(size_t pos,const char  *str){
      size_t len=strlen(str);
      if(len+_size>_capacity){
        Reserve(len+_size);
      }
      for(int i=_size;i>=(int)pos;--i) {
        _str[i+len]=str[i];
      }
      strncpy(_str+pos,str,len);
      _size=_size+len;
    }
    void Erase(size_t pos=0,size_t len=npos){
      //删除一个字符串从pos开始
      if(pos+len>=_size){
        //删除长度大于字符串的总长度-->把\0也删除了
        _size=pos;
        _str[_size]='\0';//所以要添加\0
      }
      else{
        //没有删除完只删除了中间一部分-->找一个新的地方将字符串拷贝过去 
        size_t start=pos+npos;//找到删除后的后面那个字符串的第一个位置
        strcpy(_str+pos,_str+start);//从_str+start位置开始拷直到到\0
        _size=_size-len;

      }
    }
    size_t Find(char ch,size_t pos=0){
      size_t i=0;
      for(;i<_size;i++){
        if(_str[i]==ch){
          return i;
        }
      }
    }
    size_t Find(const char*str,size_t pos=0){
      //找到pos位置开始的字串
      const char* ret=strstr(_str+pos,str);
      if(ret==NULL){
        return npos;
      }
      else {
        return ret-_str;
      }
    }
    bool operator>(const String& s)const 
    {
      size_t i=0;
      size_t j=0;
      while(i<_size&&i<s._size){
        if(_str[i]>s[j]){
          return true;
        }
        if(_str[i]<s[j]){
          return false;
        }
        ++i;
        ++j;
      }
    } 
    bool operator==(const String& s)const{
      if(this->_size==s._size){
        int i=0;
        for(i=0;i<(this->_size);i++){
          if(_str[i]==s._str[i]){
            return true;
          }
        }
      }
      return false;
    }
    bool operator<(const String& s)const{
      return !(*this>=s);

    }
    bool operator!=(const String& s)const
    {
      return !(*this==s);
    }
    bool operator<=(const String& s)const{
      return *this<s||*this==s;
    }
    bool operator>=(const String& s)const{
      return !(*this<s);
    }
    void Pushback(char ch){
      //插入单个字符
      if(_size==_capacity){
        Reserve(_capacity*2);
      }
      Insert(_size,ch);
    }
    void Append(const char*s){
      Insert(_size,s);
    }
    void Reserve(size_t n){
      if(n==0||n>_capacity){
        size_t newsize=n;
        if(n%8!=0){
          newsize=(n/8+1)*8;
        }
        else{
          newsize=n+8;
        }
        char* newstr=new char(newsize);
        if(_str){
          strcpy(newstr,_str);
        }
        _str=newstr;
        _capacity=newsize-1;
      }
    }
    void Resize(size_t n,char ch='\0'){
      if(n<=_size){
        _size=n;
        _str[_size]='\0';
      }
      else{
        Reserve(n);
        size_t i;
        for(i=_size;i<n;i++){
          _str[i]=ch;
          ++_size;
        }
        _str[_size]='\0';
      }
    }
    size_t Capacity()const
    {
      return _capacity;
    }
    size_t Size()const
    {
      return _size;
    }
  private:
    char* _str;
    size_t _capacity;
    size_t _size;
    static size_t npos;
};
size_t String::npos=-1;
void test(){
  cout<<"验证构造函数赋值和拷贝构造"<<endl;
  String s1("nihao");
  String s2(s1);
  cout<<s1.c_str()<<endl;
  cout<<s2.c_str()<<endl;
  String s3("world");
  s1=s3;
  cout<<s3.c_str()<<endl;
}
void test1(){
  cout<<"验证[],const迭代器和普通迭代器"<<endl;
  String s1("nihaoh");
  for(size_t i=0;i<s1.Size();++i){
    cout<<s1[i]<<" ";//验证[]
  }
  cout<<endl;
  String::iterator it=s1.begin();
  while(it!=s1.end()){
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;
  const String s2("chenyongjie");
  String::const_iterator it1=s2.begin();
  while(it1!=s2.end()){
    cout<<*it1;
    it1++;
  }
  cout<<endl;
  cout<<s2.c_str()<<endl;
  //for(atuo&e:s1){
  //e='y';
  //cout<<e<<" ";
  //}
  cout<<endl;
  cout<<s1.c_str()<<endl;
}
void test3(){
  String s1("nihao");
  s1+=' ';
  s1+="shijie";
  cout<<s1.c_str()<<endl;
  cout<<s1.Size()<<endl;
  cout<<s1.Capacity()<<endl;
  s1.Reserve(5);
  cout<<s1.c_str()<<endl;
  cout<<s1.Size()<<endl;
  cout<<s1.Capacity()<<endl;
  //s1.Reserve(20,'x');
}
void test4(){
  String s1("nihao");
  s1.Insert(5,"world world world");
  cout<<s1.c_str()<<endl;
  cout<<s1.Size()<<endl;
  cout<<s1.Capacity()<<endl;
  s1.Insert(0,"nihaok");
  cout<<s1.c_str()<<endl;
}
int main(){
  //  test();
  //test1();
  //test3();
  test4();
  return 0;
}
