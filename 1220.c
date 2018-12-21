#include <stdio.h>
#include <string.h>
#include <math.h>
//int main(){
//
//void sort(char *[]);
//int i;
//char*p[4],str[4][10];
//for(i=0;i<4;i++){
//  p[i]=str[i];
//}
//printf("请输入字符串\n");
//for(i=0;i<4;i++){
//  scanf("%s\n",p[i]);
//
//}
//sort(p);
//for(i=0;i<4;i++){
//  printf("%s\n",p[i]);
//}
//  return 0;
//}
//void sort(char *s[])
//{
//  int i,j;
//  char *temp;
//  for(i=0;i<3;i++){
//for(j=0;j<3-i;j++){
//  if(strcmp(*(s+j),*(s+j+1))>0)
//  {
//    temp=*(s+j);
//    *(s+j)=*(s+j+1);
//    *(s+j+1)=temp;
//  }
//
//  }
//}
//}
//////int main(){
////用矩阵法求定积分的通用函数
//  float jifen(float (*)(float),float,float,int);
//    float fsin(float);
//    float fcos(float);//对三角函数的声明
//  float fexp(float);//对e的x次方函数声明
//float a1,b1,a2,b2,a3,b3,c,(*p)(float);
//int n=20;
//printf("请输入a1,b1\n");
//scanf("%f,%f",&a1,&b1);
//printf("请输入a2,b2\n");
//scanf("%f,%f",&a2,&b2);
//printf("请输入a3,b3\n");
//scanf("%f,%f",&a3,&b3);
//p=fsin;
//c=jifen(p,a1,b1,n);
//printf("sinx的积分为%f\n",c);
//p=fcos;
//c=jifen(p,a2,b2,n);
//printf("cosx的积分为%f\n",c);
//p=fexp;
//c=jifen(p,a3,b3,n);
//printf("exp(x)的积分为%f\n",c);
//
//  return 0;
//}
//
//float jifen(float(*p)(float),float a,float b,int n){
//  int i;
//  float x,h,s;
//  h=(b-a)/n;
//  x=a;
//  s=0;
//  for(i=1;i<=n;i++){
//    x=x+h;
//    s=s+(*p)(x)*h;
//
//  }
//return s;
//}
//float fsin(float x){
//float y;
//y=sin(x);
//  return y;
//}
//float fcos (float x){
//float y;
//y=cos(x);
//return y;
//}
//float fexp(float x){
//  float y;
//y=exp(x);
//  return y; 
//}
int main()
{//n个数 按照输入时顺序的逆序排列
  void sort(int *p,int m);
  int i,n;
  int *p,num[20];
  printf("请输入n\n");
  scanf("%d",&n);
  printf("请输入这些数字\n");
  for(i=0;i<n;i++){
  scanf("%d",&num[i]);
  }
p=&num[0];
sort(p,n);
for(i=0;i<n;i++){
  printf("%d",num[i]);
}
printf("\n");
  return 0;
}
void sort(int*p,int m){
int i;
int temp,*p1,*p2;
for(i=0;i<(m/2);i++){
  p1=p+i;
p2=p+(m-1-i);
temp=*p1;
*p1=*p2;
*p2=temp;
}
}
