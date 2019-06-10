#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
void test1(){
  std::vector<int> first;//空的int 
  std::vector<int> second(4,100);//4个100
  std::vector<int> third(second.begin(),second.end());
  std::vector<int>fourth(third);//拷贝third
  int myints[]={16,2,77,29};
  //std::vector<int>fifth(myints,myints+sizeof(myints)/sizeof(int));
  std::vector<int>fifth(myints,myints+sizeof(myints)/sizeof(int));
  for(std::vector<int>::iterator it=fifth.begin();it!=fifth.end();it++){
    cout<<*it<<endl;//16 2 77 29
  }
    }
void printvector(const std::vector<int> &v){
  std::vector<int>::const_iterator it=v.begin();
  while(it!=v.end()){
cout<<*it<<" ";
  }
  cout<<endl;
}
void test3(){
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  std::vector<int>::iterator it=v.begin();
  while(it!=v.end()){
      cout<<*it<<" ";
      ++it;
      }
  cout<<endl;
  //使用迭代器进行修改
  it=v.begin();
  while(it!=v.end()){
//   ( *it )*=2;
    *it=*it*2;
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;
  std::vector<int>::reverse_iterator rit=v.rbegin();
  while(rit!=v.rend()){
    cout<<*rit<<" ";
++rit;
  }
  cout<<endl;
}
void test4(){
  //看容量如何增加
 size_t sz;
 std::vector<int> foo;
 sz=foo.capacity();
cout<<"making foo rongliang grow.\n";
for(int i=0;i<100;++i){
  foo.push_back(i);
  if(sz!=foo.capacity()){
    sz=foo.capacity();
    cout<<"capacity changed: "<<sz<<endl;
  }
}
}
void testreserve(){
  //改变放的capacity
  size_t sz;
  std::vector<int> foo;
  sz=foo.capacity();
  foo.reserve(100);
  cout<<"making rongliang grow\n";
  for(int i=0;i<100;++i){
    foo.push_back(i);
    if(foo.capacity()!=sz){
     sz=foo.capacity(); 
     cout<<"rongliang changed :"<<sz<<endl;
    }
  }
}
void testresize(){
  //resize 改变放的size
  std::vector<int> myvector;
  for(int i=1;i<10;++i){
    myvector.push_back(i);
  }
myvector.resize(5);
myvector.resize(8,100);
myvector.resize(12);
cout<<"myvector contain:";
for(int i=0;i<myvector.size();i++){
  cout<<myvector[i];
  cout<<endl;
}
}
void test5(){
  //迭代器删除
  int a[]={1,2,3,4,5};
  std::vector<int>v(a,a+sizeof(a)/sizeof(int));
  std::vector<int>::iterator it=v.begin();
  while(it!=v.end()){
    cout<<*it<<" ";
  ++it;
  }
  cout<<endl;
  v.pop_back();
  v.pop_back();
  it=v.begin();
  while(it!=v.end()){
    cout<<*it<<" ";
  ++it;
  }
  cout<<endl;
}
void test6(){
  //vector查找在迭代器下用find
  int a[]={1,2,3,4,5,6};
  std::vector<int>v(a,a+(sizeof(a)/sizeof(int)));
  std::vector<int>::iterator it=v.begin();
  std::vector<int>::iterator pos=find(v.begin(),v.end(),3);
  //find查找3所在位置的iterator-->
  v.insert(pos,30);//迭代器失效
  while(it!=v.end()){
    cout<<*it<" ";
    ++it;
  }
  cout<<endl;
}
void test7(){
  int a[]={1,2,3,4,5,6};
  std::vector<int>v(a,a+(sizeof(a)/sizeof(int)));
  std::vector<int>::iterator it=v.begin();
  while(it!=v.end()){
cout<<*it<<" ";
++it;
  }
  cout<<endl;
  it=v.begin();//没有这句话不行
  while(it!=v.end()){
    if(*it%2==0){
      it=v.erase(it);
      //迭代器删除会出错,返回erase删除位置的下一个就可以实现迭代器删除
      //不失效
    }
    else{
    ++it;
    cout<<*it<<" ";
}
}
cout<<endl;
}
int main(){
//test1();
//test3();
//test4();
//testreserve();
//testresize();
//test5();
test7();
  return 0;
}
