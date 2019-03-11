//编写一个程序显示你的姓名和地址
#include <iostream>
//int main(){
//using namespace std;
////cout<<"my name chenyongjie\n";
////cout<<"my address is shanxi xi'an shanxikejidaxue\n";
//////要求用户输入以Long为单位的距离,然后将他转化为码(1long=220码)
////int long1;
////cout<<"请输入距离\n";
////cin>>long1;
////int ma=220*long1;
////cout<<"ma="<<ma<<endl;
//return 0;
//}
//用三个用户定义的函数生成下面输出:
//three bilind mice
//three blind mice
//see how they run
//see how they run
//void mice();
//void run();
//int main(){
//mice();
//mice();
//run();
//run();
//  return 0;
//}
//void mice(){
//  std::cout<<"three blind mice\n";
//}
//void run(){
//  std::cout<<"see how they run\n";
//}
//编写一个程序用户输入其年龄然后显示该年龄包含多少个月
//double exc(double);
//int main(){
//using namespace std;
////cout<<"enter your age !\n";
////int age;
////cin>>age;
////cout<<"your name inclue"<<12*age<<"month"<<endl;
//cout<<"请输入华氏温度!\n";
//double T;
//cin>>T;
//double F;
//F=exc(T);
//cout<<"华氏温度为"<<F<<endl;
//return 0;
//}
//double exc(double t){
//return 1.8*t+32;
//}
//double exchange(double);
//int main(){
//using namespace std;
//cout<<"enter the number of light year:\n";
//double year;
//cin>>year;
//cout<<year<<"light years="<<exchange(year)<<"astronomical"<<endl;
//  return 0;
//}
//double exchange(double x){
//  return 63240*x;
//}
void enter();
 int  main(){
enter();
return 0;
  }
void enter(){
  std::cout<<"enter the number of hours:\n";
  int hours;
  std::cin>>hours;
  std::cout<<"hours"<<hours<<std::endl;
std::cout<<"enter the number of mins:\n";
int mins;
std::cin>>mins;
std::cout<<"minutes"<<mins<<std::endl;
std::cout<<"time"<<hours<<":"<<mins<<std::endl;
}
