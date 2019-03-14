//访问结构体成员
//访问结构体成员的方法是(1)如果ps是指向结构体的指针则*ps就是被指向的值
//也就是结构体本身,由于*ps是一个结构故(*ps).price是该结构的成员
//也可以用ps->name,
//不明白如何使用.和->,如果结构表示符是结构名则用句点如果标识符是指向结构体的指针
//则使用->
#include <iostream>
//struct inflatable{
//char name[20];
//float volume;
//double price;
//};
//int main(){
//using namespace std;
//inflatable *ps=new inflatable;//用new申请内存为动态连编
//cout<<"enter name of inflatable item:\n";
//cin.get(ps->name,20);
//cout<<"enter volume in cubic feet:\n";
//cin>>(*ps).volume;
//cout<<"enter price:\n";
//cin>>ps->price;
//cout<<"name "<<(*ps).name<<endl;
//cout<<"volume "<<ps->volume<<endl;
//cout<<"price: "<<(*ps).price<<endl;
//delete ps;
//  return 0;
//}
#include <cstring>
//using namespace std;
//char *getname(void);
//int main(){
//char *name;
//name=getname();
//cout<<name<<"at"<<(int*)name<<"\n";
//delete [] name;
//return 0;
//
//  return 0;
//}
//char* getname(){
//char temp[80];
//cout<<"enter last name";
//cin>>temp;
//char *pn=new char[strlen(temp)-1];
//strcpy(pn,temp);
//return pn;
//}
////用cin将输入单词放到temp数组,然后用new分配内存,存储该单词,程序需要
////strlen(temp)+1字符存储(包括/0),获得空间后getname(),用strcp,将temp字符串复制
////到新内存块中,该函数不包含检查内存块释放容纳字符串,单getname(),通过用new,请
////求合适的字节数来完成这样工作,最后函数返回pn,这只字符能穿副本的地址
////在main函数中返回值(地址)被赋值给指针变量name,它指向函数中分配的内存块,
////然后打印字符串及其地址;接下来在释放name指向的内存后main再次调用getname()
////这个例子getname()分配内部main释放内存
//
//struct antar_year_end{
//  int year;
//};
//int main(){
//using std::cout;
//using std::endl;
//antar_year_end s01,s02,s03;
//s01.year=1998;
//antar_year_end *pa=&s02;
//pa->year=1999;
//antar_year_end trio[3];//数组名在c++同指针
//trio->year=2003;
//cout<<trio->year<<endl;
//const antar_year_end *arp[3]={&s01,&s02,&s03};
//cout<<arp[1]->year<<endl;
//const antar_year_end **ppa=arp;
//const antar_year_end **ppb=arp;
////auto ppb=arp;//c++11可以为什么这个不行啊???
//cout<<(*ppa)->year<<endl;
//cout<<(**ppa).year<<endl;
//cout<<(*(ppb+1))->year<<endl;
//return 0;
//}
////明白**ppb.year和*ppb->year
////数组的替代品模板类vector和array
////什么叫模板a3 a4尚未声明????bug
//#include <vector>
//#include<array>
//int main(){
//  using namespace std;
//double a1[4]={1.2,2.4,3.6,4.8};
//vector<double>a2(4);
//a2[0]=1.0/3.0;
//a2[1]=1.0/5.0;
//a2[2]=1.0/7.0;
//a2[3]=1.0/9.0;
//array<double, 4> a3={3.14,2.72,1.62,1.41};
////array<double, 4> a4;
////a4=a3;
//cout<<"a1[2]:"<<a1[2] <<"at"<<&a1[2]<<endl;
//cout<<"a2[2]:"<<a2[2] <<"at"<<&a2[2]<<endl;
//cout<<"a3[2]:"<<a3[2] <<"at"<<&a3[2]<<endl;
////cout<<"a4[2]:"<<a4[2] <<"at"<<&a4[2]<<endl;
////a1[-2]=20.2;
////cout<<"a1[-2]:"<<a1[-2]<<"at"<<&a1[-2]<<endl;
////cout<<"a3[2]:"<<a3[2]<<"at"<<&a3[2]<<endl;
////cout<<"a4[2]:"<<a4[2]<<"at"<<&a4[2]<<endl;
//  return 0;
//}
//循环
int main(){
using namespace std;
//for(int i=0;i<5;i++){
//cout<<"c++ is good \n";
//}
cout<<"enter the starting contdown value:\n";
int limit;
cin>>limit;
int i ;
for(i=limit;i;i--){
cout<<"i="<<i<<"\n";
}
cout<<"done now that i="<<i<<"\n";
  return 0;
}
//程序如何停止,i在等于0时候停止因为c++添加了bool,还有for里面的i是什么意思
//还有最后一个cout 是i=0,为什么???
