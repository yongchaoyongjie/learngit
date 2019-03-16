#include <iostream>
//int main(){
//using std::cout;
//using std::cin;
//using std::endl;
//计算一个字符串有多少个字母和空格
//char ch;
//int space=0;
//int total=0;
//cin.get(ch);
//while(ch!='.'){
//  if(ch==' '){
//++space;
//  }
//++total;
//cin.get(ch);
//
//}
//cout<<"space="<<space<<endl;
//cout<<"total="<<total<<endl;
//通过字母进行加密编码来修改输入的文本(换行符不变),这样每个输入行都被
//转换为一行输出而且长度不变,意味着程序对换行符采用一种操作,对其他字符采取
//另一种操作
//char ch;
//cout<<"type,and i shall repeat.\n";
//cin.get(ch);
//while(ch!='.'){
//  if(ch=='\n'){
//    cout<<ch;
//  }
//  else{
//    cout<<++ch;
////    cout<<++ch;
////ch=ch+1;
// //   cout<<ch;
//  }
//  cin.get(ch);
//}
////找到你最喜欢的数0-100
//const int fave=27;
//int n;
//cout<<"enter a number in the range 1-100 to find:\n";
//cout<<"my favotate number:";
//do{
//  cin>>n;
//  if(n<fave){
//    cout<<"TOOlow--enter again:";
//  }
//  else if(n>fave){
//cout<<"TOOhigh--enter again:";
//  }
//  else{
//    cout<<"eter is right the value is "<<n<<endl;
//  }
//}while(n!=fave);
//一个选择程序y结束程序n继续
//cout<<"this program may reformat your hard disk\n"
//  "and destroy all your date.\n"
// " do you wish to continue ?<y/n>";
//char ch;
//cin>>ch;
//if(ch=='y'||ch=='Y'){
//  cout<<"you were warned!\a\a\n";
//}
//else if(ch=='n'||ch=='N'){
//  cout<<"a wise chioce..bye\n";
//}
//else{
//  cout<<"that wasn't a y or n! apparently you"
//  "can't follw\ninstructions,so"
//    "i'll trash your disk anyway.\a\a\a\n";
//
//}
  //return 0;
//}
//这个程序有问题,一个测试数组被填满时候循环结束一个测试(temp>=0)让
//用户通过输入一个负值来提前结束循环;
//const int arise=6;
//int main(){
//using namespace std;
//float naaq[arise];
//cout<<"enter the naaqs(new age awareness quotients)"
//"of\nyour neighboors.program terminates"
//"when you make\n"<<arise<<"entries"
//"or enter a negative value.\n";
//int i=0;
//float temp;
//cout<<"first value:";
//cin>>temp;
//while(i<arise&&temp>=0){
//naaq[i]=temp;
//++i;
//if(i<arise){
//  cout<<"next value:";
//}
//cin>>temp;
//}
//if(i==0){
//  cout<<"no date--bye\n";
//}
//else{
//  cout<<"enter your naaq:";
//  float you;
//  cin>>you;
//  int count=0;
//  for(int j=0;j<i;j++){
//
//    if(naaq[j]>you ){
//      ++count;
//    }
//  }
//  cout<<count;
//  cout<<"of your neighbors have greater awareness of\n"
//    "the new age than you do.\n";
//}
//
//const char* qualify[4]={
//  "100meters race.\n",
//  "mud tug-of-war.\n",
//  "masters canoe jousting.\n",
//  "pie-throwing festival.\n"
//};
//int main(){
//  using namespace std;
//  int age;
//  cout<<"enter your age in year\n";
//  cin>>age;
//  int index;
//  if(age>17&&age<35){
//    index=0;
//  }
//  else if(age>=35&&age<50){
//    index=1;
//  }
//  else if(age>=50&&age<65){
//    index=2;
//  }
//  else{
//    index=3;
//  }
//  cout<<"your qualify for the"<<qualify[index]<<endl;
//return 0;
//}
//用来筛选可赋值给int变量的数字输入如果用户定义的函数is_int的参数
//位于int类型之内则返回true然后循环拒绝不在该取值范围内的值
//#include<climits>
//bool is_int(double);
//int main(){
//using namespace std;
//double num;
//cout<<"you dude!enter an integer value:";
//cin>>num;
//while(!is_int(num)){//真为true假为fale
//  cout<<"out of range--please try again:";
//  cin>>num;
//}
//int val=int(num);
//cout<<"you've entered the integer"<<val<<"\nbye\n";
//return 0;
//}
//bool is_int(double x){
//
//  if(x>=INT_MAX&&x>=INT_MIN){
//return true;
//  }
//  else{
//return false;
//  }
//}
//字符函数cctype
//#include <cctype>
//int main(){
//using namespace std;
//cout<<"enter text for analysis and type@"
//  "to terminate input.\n";
//char ch;
//int whitespace=0;
//int digits=0;
//int chars=0;
//int punct=0;
//int others=0;
//cin.get(ch);
//while(ch!='@'){
//  if(isalpha(ch)){
//    chars++;
//  }
//  else if (isdigit(ch)){
//    digits++;
//  }
//  else if(ispunct(ch)){
//    punct++;
//  }
//  else if(isspace(ch)){
//    whitespace++;
//  }
//  else{
//    others++;
//  }
//  cin.get(ch);
//}
//cout<<chars<<"letters\n"
//<<whitespace<<"space\n"
//<<digits<<"digits\n"
//<<punct<<"punctuations\n"
//<<others<<"others\n";
//  return 0;
//}
//?运算符c=a>b?a:b;三目运算符大于为真为a大于为假为b
//int main(){
//using namespace std;
////int a,b;
////cout<<"enter two numbers";
////cin>>a>>b;
////cout<<"the larger of tow numbers "<<a<<b;
////  int c=a>b?a:b;
////cout<<"is"<<c<<endl;
////比较难懂的?
//const char x[2][20]={"jame","liming"};
//const char* y="papa";
//for(int i=0;i<3;i++){
//
//  cout<<((i<2)?!i?x[i]:y:x[1]);
//}
//
//  return 0;
//}
//swich语句
//写一个目录程序
using namespace std;
void showmenu();
void report();
void comfort();
int main(){
showmenu();
int chice;
cin>>chice;
while(chice!=5){
  switch(chice){
    case 1:cout<<"\a\n";
           break;
  case 2:report() ;
         break;
  case 3:cout<<"the boss was in all day.\n" ;
         break;
  case 4:comfort();
         break;
  default: cout<<"that's not a choic.\n";
}
showmenu();
cin>>chice;
}
cout<<"bye!\n";
return 0;
}
void showmenu(){
  cout<<"please enter 1,2,3,4,5,:\n"
    "1>alarm      2>report\n"
    "3>alibi      4>comfort\n"
    "5>quit\n";
}
void report(){
  cout<<"it's been an excellent week for business.\n"
    "salas are up 120%.expenses are down35%.\n";
}
void comfort(){
  cout<<"your employees think you are the finest CEO\n"
    "int the industy,the board of directors think\n"
    "you are the finest CEO in the industy\n";
}
