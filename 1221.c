#include <stdio.h>
//int main(){
////四个学生五门课程1.求第一门平均分2.找出两门课程不及格输出学号和全部成绩
////和平均成绩,找出90分以上或者平均分大于85
//  void avsco(float*,float*);//每个人的平均成绩
//  void avsco1(char(*)[10],float*);//第一门课 的平均成绩
//  void fail2(char course[5][10],int num[],float *pscore,float aver[4]);
//  //两门以上不及格的学生
//  void good(char course[5][10],int num[4],float *pscore,float aver[4]);
//float score[4][5],aver[4],*pscore,*paver;
//char course[5][10],(*pcourse)[10];
//int i,j,*pnum,num[4];
//printf("请输入课程\n");
//pcourse=course;
//for(i=0;i<5;i++){
//  scanf("%s",course[i]);
//}
//printf("输入第几门和分数\n");
//printf("第几门");
//for(i=0;i<5;i++){
//  printf("%s",course[i]);
//}
//printf("\n");
////输入分数
//pscore=&score[0][0];
//pnum=&num[0];
//for(i=0;i<4;i++){
//  //输入学号
//  scanf("%d",pnum+i);
//for(j=0;j<5;j++){
//  scanf("%f",pscore+5*i+j);
//  //输入分数
//}
//}
//paver=&aver[0];
//printf("\n\n");
//avsco(pscore,paver);
////每个学生的平均成绩
//avsco1(pcourse,pscore);
//printf("\n\n");
//fail2(pcourse,pnum,pscore,paver);
//printf("\n\n");
//good(pcourse,pnum,pscore,paver);
//  return 0;
//}
//void avsco(float*pscore,float *paver){
//  int i,j;
//  float sum,average;
//  for(i=0;i<4;i++){
//    sum=0.0;
//    for(j=0;j<5;j++){
//      sum=sum+(*(pscore+5*i+j));
//    }
//    average=sum/5;//计算一个人的平均成绩
//*(paver+i)=average;
//  }
//}
//void avsco1(char(*pscoure)[10],float*pscore){
//  //第一门课的平均成绩
//  int i;
//  float sum,average1;
//  sum=0.0;
//  for(i=0;i<4;i++){
//    sum=sum+*(pscore+5*i);
//  }
//  average1=sum/4;
//  printf("第一门课的名字为%s平均成绩为%7.2f\n",*pscoure,average1);
//}
//void fail2(char course[5][10],int num[],float *pscore,float aver[4]){
//int i,j,k,labe1;
//printf("两门课不及格的学生是:\n");
//printf("不及格的成绩为第几门\n");
//for(i=0;i<5;i++){
//  printf("%11s",course[i]);
//}
//printf("average\n");
//for(i=0;i<4;i++){
//  labe1=0;
//  for(j=0;j<5;j++){
//    if(*(pscore+5*i+j)<60.0){
//      labe1++;
//    }
//  }
//  if(labe1>=2){
//    printf("%d",num[i]);
//    for(k=0;k<5;k++){
//      printf("%11.2f",*(pscore+5*i+k));
//    }
//    printf("%11.2f\n",aver[i]);
//  }
//}
//}
//void good(char course[5][10],int num[4],float *pscore,float aver[4]){
//int i,j,k,n;
//printf("谁的成绩很优秀\n");
//printf("第几门\n");
//for(i=0;i<5;i++){
// printf("%11s",course[i]);
//}
// printf("average\n");
// for(i=0;i<4;i++){
//  n=0;
//  for(j=0;j<5;j++){
//    if(*(pscore+5*i+j)>85.0){
//      n++;
//    }
//  }
//  if((n==5)||aver[i]>=90){
//    printf("%d",num[i]); 
//  }
//  for(k=0;k<5;k++){
//    printf("%11.2f",*(pscore+5*i+k));
//  }
//printf("%11.2f\n",aver[i]);
//}
//}
void mygets(char *str){
  int i=0;
  scanf("%c",&str[i]);
  while(str[i++]!='\n'){
    scanf("%c",&str[i]);
  }
}
int main(){
//输入一个字符串 有数字和非数字比如A123x456 17960? 302tab5876 
//将其中连续的数字依次放到数组a统计有多少个整数并输出这些整数
char str[50],*pstr;
int i,j,k,m,e10,digit,ndigit,a[10],*pa;
printf("请输入字符串\n");
mygets(str);
pstr=str;//字符指针置于数组指针首地址
pa=a;//指针pa置于a的首地址
ndigit=0;//有多少个数字
i=0;//代表字符串第几个字符
j=0;
while(*(pstr)!='\0'){
  if(((*pstr+i)>='0')&&(*(pstr+i)<'9')){
    j++;
  }
  else{
    {
      if(j>0){
digit=*(pstr+i-1)-48;//将个数赋给digtit,字符数字转换为数字要减去48
k=1;
while(k<j){//将含有两位以上的其他位的数值累计于digit
e10=1;
for(m=1;m<=k;m++){
  e10=e10*10;//e10代表该位数所应该乘的因子
}
  digit=digit+(*(pstr+i-1-k)-48)*e10;
  k++;
}
*pa=digit;//数值赋予数组a
ndigit++;
pa++;
j=0;
      }
    }
i++;  
}
}
if(j>0){
  digit=*(pstr+i-1)-48;
  k=1;
  for(m=1;m<=k;m++){
    e10=e10*10;
    digit=digit+(*(pstr+i-1-k)-48)*e10;
    k++;
  }
  *pa=digit;
  ndigit++;
  j=0;
}
printf("这里有%d个数在这段话中,他们是:\n",digit);
j=0;
pa=a;
for(j=0;j<ndigit;j++){
  printf("%d",*(pa+j));
}
printf("\n");
return 0;
}
