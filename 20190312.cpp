//结构,以及将name指定为string对象
#include <iostream>
#include <cstring>
//struct inflatabel{
////char name[20];//法1
//std::string name;//法2
//float volum;
//double price;
//};
//int main(){
//using std::cout;
//using std::cin;
//using std::endl;
//inflatabel guest={
//  "JAMES",
//  1.88,
//  29.99
//};
//inflatabel pal={
//"weide",
//3.12,
//32.99
//}cez;//创建和pal相同的结构体
//cout<<"expand your  guest list with"<<guest.name<<endl;
//cout<<"and"<<pal.name<<endl;
//cout<<"you have both for $";
//cout<<guest.price+pal.price<<endl;
//  return 0;
//}
//结构数组
//struct bbsd{
//  char name[20];
//  float volum;
//  double price;
//};
//int main(){
//using namespace std;
//bbsd ad[2]={
//  {"limi",0.5,21.99},
//  {"fute",2000,565.99}
//};
//cout<<"the ad"<<ad[0].name<<" and "<<""<<ad[1].name<<"\n";
//cout<<ad[1].volum+ad[0].volum<<"\n";
//  return 0;
//}
//地址运算符&
//int main(){
//using namespace std;
//int dount=6;
//double cups=4.5;
//cout<<"dount values="<<dount<<endl;
//cout<<"dount address"<<&dount<<endl;
//cout<<"cups values="<<cups<<endl;
//cout<<"cups address"<<&cups<<endl;
////如何声明指针,指针解引用为值,不解引用为地址,切记int *p;表示指针为p,而*p则为
////指针指向地址的值也就是解引用,值&为地址
////指针初始化int a=3;int *p=&a;
//int update=6;
//int* p_update;
//p_update=&update;
//cout<<"values update="<<update<<endl;
//cout<<"address *p_update="<<*p_update<<endl;
//cout<<"address: &update="<<&update<<endl;
//cout<<"p_update="<<p_update<<endl;
//*p_update=*p_update+1;
//cout<<"now update="<<*p_update<<endl;
//cout<<update<<endl;
//int higgens=5;
//int *pt=&higgens;//指针初始化
//cout<<"value higgens="<<higgens<<endl;
//cout<<"address higgens="<<&higgens<<endl;
//cout<<"value *pt"<<*pt<<endl;
//cout<<"value pt"<<pt<<endl;
//return 0;
//}
////用new 来分配内存,记住new 为运算符
//int main(){
//using namespace  std;
//int nights=1001;
//int*pd=new int;//s申请一个内存给int
//*pd=1001;
//cout<<"nights value="<<nights<<"\nlocation "<<&nights<<endl;
//cout<<"int";
//cout<<"value="<<*pd<<"\nlocation="<<pd<<endl;
//double *pt=new double;
//*pt=10000001.0;
//cout<<"double";
//cout<<"value="<<*pt<<"\nlocation="<<pt<<endl;
//cout<<"location of pointer pt:"<<&pt<<endl;
//cout<<"size of pd="<<sizeof(pd)<<endl;
//cout<<"size of *pd="<<sizeof(*pd)<<endl;
//cout<<"size of pt="<<sizeof (pt)<<endl;
//cout<<"size of *pt="<<sizeof (*pt)<<endl;
//delete pd;
//delete pt;
//  return 0;
//}
//切记使用new要记得释放内存哦
//指针加一等价于数组首元素加1等价于数组名加1
//int main(){
//using namespace std;
//double *p3=new double[3];
//p3[0]=0.2;
//p3[1]=0.5;
//p3[2]=0.8;
//cout<<"p3[1]="<<p3[1]<<endl;
//p3=p3+1;
//cout<<"p3=p3+1后now p3[0]="<<p3[0]<<endl;
//cout<<"p3[1]="<<p3[1]<<endl;
//p3=p3-1;
//cout<<"p3=p3-1后,now p3[0]="<<p3[0]<<endl;
//cout<<"p3[1]="<<p3[1]<<endl;
//delete[] p3;
//  return 0;
//}
//很多情况下可以用相同方式使用数组名和指针,对于数组方括号表示法可以用*解引用,
//但是也有区别数组名是常量而指针可以修改其值
int main(){
using namespace std;
double wages[3]={10000.0,20000.0,30000.0};
short stacks[3]={3,2,1};
double *pw=wages;
short *ps=&stacks[0];
cout<<"pw="<<pw<<",*pw="<<*pw<<endl;
cout<<"ps="<<ps<<",*ps="<<*ps<<endl;
ps=ps+1;
cout<<"ad 1to the ps pointer:\n";
cout<<"ps="<<ps<<",*ps="<<*ps<<endl;
cout<<"access two elements with array notation\n";
cout<<"stacks[0]="<<stacks[0]<<endl;
cout<<"stacks[1]="<<stacks[1]<<endl;
cout<<"access two elements with pointer notation\n";
cout<<"*stacks="<<stacks<<endl;
cout<<"*(stacks+1)="<<*(stacks+1)<<endl;
cout<<sizeof(wages)<<"= sizeof wages array \n";
cout<<sizeof(pw)<<"=sizeof pw pointer\n";
//如何使用不同形式的 字符串
char animal[20]="bear";
const char *bird="wren";//字符串wren地址赋给bird指针
char *pa;
cout<<animal<<" and "<<bird<<endl;
cout<<"enter a kind of animal:\n";
cin>>animal;
pa=animal;//set pa to string;
cout<<pa<<"!\n";//same as using animal
cout<<"before using strcpy()\n";
cout<<animal<<"at"<<(int*)animal<<endl;//一般如果cout提供指针则打印地址,但是如果
//指针类型为char*则cout将显示指向的字符串,如果要显示字符串的地址则必须用(int*)ps//进行强转而(int*)pa显示的是该字符串的地址
//注意animal赋给pa并不会复制字符串而只是复制地址,这样两个指针自相的相同的内存单元和字符串
cout<<pa<<" at "<<(int*)ps<<endl;
pa=new char[strlen(animal)+1];
strcpy(pa,animal);
cout<<"after using strcopy\n";
cout<<animal<<" at "<<(int*)animal<<endl;
cout<<pa<<" at "<<(int *)pa<<endl;
delete [] pa;
return 0;
}
