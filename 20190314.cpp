#include<iostream>
#include <string>
#include <cstring>
//int main(){
  //表达语句
//using namespace std;
//int x;
////调用ios_base::boolalpha,用于显示bool值不调用则会把bool转换为int显示0和1
////调用后bool显示为 true 和false
//cout<<"the expression x=100 has the value\n";
//cout<<(x=100)<<endl;
//cout<<"now x="<<x<<endl;
//cout<<"the expression x<3 has the value\n";
//cout<<(x<3)<<endl;
//cout.setf(ios_base::boolalpha);
//cout<<"the expresssion x>3 has the value\n";
//cout<<(x>3)<<endl;
//cout<<"the expression x<3 has the value\n";
//cout<<(x<3)<<endl;
//const int arsize=16;
//int main(){
//long long factorials[arsize];
//factorials[1]=factorials[0]=1ll;
//for(int i=2;i<arsize;i++){
//factorials[i]=factorials[i-1]*i;
//}
//for(int i=0;i<arsize;i++){
//  std::cout<<i<<"!="<<factorials[i]<<std::endl;
//}
//  return 0;
//}
//修改步长by是用户选择的步长值,同过修改表达式来修改步长
//int main(){
//using std::cout;
//using std::cin;
//using std::endl;
//cout<<"enter an integer:\n";
//int by;
//cin>>by;
//cout<<"counting by"<<by<<"s:\n";
//for(int i=0;i<100;i=i+by){
//cout<<i<<endl;
//}
//  return 0;
//}
////用for访问字符串,按照相反的顺序显示字符串
//int main(){
//  using namespace std;
//  cout<<"enter a world\n";
//string word;
//cin>>word;
//for(int i=word.size()-1;i>=0;i--){
//  cout<<word[i];
//}
//cout<<"原来字符串为:\n";
//  for(int i=0;i<word.size();i++){
//    cout<<word[i];
//  }
//  return 0;
//}
////关于++a和b++;
//++a表示先使用当前值使用完然后加1而b++表示先将b+1然后用新的值计算表达式
//++a属于前缀b++属于后缀,虽然行为没有什么影响但是最好使用前缀,执行时间比较快
//后缀是首先复制一个副本然后将其加1然后将复制的副本返回
//int main(){
//  using namespace std;
//int a=20;
//int b=20;
//cout<<"a="<<a<<": b="<<b<<"\n";
//cout<<"a++="<<a++<<": ++b="<<++b<<"\n";
//cout<<"a="<<a<<": b="<<b<<"\n";
//cout<<"accout sum and average";
//cout<<"five number for you \n";
//cout<<"please enter five number :\n";
//double number;
//double sum=0.0;
//for(int i=1;i<=5;i++){
//cin >>number;
//sum+=number;
//}
//cout<<"and average numeber to "<<sum/5<<endl;
//cout<<"finished";
//return 0;
//}
//关于变量在语句块内部和外部定义的问题
//外部定义变量如果在块内部重新定义则显示的是内部重新的值
//int main(){
//  using namespace std;
//int z=29;
//{
//  cout<<"内部的z"<<z<<endl;
//  int z=100;
//  cout<<z<<endl;
//}
//cout<<z<<endl;
//  return 0;
//}
//将数组中的字符顺序反转
//int main(){
//using namespace std;
////cout<<"enter word:";
////string word;
////cin>>word;
////char temp;
////int i,j;
////for(i=0,j=word.size()-1;i<j;i++,j--){
////temp=word[i];
////word[i]=word[j];
////word[j]=temp;
////}
////cout<<word<<endl;
////cout<<"done\n";
////插找一个字符串?ate于mate相同
//char word[5]="?ate";
//for(char ch='a';strcmp(word,"mate");ch++){
//cout<<word<<endl;
//word[0]=ch;
//}
//cout<<"after loop ends;word is"<<word<<endl;
//return 0;
//}
//你的英文名字的所有ASSIC码
//const int arise=20;
//int main(){
//using namespace  std;
//char name[arise];
//cout<<"enter your fist name:\n";
//cin>>name;
//cout<<"here is your first name your name bssic is:\n";
//int i=0;
////while(name[i]!='\0')//与while(name[i])等价
//while(name[i])
//{
////如果是char类型打印字符串就是字符串如果要求ASSCI必须强转成int
//  cout<<name[i]<<":"<<int(name[i])<<endl;
//  i++;
//}
//return 0;
//}
//如何写一个延时函数
//#include <ctime>
////注意ctime 将clock_t作为clock()返回函数的别名意味着可以将变申请为clock_t类型
////它定义了一个符号常量-CLOCKS_PER_SEC,该常量等于每秒钟包含的系统时间单位数
////所以讲系统时间除以这个常量可以得到秒数,这个常量乘以秒数将得到系统
////时间为单位的时间
//int main(){
//using namespace  std;
//cout<<"enter the delay time:\n";
//float secs;
//cin>>secs;
//clock_t delay=secs*CLOCKS_PER_SEC;
//cout<<"staring\a\n";
//clock_t start=clock();
//while(clock()-start<delay);
//cout<<"done\a\n";
//  return 0;
//}
//dowhile,先执行一次然后判断,这种叫出口循环,
//输入一个1-10的数判断哪个数是自己最喜欢的数
//int main(){
//using namespace  std;
//int n;
//cout<<"enter numbers in the range 1-10 to find";
//cout<<"my favorate number\n";
//do{
//  cin>>n;
//}while(n!=7);
//cout<<"yes 7 is my favorate number\n";
//
//  return 0;
//}
//输入一个字符串用#判断停止字符串的输入并计算输入了几个字符串
//int main(){
//using namespace std;
//char ch;
//int count=0;
//cout<<"enter characters # to stop:\n";
//cin>>ch;
//while(ch!='#'){
//  cout<<ch;
//++count;
////cin>>ch;//此种输入没办法输出空格
//cin.get(ch);
//
//}
//cout<<endl;
//cout<<count<<"character read\n";
//  return 0;
//}
//这是 Bug ,contl +z直接停止程序fg程序继续运行但是无法显示有多少个character
//int main(){
//using namespace  std;
//char ch;
//int count=0;
//cin.get(ch);
//while(cin.fail()==false){
//cout<<ch;
//++count;
//cin.get(ch);
//}
//cout<<endl;
//cout<<count<<"character read\n";
//  return 0;
//}
//一个二维数组的例子
const int City=4;
const int Year=3;
int main(){
using namespace std;
const char *cities[City]={"jianada","meiguo","riben","zhongguo"};
int maxtemps[Year][City]={
{1,2,3,4},
{5,6,7,8},
{9,10,11,12}
};
cout<<"maxtemps for 2008-2010\n\n";
for(int city=0;city<City;++city){
  cout<<cities[city]<<":\t";
  for(int year=0;year<Year;year++){
cout<<maxtemps[year][city]<<"\t";
  }
  cout<<endl;
}

  return 0;
}
