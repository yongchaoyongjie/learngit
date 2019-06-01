#include<iostream>
#include<stdio.h>
#include<algorithm>
using std::endl;
using std::cout;
using std::cin;
void test1(){
  int a[]={1,2,3,4};
  int *b=a;
  *b+=2;
  cout<<"(*b+=2)"<<*b<<endl;//3
  *(b+2)=2;
  cout<<"*(b+2=2)"<<*b<<endl;//3
  cout<<"没有+之前"<<*b<<endl;
  b++;
  cout<<*b<<endl;
  printf("%d,%d\n",*b,*(b+2));//2  4
}
void test2(){
  class example{
    public:
    example(int x){
//p=new int(x);
//p=new int(x);//不兼容的int*分配到int 无效的*
//*p=new (int*)(x);//不能将初始化为int值转为int*
//*p=x;-->野指针
p=&x;//-->也是运行等于5??
    }
    ~example(){

    }
    int show(){
      return *p;
    }
    private:
    int *p;
  };
  example S(5);
cout<<S.show()<<endl;
}
void daozhi(){
//woaini.--->ni.aiwo
//怎么读出空格cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
  std::string str1,str2;
  cin>>str2;
while(cin>>str1){
str2=str1+" "+str2;
}
cout<<str2<<endl;
}
void daozhi1(){
  std:: string s;
  getline(cin,s);
  reverse(s.begin(),s.end());//输入字符串全部翻转
  std::string::iterator jieshu=s.begin();
  while(jieshu!=s.end()){
    std::string::iterator kaishi=jieshu;
    while(kaishi!=s.end()&&*kaishi!=' '){
    kaishi++;
  }
    reverse(jieshu,kaishi);//局部逆转
    if(kaishi!=s.end()){
      jieshu=kaishi+1;
    }
    else{
      jieshu=kaishi;
    }
}
cout<<s<<endl;
}
int main(){
//test1();
//test2();
//daozhi();
daozhi1();
  return 0;
}
