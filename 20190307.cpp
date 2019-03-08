#include <iostream>
//int main(){
//  int carrots;
//  carrots=25;
//  std::cout<<"i have"<<carrots<<"carrots"<<std::endl;
//carrots=carrots-1;
//std::cout<<"now i have"<<carrots<<"carrots"<<std::endl;
//  return 0;
//using namespace std;
//int carrots;
//cout<<"how many carrots do you have"<<endl;
//cin>>carrots;
//cout<<"here are two more"<<endl;
//carrots=carrots+2;
//cout<<"now you have "<<carrots<<"carrots"<<endl;
//return 0;
//}
#include <cmath>
//调用sqrt函数
//int main(){
//using namespace std;
//double area;
//cout<<"enter floor area,in square feet,of your home:";
//cin>>area;
//double side;
//side=sqrt(area);
//cout<<"that is the equivalent of a square"<<side<<"feet to the side."<<endl;
//cout<<"how facinating"<<endl;
//  return 0;
//}
//调用自己的函数无返回值
//void simom(int);
//int main(){
//simom(3);
//std::cout<<"pick an integer";
//  int count;
//std::cin>>count;
//simom(count);
//std::cout<<"done"<<std::endl;
//  return 0;
//}
//void simom(int n){
//  std::cout<<"simom says touch your toes"<<n<<"times"<<std::endl;
//}
//调用函数有返回值的情况
//int stonetolb(int);
//int main(){
//using namespace std;
//cout<<"enter the weight in stone:";
//int stone;
//cin>>stone;
//int pounds=stonetolb(stone);
//cout<<stone<<"stone="<<pounds<<"pounds"<<endl;
//  return 0;
//}
//int stonetolb(int a){
//return 14*a;
//}
//查看c++基本类型字节数和最大取值
//#include<climits>
//int main(){
//using namespace std;
//int n_int=INT_MAX;
//short n_short=SHRT_MAX;
//long n_long=LONG_MAX;
//long long n_llong=LLONG_MAX;
//cout<<"int is"<<sizeof n_int<<"bytes."<<endl;
//cout<<"short is"<<sizeof n_short<<"bytes."<<endl;
//cout<<"long is"<<sizeof n_long<<"bytes."<<endl;
//cout<<"long long is"<<sizeof n_llong<<"bytes."<<endl;
//cout<<endl;
//cout<<"MAX value"<<endl;
//cout<<"int"<<n_int<<endl;
//cout<<"short"<<n_short<<endl;
//cout<<"long"<<n_long<<endl;
//cout<<"long long"<<n_llong<<endl;
//cout<<"Mininum int value="<<INT_MIN<<endl;
//cout<<"bits per byte="<<CHAR_BIT<<endl;
//  return 0;
//}
//如何使用无符号类型以及类型越界后的结果
//#define ZERO 0
//#include<climits>
//int main(){
//using namespace std;
//short sam=SHRT_MAX;
//unsigned short sue=sam;
//cout<<"sam has"<<sam<<"yuan and sue has"<<sue<<"yuan"<<endl;
//cout<<"给sam和sue各自加一元"<<endl;
//sam=sam+1;
//sue=sue+1;
//cout<<"sam has"<<sam<<"yuan and sue has"<<sue<<"yuan"<<endl;
//sam=ZERO;
//sue=ZERO;
//cout<<"sam has"<<sam<<"yuan and sue has"<<sue<<"yuan"<<endl;
//cout<<"给Sam和sue各自减一元"<<endl;
//sam=sam-1;
//sue=sue-1;
//cout<<"sam has"<<sam<<"yuan and sue has"<<sue<<"yuan"<<endl;
//  return 0;
//}
////第一位为0,2位为1-9是十进制,第一位0,2位0-7八进制,0x为16进制
//int main(){
//using namespace std;
//int chest=42;
//int waist=0x42;
//int inseam=042;
//cout<<"chest="<<chest<<"十进制"<<endl;
//cout<<"waist="<<waist<<"十六进制"<<endl;
//cout<<"inseam="<<inseam<<"八进制"<<endl;
//  return 0;
//}
//用十进制八进制十六进制输出
//int main(){
//using namespace std;
//int chest=42;
//int waisr=42;
//int inseam=42;
//cout<<"chest="<<chest<<"十进制输出"<<endl;
//cout<<hex<<"waisr="<<waisr<<"十六进制输出"<<endl;
//cout<<oct<<"inseam"<<inseam<<"八进制输出"<<endl;
//  return 0;
//}
//char类型的使用
//int main(){
//using namespace std;
//char ch;
//cout<<"enter a character"<<endl;
//cin>>ch;
//cout<<"chenyongije";
//cout<<"thank you for the "<<ch<<" character"<<endl;
//  return 0;
//}
//cout.put()函数显示一个字符
//int main(){
//using namespace std;
//char ch='M';
//int i=ch;
//cout<<"the ASCII "<<ch<<" is "<<i<<endl;
//cout<<"加1后"<<endl;
//ch=ch+1;
//i=ch;
//cout<<"the now ASCII"<<ch<<" is "<<i<<endl;
//cout<<"用cout.put()"<<endl;
//cout.put(ch);
//cout.put('!');
//cout<<endl<<"done"<<endl;
//cout<<"\n\nwhat next?\nenter a number:\n";
//char alarm='\a';
////c++中/"表示"双引号,\n换行,\t水平制表符,\v垂直制表符,\b退格,\r回车,\a震动\'表示单引号
//cout<<alarm<<"do not do that again!\a\n";
//cout<<"ben\"buggsie\"hacker\nwas here!\n";
////一个密码输入的程序,下划线为8个_
//cout<<"\aoperation\"hyperhype\" is now acticvated!\n";
//cout<<"输入你的密码:________\b\b\b\b\b\b\b\b";
//long mima;
//cin>>mima;
//cout<<"\a你的输入为:"<<mima<<"..."<<endl;
//cout<<"\a你的输入正确开始执行其他任务"<<endl;
//  return 0;
//}
//演示了float和double的精度差异,参数ios_base::fixed和ios_base::floatfield
//通过包含iostream来提供常量,调用cout.setf(),将会使函数保留后面的00,,tub在七位以前是准确的但是七位以后不准确乘以10出现 了2而不是3;而double显示了13个3
int main(){
using namespace std;
cout.setf(ios_base::fixed,ios_base::floatfield);
float tub=10.0/3.0;
double mint=10.0/3.0;
const float million=1.0e6;
cout<<"tub="<<tub<<endl;
cout<<",a millon tubs"<<million*tub;
cout<<",\nand ten million tubs="<<10*million*tub<<endl;
cout<<"mint="<<mint<<"and a million mint="<<million*mint<<endl;
//浮点型一般8.24或者2.4E8属于double,希望为float在后面加f即可
//程序加1减1结果 应该不变但是结果等于0,问题是2.34E+22是一个小数点左边有23个有效
//数字加1在23位加1但是float只能表示前6或者前7位因此修改23位不会有影响
float a=2.34E+22f;
float b=a+1.0f;
cout<<"a="<<a<<endl;
cout<<"b-a="<<b-a<<endl;

  return 0;
}
