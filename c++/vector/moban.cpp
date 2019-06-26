#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std;
//模板函数
template<class T>
T add1(const T&left,const T&right){
  return left+right;
}
void test(){
  int a1=10,a2=20;
  double d1=1.1,d2=2.2;
  cout<<add1(a1,a2)<<endl;
  cout<<add1(d1,d2)<<endl;
  int a=10;
  double b=2.1;
 cout<< add1<int>(a,b)<<endl;//显示实例化
}
//类模板
template<class T>
//动态顺序表
class Vector{
  public:
    Vector(size_t capacity=10):_pdata(new T(capacity)),_size(0),
    _capacity(capacity){}
    //用析构函数在类中声明在类外定义
    ~Vector();
    size_t Size(){
      return _size;
    }
    size_t Capacity(){
      return _capacity;
    }

    //插入数据
    size_t PushBack(const T&pdata ){
_pdata[++_size]=pdata;
    }
    size_t Popback(){
      _size--;
    }
    T& operator[](size_t pos){
assert(pos<_size);
return _pdata[pos];
    }
    
private:
    T* _pdata;
    size_t _size;
    size_t _capacity;
};
template < class T>
Vector< T>::~Vector(){
  if(_pdata){
delete[]_pdata;
}
}
void test1(){
  Vector<int>s1;
  //s1.PushBack(1);
  //s1.PushBack(2);
  //s1.PushBack(3);
  Vector<double>s2;
  s2.PushBack(1.1);
  s2.PushBack(2.1);
  s2.PushBack(3.1);
  //for(size_t i=0;i<s1.Size();++i){
  //  cout<<s1[i]<<" ";
  //}
  //cout<<endl;
  for(size_t i=0;i<s2.Size();++i){
    cout<<s2[i]<<" ";
  }
  //cout<<endl;
}
//只出现一次的数字
int singnalnumber(vector<int>& nums){
  int value=0;
  for(size_t i=0;i<nums.size();++i){
value^=nums[i];
  }
  return value;
}
void test2(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
cout<<singnalnumber(v)<<endl;
}
//杨辉三角用vector实现
class solution{
vector<vector<int>> generation(int numrows){
vector<vector<int>> vv;
vv.resize(numrows);
for(size_t i=1;i<=numrows;++i){
  vv[i-1].resize(i,0);
  vv[i-1][0]=1;
  vv[i-1][i-1]=1;
}
for(size_t i=1;i<vv.size();++i){
  for(size_t j=0;j<vv[i].size();++j){
    if(vv[i][j]==0){
      vv[i][j]=vv[i-1][j-1]+vv[i-1][j];
    }
  }
}
return vv;
}
};

int main(){
  //test();
  //test1();
  test2();
  return 0;
}
