#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
void test_set(){
  set<int> s;
  s.insert(4);
  s.insert(2);
  s.insert(5);
  s.insert(8);
  s.insert(4);
  s.insert(8);
  set<int>::iterator it=s.begin();
  while(it!=s.end()){
    cout<<*it<<" ";//打印结果为2 4 5 8-->set功能查找再不在以及排序+去重
    ++it;
  }
  cout<<endl;
}
void test1(){
  set<int> s;
  s.insert(4);
  s.insert(2);
  s.insert(5);
  s.insert(8);
  s.insert(4);
  s.insert(8);
auto it =s.begin();
while(it!=s.end()){
  cout<<*it<<" ";
  ++it;
}
cout<<endl;
auto pos=s.find(4);//ONlogn
//auto pos=std::find(s.begin(),s.end(),4);ON(n)
if(pos!=s.end()){
  s.erase(40);//有要删除的数则删除没有则保持不变
  s.erase(4);
  for(auto &e:s){
    cout<<e<<" ";
  }
  cout<<endl;
}
}
//键值对的定义
//template<class K,class V>
//struct pair{
//K first;
//V second;
//};
//make_pair本质
//template<class K,class V>
//inline pair<K,V> make_pair(const K&k,const V&v){
//  return pair<K,V>(k,v);
//}
void test_map(){
  map<string,string> ms;
  ms.insert(pair<string,string>("apple","苹果"));
  ms.insert(pair<string,string>("banana","香蕉"));
  ms.insert(pair<string,string>("smell","闻起来"));
  ms.insert(make_pair("good","好"));//显示好
  ms.insert(make_pair("good","坏"));
  cout<<ms["good"]<<endl;
  cout<<endl;
  ms["good"]="notgood";
  ms["left"]="左边";
  ms["left"]="右边";//同时用[],则会显示的是最后插进去的
  map<string,string>::iterator mit=ms.begin();
  while(mit!=ms.end()){
    mit->second="yyy";//将value全部变成yyy
    cout<<(*mit).first<<"-"<<(*mit).second<<" ";
   // cout<<mit->first<<"-"<<mit->second<<" ";

   mit++; 
  }
  cout<<endl;
  for(const auto&e:ms){
cout<<e.first<<":"<<e.second<<endl;
  }
}
void test2(){
  string word;
  //统计单词出现的个数
  map<string,int>countmap;
//  for(size_t i=0;i<word.size();++i){
for(auto&e:word){
  auto it=countmap.find(e);
  if( it!=countmap.end()){
it->second++;
  }
  else{
    countmap.insert(make_pair(e,1));
  }
  }
for(auto e:countmap){
cout<<e.first<<" "<<e.second<<endl;
}
}
int main(){
//test_set();
test1();
test_map();
  return 0;
}
