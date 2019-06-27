#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getluckypacket(int x[],int n,int pos,int sum,int mul){
//x[]袋子中所有球的个数,n球的总数pos当前搜索的位置,sum当前的和
//mul当前的积
int count=0;
  for(int i=pos;i<n;++i){
sum+=x[i];
mul*=x[i];
if(sum>mul){
//找到符合的要求+1继续累加后面的值看是否符合集合
count=getluckypacket(x,n,i+1,sum,mul);

}
//如果不符合要求而且当前值为1继续向后+1
else if(x[i]==1){
count=getluckypacket(x,n,i+1,sum,mul);
}
else{
  //若sum>Mul后面没有符合要求的组合了
  break;
}
//搜索下一个位置的时候回复sum和mul
sum-=x[i];
mul/=x[i];
//数字相同的组合只能算一个集合直接跳过
while(i<n-1&&x[i]==x[i+1]){
  i++;
}
  }
return count;
}
void test(){
  //如果一个袋子是幸运的当
  //且仅当所有球的号码的和大于所有球的号码的积。输入描述：
//第一行输入一个正整数n(n ≤ 1000j第二行为n个数正整数xi(xi ≤ 1000)
//输出描述：输出可以产生的幸运的袋子数
int n;
//while(cin>>n){
  int x[n];
  //但是是个动长数组
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  sort(x,x+3);
  //从第一个位置开始搜索
  cout<<getluckypacket(x,n,0,0,1)<<endl;
}
//}
//随意取出的手套至少可以形成一组组合的最少手套数量。
//开两个数组,两个数组对应位置表示同一种颜色的左右手套数量。
//对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类 n =sum(a1...an) -a1 +1（也就是总数减去最小值之后
//加一） 所以对于左右手手套颜色都有数量的序列，想要覆盖每一种颜色，则最小数量
//leftsum = 左边数量和 - 左边最小值 + 1， rightsum =右边数量和 - 右边的最小值 
//+ 1。而对于有0存在的，则需要做累加，保证覆盖每一种颜
class shoutao{
  int findminshoutao(int n,vector<int>left,vector<int>right){
int left_sum=0,left_min=INT_MAX;
int right_sum=0,right_min=INT_MAX;
int sum=0;
//遍历每一种颜色的左右手手套序列
for(int i=0;i<n;++i){
  //对于有0存在的手套累加
  if(left[i]*right[i]==0){
    sum+=left[i]+right[i];
  }else{
    //对于左右手都有颜色的手套执行累加0最小值+1
  //找到最小值的总和
  left_sum+=left[i];
  right_sum+=right[i];
  left_min=min(left_min,left[i]);
  right_min=min(right_min,right[i]);

  }

}
//结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保
//证了
return sum+min(left_sum-left_min+1,right_sum-right_min+1);
  }
};
//变形杨辉三角以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好
//是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数
//就是0,求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出
//2，输入4则输出3
//可以发现第n行有2n -1个元素，第i,j元素等于上一行第j -2,j -1,j三列元素之和，
//每一行的第一列和最后一列都为1，如果是第二列，则只是两个元素之和。
void test1(){
   int n,m;//n为行数,m为该行的元素个数
   while(cin>>n){
m=2*n-1;
//vector<vector<int>>dp是一个二维数组,dp(n,vector<int>(m,0))第n行存的元素个数
//为m个而且都初始化为0
vector<vector<int>> vv(n,vector<int>(m,0));
vv[0][0]=1;
for(int i=1;i<n;++i){
 //第一列和最后一列为1
 vv[i][0]=vv[i][2*i];//此处不能为vv[i][n-1],n-1是最后一行,如果是第二行则它的
 //列得不到n-1列,只能达到2*i列
 for(int j=1;j<2*i;++j){
   if(j==1){
     vv[i][j]=vv[i-1][j-1]+vv[i-1][j];
   }
   else{
     vv[i][j]=vv[i-1][j-1]+vv[i-1][j]+vv[i-1][j-2];
   }
 }
}
int k;
for(int k=0;k<m;++k){
  if(vv[n-1][k]%2==0&&vv[n-1][k]!=0){
    cout<<k+1<<endl;
    break;
  }
}
if(k==m){
 cout<<-1<<endl;;//么有找到
}
   }
}
//超长正整数相加
//加法运算，每一位的值等于当前对应位的两数之和+进位。由于是加法，所以当前位
//的和最多是19（9 + 9 + 进位1)，所以产生的进位最多为1。故第一步：计算对应位
//的和，对应位相加 + 上一位的进位第二步：更新当前位的值， 和 % 10 ，把值转成
//字符（和 - '0'）存入字符结果中第三步：更新进位， 和 / 10， 然后计算下一位
//的值最后一步：如果计算完之后，进位为1，说明最高位产生了进位，所以需要再加
//一位，才是最后的结果。结果产生之后，需要逆置，得到最终结果。
string addstrings(string str1,string str2){
int i=str1.size();
int j=str1.size();
string result="";//进位后的结果
int dangqian=0;
while(i>0||j>0){
  if(i>=0){
dangqian=str1[i]-'0';
  }
  if(j>=0){
dangqian=str1[j]-'0';
  }
  
 //当前为的最大值不大于10
result+=(char)(dangqian%10+'0');
//如果大于10,向上进一位
dangqian/=10;
i--;
j--;
}
///相加完之后，如果还有进位，则再加1
if(dangqian==1){
  result+='1';
}
reverse(result.begin(),result.end());
return result;
}
void test2(){
  string s1,s2;
  while(cin>>s1>>s2){
    cout<<addstrings(s1,s2)<<endl;
  }
}
int main(){
test();
test1();
test2();
return 0;
}
