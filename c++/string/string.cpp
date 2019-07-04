#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
void test(){
  std::string str1;
 //std::string str2;
  std::string str3(10,'a');//string类型的str3 10个a
  std::string str2("nihao");//构造c风格字符串
 //str2("nihao");//定义c风格字符串不能定义了成员string str2再这样会
  std::string str4(str3);//拷贝构造str3
  std::string str5(str2);//拷贝构造str2
  cin>>str1;
  cout<<str1<<endl;
  cout<<str1.c_str()<<endl;
  cout<<str2<<endl;
  cout<<str3<<endl;
  cout<<str4<<endl;
  cout<<str5<<endl;
}
void teststring(){
  std::string str1("nihao");
cout<<"length:"<<str1.length()<<endl;//11
cout<<"size:"<<str1.size()<<endl;//11
cout<<"capacity:"<<str1.capacity()<<endl;//11
cout<<str1<<endl;
str1.clear();//清理
cout<<"清理"<<endl;
cout<<"size:"<<str1.size()<<endl;//0
cout<<"capacity:"<<str1.capacity()<<endl;//11
cout<<"重新写入10"<<endl;
str1.resize(10,'a');//重新写入10个a
cout<<str1.size()<<endl;
cout<<str1<<endl;
cout<<str1.capacity()<<endl;
cout<<"有效字符增加到15个"<<endl;
str1.resize(15);
cout<<"size:"<<str1.size()<<endl;
cout<<str1<<endl;
cout<<"capacity"<<str1.capacity()<<endl;//容量显示20但是写了10个a扩容到15个加上之前
//清理的nihao空余的一共20
//将容量缩小到5
str1.resize(5);
cout<<"容量变缩小后"<<endl;
cout<<"size"<<str1.size()<<endl;
cout<<str1<<endl;
cout<<"capacity:"<<str1.capacity()<<endl;
//只改变了个数size但是容量是无法缩小的

}
void test6(){
  std::string s;
  s.resize(100);
  cout<<"size resize:"<<s.size()<<endl;
  cout<<"capacity resize"<<s.capacity()<<endl;
   s.resize(50);
   cout<<"缩小后的size"<<s.size()<<endl;
   cout<<"capacity"<<s.capacity()<<endl;
}
void test2(){
  std::string s;
  s.reserve(100);
  cout<<"reserve size"<<s.size()<<endl;
  cout<<"reserve capacity"<<s.capacity()<<endl;
   s.reserve(50);
   cout<<"size reserve"<<s.size()<<endl;
   cout<<"reserve capacity"<<s.capacity()<<endl;
   //reverse容量可以缩小
}
void test3(){
  //对象访问操作符[]
std::string s1("nihao");
const std::string s2("nihao");
cout<<s1<<" "<<s2<<endl;
cout<<s1[0]<<" "<<s2[0]<<endl;
s1[0]='H';
cout<<s1[0]<<endl;
//s2[0]='h';不能通过因为是const修饰

for(size_t i=0;i<s1.size();i++){
//将打印为nihao-hnihao因为s1[0]被该为H了
  cout<<s1[i]<<endl;
}
}
void test4(){
  //字符串相加
  std::string str("nihao");
  str.push_back(' ');//str后加空格
cout<<str<<endl;
str.append("hehe");
cout<<str<<endl;
str+='b';//追加字符
str=str+'b';//+=运算符重载但是str=str+b也可以
str+=" abc";//追加字符串
str=str+" ac";
cout<<str<<endl;
}
void test5(){
  //length和size没有区别?c_str(),打印字符串
  std::string str1("nihaoshijie");
  cout<<"length:"<<str1.length()<<endl;
  cout<<"size:"<<str1.size()<<endl;
  cout<<"c_str():"<<str1.c_str()<<endl;
  cout<<str1<<endl;
  str1.clear();
  cout<<"length:"<<str1.length()<<endl;
  cout<<"size:"<<str1.size()<<endl;
  cout<<"c_str():"<<str1.c_str()<<endl;
  cout<<str1<<endl;
}
int main(){
//test();
//teststring();
test6();
test2();
//test3();
//test4();
//test5();
  return 0;
}
