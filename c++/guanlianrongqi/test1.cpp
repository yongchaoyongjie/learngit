#include<unordered_map>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//大小为2n的数组a中有n+1个不同的元素其中一个元素重复了n次,求返回重复N次的那个元素
int reapettime(vector<int>&A){
unordered_map<int,int>count;//存数和次数
for(auto&e:A){
  count[e]++;//存在改变它的值不存在则插入插入进去后再++,插入是默认的值int默认0
//一开始0+1后面就是修改
}
for(const auto&e:count){
  //遍历判断哪个出现了n次
  if(e.second==A.size()/2){
    return e.first;
  }
}
return 0;
}
//两个数的交集去重两个set分别存放vector,遍历一个去看另外一个有没有包含如果有
//是交集
//存在重复元素出现两次返回对小于两次返回false
vector<int>insertion(vector<int>&num1,vector<int>&num2){
  unordered_set<int>set1;
  unordered_set<int>set2;
  for(const auto&e:set1){
    set1.insert(e);
  }
  for(const auto&e:set2){
    set2.insert(e);
  }
  vector<int> v;//容器存放
  for(const auto&e:set2){
    if( set2.find(e)!=set1.end()){
      v.push_back(e);
    }
  }
return v;
}
//判断一个数组存在重复元素
bool contains(vector<int>&nums){
  unordered_set<int>s1;
  for(const auto& e:nums){
if(!(s1.insert(e)).second)//插入的时候直接判断,元素存在插入失败,拿插入返回值
  //去判断它
  return true;
  }
return false;
}
//给定两个句子a,b,如果一个单词在其中一个句子出现一次另一个句子没有则这个单词不常见
vector<string>unbuhchangjian(string a,string b){
  //两句话合成一句统计,只出现一次
a +=' ';//两个拼成一个
a +=b;
unordered_map<string,int >map1;
//按照单词分割,然后统计次数
size_t start=0;
size_t pos=0;
do{
//size_t pos=a.find(' ',0);//从0位置开始找,单词拿出来,找出空格出现的位置
//a.substr(0,pos);//从0开始拿,下次从pos+1位置找---走循环
pos=a.find(" ",start);//找空格,从start开始构建一个substr,然后存放在map1[]里面
map1[a.substr(start,pos-start)]++;//拿多少个单词
start=pos+1;//然后从pos+1开始走
}
while(pos!=string::npos);//统计完判断是否出现一次--遍历
vector<string>v;
for(const auto& e:map1){
  if(e.second==1){
    v.push_back(e.first);//只放单词
  }
  return v;
}
}
//前k个高频单词
//单词出现频率由高到底排序
//i love you  i love me --i love 都出现两次
//统计每个单词次数  
class solution{
  public:
vector<string> topfrequentworld(vector<string>&world,int k){
//统计次数要++--[]map  
map<string,int>count;
vector<string>v;
for(auto&e:world){//e就是k
  //按字母序走
  count[e]++;//单词出现的个数都统计了
}
//map按string排序而不是按出现的次数排序是按字母序出现的频率,所以以出现的次数为
//key,--所以用multimap有重复的string
multimap<int,string,greater<int>> retmap;//i  和love  //great<int>给的是仿函
//数对象,从大到小排列,按照大于比较
for(const auto& e:count){
  retmap.insert(make_pair(e.second,e.first));//按次数出现从小到大排
}
//在遍历反向走
//auto mit=retmap.rbegin();//字母序反的字母序按照从大到小排序
for(const auto&e:retmap){
  if(k-->0){
    v.push_back(e.second);
  }
}
return v;
}
};
