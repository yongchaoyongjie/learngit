#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
//重复n次的元素
int tongjicishu(vector<int>&A){
size_t d=A.size();
unordered_map<int,int> m;
//统计重复n次的元素
for(auto &e:A){
  m[e]++;
}
for(auto &e:m){
  if(e.second==d){
return e.first;
  }
}
}
//两个数组的交集
vector<int>jiaoji(vector<int>&a,vector<int>&b){
//用unorderset对数组中的元素去重
unordered_set<int>s1;
for(auto &e:a){
s1.insert(e);
}
unordered_set<int>s2;

for(auto &e:b){
  s2.insert(e);
}
vector<int>vret;
for(auto &e:s1){
  if(s2.find(e)!=s2.end()){
    vret.push_back(e);
  }
  return vret;
}
}
//给定两个数组求交集
vector<int>jiaoji2(vector<int>&a,vector<int>&b){
unordered_map<int,int>dict;
vector<int>res;
for(auto&i:a){
  dict[i]++;
}
for(auto&j:b){
  if(dict[j]){
    res.push_back(j);
    dict[j--];
    if(dict[j]==0){
      dict.erase(j);
    }
  }
  return res;
}

}
//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同
//则返回 false。
bool contain(vector<int>&nums){
  unordered_set<int>set1(nums.begin(),nums.end());
return set1.size()!=nums.size();
}
vector<string> uncommonFromSentences(string A, string B) {
 unordered_map<string,int> m;
 string temp;
 stringstream is(A);
 while(is>>temp) m[temp]++;
 is =stringstream(B);
 while(is>>temp) m[temp]++;
vector<string> ret;
 for(unordered_map<string,int>::iterator i =m.begin();i!=m.end();i++){
 if(i->second==1)
 ret.push_back(i->first);
}
 return ret;
                                                                      
}
int main(){


  return 0;
}
