#include<iostream>
#include<string>
#include<cstring>
int main(){
using namespace std;
//cin.get()与getLine()类似,接受参数的方式也一样解释参数的方式也相同,并且都读到
//行尾,但cin.get(),并不在读取并丢弃换行符,而是将其留在输入队列中,如果进行两次的
//cin.get(),则中间必须添加一次cin.get(),空的调用因为调用完一次如果不进行空调用则
//第一次的字符便是换行符用不带参数的cin.get()调用可读取下一个字符(即是是换行符);
//因此空的调用可以处理换行符为读取下一行输入做准备
//const int arise=20;
//char name[arise];
//char dessert[arise];
//cout<<"enter your name:\n";
//cin.get(name,arise).get();//等价于cin.get(name,arise);cin.get()
//cout<<"enter your favorate food\n";
//cin.get(dessert,arise).get();
//cout<<"i have some delicious "<<dessert<<" for you:\n"<<name<<endl;
//混合输入字符串和数字
//cout<<"what's year was your house built?\n";
//int year;
//cin>>year;
//cout<<"what is street address?\n";
//char address[80];
//cin.getline(address,year);
//cout<<"year built:"<<year<<endl;
//cout<<"Address"<<address<<endl;
//cout<<"done!\n";
//  return 0;
//}
//bug没有机会输入地址直接输出
//问题是cin读取年份将回车键生成的换行符留在了输入队列后面的cin.get(),
//看到换行符后将认为是一个空行,并将一个公子扶串复制给address数组
//解决的问题是在读取地址之前先读取并丢弃换行符
//法一在读取后用一次空调用即是cin.get()
//法2用表达式cin>>year返回cin对象将调用函数拼接起来
//cout<<"what's year was your house built?\n";
//int year;
////cin>>year;
////cin.get();
//(cin>>year).get();
//cout<<"what is street address?\n";
//char address[80];
//cin.getline(address,year);
//cout<<"year built:"<<year<<endl;
//cout<<"Address:"<<address<<endl;
//cout<<"done!\n";
//string类
//string str="addsf"看字符串第三个字母则用str[2]则会显示d
//char charr1[20];
//char charr2[20]="jaguar";
//string str1;
//string str2="panther";
//cout<<"enter a kind of feline:\n";
//cin>>charr1;
//cout<<"enter another feline:\n";
//cin>>str1;
//cout<<"here are some felines:\n";
//cout<<charr1<<" "<<charr2<<" "<<str1<<" "<<str2<<endl;
//cout<<"the third letter in"<<charr2<<"is:"<<charr2[2]<<endl;
//cout<<"the third letter in"<<str2<<"is:"<<str2[2]<<endl;
//c风格字符串的拼接以及string类的拼接
//s1+=s2,在s1尾部添加字符串s2
//string s1="nihao";
//string s2,s3;
//cout<<"ni keyi jiang s1的zifuchuan fuzhi gei s2,s2=s1\n";
//s2=s1;
//cout<<"s1="<<s1<<",s2="<<s2<<endl;
//cout<<"you can assign c-style string to a string object\n";
//cout<<"s2=\"buzzd\"\n";
//s2="buzzd";
//cout<<"s2:"<<s2<<endl;
//cout<<"you can conect s3=s2+s1\n";
//s3=s2+s1;
//cout<<"s3:"<<s3<<endl;
//cout<<"you can append string:\n";
//s1+=s2;
//cout<<"s1+=s2:"<<s1<<endl;
//s2+="for a day";
//cout<<"s2+=\"for a day\" yield s2="<<s2<<endl;
////关于c风格字符串的拼接和计算长度 以及string类的拼接和计算长度
////关于计算string类字符串所包含的字母个数用str1="baobao";str1.size();
//char charr1[20];
//char charr2[20]="nihao";
//string str1;
//string str2="baobao";
//str1=str2;
//strcpy(charr1,charr2);
//cout<<"charr1:"<<charr1<<endl;
//str1+="aini";
//cout<<"str1+="<<str1<<endl;
//strcat(charr1,"shijie");
//cout<<"拼接后为:"<<charr1<<endl;
//int len1=str1.size();
//int len2=strlen(charr1);
//cout<<"str1包含字母为:"<<len1<<endl;
//cout<<"charr1包含字母为:"<<len2<<endl;
char charr[20];
string str;
cout<<"长度charr为"<<strlen(charr)<<endl;
cout<<"长度string在输入前为:"<<str.size()<<endl;
cout<<"enter a line of text\n";
cin.getline(charr,20);//将一行输入读取到数组中
cout<<"你在charr中输入的字符串为"<<charr<<endl;
cout<<"enter another line of text\n";
getline(cin,str);//将一行输入读取到字符串str中
cout<<"你在str中输入的字符串为"<<str<<endl;
cout<<"length of charr is:"<<strlen(charr)<<endl;
cout<<"length of str is: "<<str.size()<<endl;
return 0;
}
