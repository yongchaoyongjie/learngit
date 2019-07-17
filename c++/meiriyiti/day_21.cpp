#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<math.h>
using namespace std;
void test(){
//求一个数的因子个数
int n;
int count;
while(cin>>n){
  count=0;
  for(int i=2;i<=sqrt(n);++i){
    if((n%i)==0){
      while((n%i)==0){
        n=n/i;
      }
      count++;
    }
  }

if(n!=1){
  count++;
}
  cout<<count<<endl;
}
}
//给定某年生成节假日期--是根据周来分节假日的
//1号周三我要周五那么(5-3)+1即可求出第一个周五是3号那么反过来是所求星期数小
//例如1号周三我要周一那么显然要先把周一看成周八才行。也就是(8-3)+1。第一个周
//一是6号，所以统统都让它加7以后减，减完后的结果再mod一下7，就能得到结果了
//就是(所求星期数+7-1号星期数)%7+1。这样我们就拿到了求第一个周几公式。随后
//只需要在这个公式上加上7*(n-1)即刻求出第n个周几。
int day_ofweek(int year,int month,int day){
  if(month==1||month==2){
month+=12;
year-=1;
  }
  int century=year/100;
  year%=100;
int week;
week=year+(year/4)+(century/4)-2*century+(13*2*(month+1)/(2*5))+day-1;
week=(week%7+7)%7;
if(week==0){
  week=7;
}
return week;
}
int day_ofdemand(int year,int month,int count,int d_of_week){
  int week=day_ofweek(year,month+1,1);
  int day=1+(count-1)*7+(7+d_of_week-week)%7;
  return day;
}
void new_year_day(int year){
    cout<<year<<endl;
    cout<<"01-01"<<endl;
}
void marding_luther_king_day(int year){
    cout<<year<<endl;
printf("%d-01-%02d\n",year,day_ofdemand(year,1,3,1));
}
void president(int year){
  printf("%d-02-%02d\n",year,day_ofdemand(year,2,3,1));
}
void die_of_solider(int year){
  int week=day_ofweek(year,6,1);
  int day;
  day=21-((week==1)?6:(week-2));
printf("%d-05-%02d\n",year,day);
}
void independeceday(int year){
  printf("%d-07-04\n",year);
}
void laodong_jie(int year){
  printf("%-09-%02d\n",year,day_ofdemand(year,9,1,1));
}
void thanksgive_day(int year){
  printf("%d-11-%02d\n",year,day_ofdemand(year,11,4,4));

}
void christm(int year){
  printf("%d-12-25d\n",year);

}
void holiday_of_usa(int year){
  new_year_day(year);
  marding_luther_king_day(year);
  president(year);
  independeceday(year);
  laodong_jie(year);
  thanksgive_day(year);
  christm(year);
  die_of_solider(year);
}
void test2(){
int year;
while(cin>>year){
  holiday_of_usa(year);
  cout<<endl;
}

}
void test3(){
  int n;
  while(cin>>n){
    //cout<<n;
    printf("%d=",n);
    for(unsigned i=2;i<sqrt(n);++i){
      while(n%i==0&&(n!=i)){//反复除一个数直到除不尽为止，排除刚好是N的次方的
      //情框
      printf("%u*",i);
     //   cout<<i<<"*";
     //
        n/=i;//能整除则修改N
      }
    }
    printf("%d\n",n);
   // cout<<n<<endl;
  }
}
int main(){
//test();
//test2();
test3();
}
