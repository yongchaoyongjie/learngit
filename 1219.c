////#include <stdio.h>
//int checkduankou(){
//int i;
//i=1;
//return (*(char*)&i);
//}
//int main(){
//  //c语言的大端小端的判断
//  //大端是数据的低位保存在高地址而高位保存在低地址
//  //小端是数据的低位保存在低地址高位保存在高地址
//  int ret=checkduankou();
//  if(ret==1){
//  printf("这是小端\n");
//
//}
//else{
//  printf("这是大端\n");
//}
//  return 0;
//}
#include <stdio.h>
//int main() {
//  char a=-1;
//signed b=-1;
//unsigned c=-1;
//printf("%d%d%d\n",a,b,c);
//return 0;
//}
//void print_arr(int arr[3][5],int row,int col){
//  int i,j;
//  for(i=0;i<row;i++){
//    for(j=0;j<col;j++){
//      printf("%3d",arr[i][j]);
//    }
// printf("\n");
//  }
//}
//void print_arr2(int (*arr)[5],int row,int col){
//  //数组名arr表示首地址但是二维数组的首元素是二维数组的第一行
//  //所以这里的arr其实相当于二维数组第一行的地址
//int i,j;  
//for(i=0;i<row;i++){
//    for(j=0;j<col;j++){
//      printf("%3d",arr[i][j]);
//    }
// printf("\n");
//  }
//}
//int main(){
//int arr[3][5]={1,2,3,4,5,6,7,8,9,10};
//print_arr (arr,3,5);
//print_arr2(arr,3,5);
//int add(int a,int b){
//  return a+b;
//}
//int jian(int a,int b){
//  return a-b;
//}
//int multiply(int a,int b){
//  return a*b;
//}
//int div(int a,int b){
//  return a/b;
//}
//int main(){
// //使用函数指针数组实现计算器
//int x,y;
//int ret=0;
//int input=1;
//int (*p[5])(int x,int y)={0,add,jian,multiply,div};
//while(input){
//  printf("*********************************************\n");
//  printf("1.add**********************************2.jian\n");
//  printf("3.multiply******************************4.div\n");
//  printf("请输入选择\n");
//  scanf("%d",&input);
//  if(input>=1&&input<=4){
//    printf("请输入x,y\n");
//    scanf("%d,%d",&x,&y);
//    ret=(*p[input])(x,y);
//  }
//  else{
//    printf("输入有错误请重新输入\n");
//  }
//    printf("ret=%d\n",ret);
//}
//
//  return 0;
//}
//void test(const char*str){
//  printf("%s",str);
//}
//int main(){
//  //*pfun为函数指针,然后指向test
//void(*pfun)(const char*)=test;
////函数指针的数组pfunarr,为什么为[5],因为只指向了一个函数,其他没有只所以默认为0
//void(*pfunarr[5])(const char*str);//让其指向函数test
//pfunarr[0]=test;
////不能这样吗?void(*(*ppfunarr)[10])(const *char)=&pfunarr;

//  return 0;
//}
int int_cmp(const void *p1,const void *p2){
  return (*(int*)p1>*(int*)p2);
}
void _swap(void *p1,void*p2,int size){
  int i=0;
  for(i=0;i<size;i++){
    char temp=*((char *)p1+i);
  *((char*)p1+i)=*((char*)p2+i);
  *((char*)p2+i)=temp;
  }
}
void bubble(void *base,int count, int size,int(*cmp)(const void*,const void*))
{
  int i,j;
  for(i=0;i<count-1;i++){
    for(j=0;j<count-1-i;j++){
      if(cmp((char*)base+j*size,(char*)base+(j+1)*size)>0){
        //cmp和int_cmp????
        _swap((char*)base+j*size,(char*)base+(j+1)*size,size);
      
      }
    }
  }
}
int main(){
int arr[]={1,3,5,7,9,2,4,6,8,0};
int i=0;
 bubble(arr,sizeof(arr)/sizeof(arr[0]),sizeof(int),int_cmp);
for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
  printf("%d\n",arr[i]);
}

printf("\n");
  return 0;
}
