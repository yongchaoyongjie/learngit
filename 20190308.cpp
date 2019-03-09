#include<iostream>
#include<cstring>
//int main(){
//using namespace std;
////如何运用运算符
//float hats,heads;
//cout.setf(ios_base::fixed,ios_base::floatfield);//只是为了显示小数点后面的0
//cout<<"enter a number";
//cin>>hats;
//cout<<"enter another number";
//cin>>heads;
//cout<<"hats="<<hats<<endl;
//cout<<"heads="<<heads<<endl;
//cout<<"heads+hats"<<heads+hats<<endl;
//cout<<"hats-heads"<<hats-heads<<endl;
//cout<<"hat*heads"<<hats*heads<<endl;
//cout<<"hats/heads"<<hats/heads<<endl;
//cout<<"9/5="<<9/5<<endl;
//cout<<"9.0/5.0="<<9.0/5.0<<endl;
//cout<<"9.0/5="<<9.0/5<<endl;
//cout<<"1.e7/9.0="<<1.e7/9.0<<endl;
//cout<<"1.e7f/9.0f="<<1.e7f/9.0f<<endl;
//求模运算
//const int Lbs_per_stn=14;
//int onebs;
//cout<<"enter yout weight:";
//cin>>onebs;
//int stone=onebs/Lbs_per_stn;
//int  poud=onebs%Lbs_per_stn;
//cout<<onebs<<"poud are"<<stone<<"stone"<<poud<<"poud(s)"<<endl;
//潜在的赋值转换
//cout.setf(ios_base::fixed,ios_base::floatfield);
//float tree=3;
//int guess(3.9823);
//int debt=7.2e12;
//cout<<"tree="<<tree<<endl;
//cout<<"guess="<<guess<<endl;
//cout<<"debt="<<debt<<endl;
//
//强制转换直接的运算
//int a,b,c;
//a=19.99+11.99;
//b=(int)19.99+(int)11.99;
//c=int (19.99)+int(11.99);
//cout<<"a="<<a<<"\n"<<"b="<<b<<"\n"<<"c="<<c<<endl;
//char ch='Z';
//cout<<"字母为"<<ch<<endl;
//cout<<int(ch)<<endl;//第二种强转类型方式
//cout<<"是的字母为:"<<static_cast<int>(ch)<<endl;//第1种强转类型
//  return 0;
//  //关于static_cast<int>(ch)可以将值从一种数值类型转换为另一种数值的类型
//}
//复合类型数组
//int yam[3];
//yam[0]=7;
//yam[1]=8;
//yam[2]=6;
//int yams[3]={2,3,4};
//cout<<"total yam="<<yams[0]+yams[1]+yam[2]<<endl;
//cout<<"the package with"<<yam[1]<<"yams cost"<<yams[1]<<"cents pre\n";
//int total=yam[1]*yams[1]+yams[0]+yam[0];
//total=total+yam[2]*yams[2];
//cout<<"全部"<<total<<endl;
//cout<<"yam字节"<<sizeof(yam)<<"bites.\n";
//cout<<"yams 字节"<<sizeof(yam[0])<<"bites.\n";
//return 0;
//拼接字符串
//const int size=15;
//char name[size];
//char name1[size]="chenxiao";
//cout<<"nihao我是"<<name1<<"nijiao什么名字";
//cin>>name;
//cout<<"enwo的名字是"<<name<<"your name has ";
//cout<<strlen(name1)<<"worlds\n";
//cout<<"在数组中你有"<<sizeof(name)<<"个字节"<<
//"你名字的首字母为"<<name[0]<<endl;
//name1[3]='\0';
//cout<<"你名字的前三个字母为"<<name1<<endl;
//return 0;
//}
//int main(){
//  using namespace std;
//  const int arsize=20;
//  char name[arsize];
//  char dessert[arsize];
//  cout<<"shuru ni d mingzi";
//  cin>>name;
//  cout<<"shuru ni zuixihuan d chid "<<endl;
//  cin>>dessert;
//  cout<<"w you yixie haochi d fan "<<dessert<<" for you "<<name<<"\n";
//  return 0;
//}
//程序改进用面向行的输入getline
//通过回车键的换行符确定结尾第一个参数存储输入行的名称
//第二个参数要读取的字符数
int main(){
  using namespace std;                                                 
  const int arsize=20;                                                 
  char name[arsize];                                                   
  char dessert[arsize];                                                
  cout<<"shuru ni d mingzi";                                           
  cin.getline(name,arsize);                                                           
  cout<<"shuru ni zuixihuan d chid "<<endl;                            
  cin.getline(dessert,arsize) ;                                                        
  cout<<"w you yixie haochi d fan "<<dessert<<" for you "<<name<<"\n"; 
return 0; 
}
