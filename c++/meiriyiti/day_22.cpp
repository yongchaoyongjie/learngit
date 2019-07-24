#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int runnian(int year){
  if(year%400==0||((year%100!=0)&&(year%4==0))){
    return year;
  }
}
int full_of_year(int year){
  return 2*31+1*28+1*31+2*30+1*31+2*30+1*31+
    2*31+2*30+2*31+1*30+2*31+runnian(year);
}
bool issushuyue(int n){
  return (n==2)||(n==3)||(n==5)||(n=7)||(n==11);
}
//求一个日子是这一年的第几天
int day_isyear(int year,int month,int day){
  if(issushuyue(month)){
    day*=2;
  }
  while(--month) {
    switch(month){
      case 1:
case 8:
case 10:
case 12:
        day+=62;
        break;
case 3:
case 5:
case 7:
        day+=31;
        break;
case 4:
case 6:
case 9:
day+=60;
break;
case 11:
day+=30;
break;
case 2:
day+=28+runnian(year);
break;
default:;
    }
  } 
  return day;
}

void test(){
int year1,month1,day1,year2,month2,day2;
int count_profit=0;
while(cin>>year1>>month1>>day1>>year2>>month2>>day2){
  count_profit=0;
count_profit+=full_of_year(month1)+day_isyear(year1,month1,day1-1);
count_profit+=day_isyear(year2,month2,day2);
if(year1==year2){//如果是同一年要减去这一年的天数
count_profit-=full_of_year(year1);
}
//中间隔无数年需要加上隔着年的天数
for(int i=year1+1;i<year2;++i){
  count_profit=full_of_year(i);
}
cout<<count_profit<<endl;
}

}
//求斐波那契数列第几项的后6位是多少
void test1(){
int fib[100001];
fib[0]=1;
fib[1]=1;
for(int i=2;i<=100000;++i){
  fib[i]=fib[i-1]+fib[i-2];
  if(fib[i]/100000>0){
    fib[i]=fib[i]%100000;
  }
}
int n;
while(cin>>n){
  if(n<29){
    printf("%d\n",fib[n]);
  }
  else{
    printf("%06d\n",fib[n]);//06保存最后6位
  }
}
}

int main(){
//test();
test1();
  return 0;
}
