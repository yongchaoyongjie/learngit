#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
//跳石板跳的目的为k每次只能跳k的约数步但是不能是1和它自身
//求公约数除了1和它自己,然后将公约数存到容器中
void gongyueshu(int n,vector<int>&gongyue){
  int i=2;
  for(;i<sqrt(n);++i){
    if(n%i==0){
      gongyue.push_back(n/i);
    }
  }
}
//如何跳初始n=1,跳到m的位置
int jump(int n,int m){
  //定义一个vector数组存储到达目标数的步数,初始化n=1;
  vector<int>gongyue(m+1,0);
  gongyue[n]=1;
  for(int i=n;i<m;++i){
    vector<int>shuzu;
    //数组中第i个元素为0表示这个位置不能跳到
    if(shuzu[i]==0){
      continue;
    }
    //求出所有能走到的步数存储到公约这个容器当中
    gongyueshu(i,gongyue);
    for(int j=0;j<shuzu.size();++j){
      if((shuzu[j]+i)<=m&&(gongyue[shuzu[j]+i]!=0)){
        gongyue[shuzu[j]+i]=min( gongyue[shuzu[j]+i],gongyue[i]+1);
      }
      else if((shuzu[j]+i)<=m){
        gongyue[shuzu[j]+i]=gongyue[i]+1;
      }
    }
  }
  if(gongyue[m]==0){
    return -1;
  }else{
    return gongyue[m]-1;
  }
}
void test(){
  int n,m;
  cin>>n>>m;
  cout<<jump(n,m)<<endl;
}
void test1(){
  //计算日期到这年的第多少天的计算
  int array[12] = {31,59, 90, 120, 151, 181, 212,
    243, 273, 304, 334, 365};//存放的是每个月的天数,如果是闰年则在二月的时候
  //多加1天
  int year,month,day;
  int sum=0;
  while(cin>>year>>month>>day){
    sum=0;
    sum+=array[month-2];
    sum+=day;
    if(month>2){
      if(((year%4==0)&&(year%100!=0))||(year%400==0)){
        sum+=1;
      }
    }
    cout<<sum<<endl;
  }
}
int countnumber(int n){
  //一定要判断特殊情况5*5相等的两个数
  int count=0;
  if(n<0||(n>5000)){
    return -1;
  }else{
    for(int i=2;i<=n;++i){
      int sum=0;
      //遍历的范围
      for(int j=2;j<sqrt(i);++j){
        if(i%j==0){
          //遇到两个相等的数了
          if(i/j==j){
            sum+=j;
          }
          sum+=j+(i/j);
        }
      }
      if(sum+1==n){
        count++;
      }
    }
    return count;
  }
}
void test2(){
  //找到0-500000的所有完全数
  //计算完全数-->1+2+4+7+14=28-->约数相加和刚好为这个数
  //遍历每个约数求和判断是否是完全数
  //int n;
  //int i=1;
  //int sum=0;
  //while(cin>>n){
  //  if(n%i==0){
  //    sum+=i;
  //  }
  //  ++i;
  //  if(sum==n){
  //    cout<<n<<endl;
  //  }
  //}
  int number;
  while(cin>>number){
    cout<<countnumber(number)<<endl;
  }
}
int main(){
  test1();
  return 0;
}
