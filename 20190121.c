//通信录
//1管理很多联系人2每个人的信息姓名手机号3增删改查4和用户通过控制台进行交互
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define PERSON_INFO_MAX_SIZE 200
//如何将其变成动态数组
typedef struct AddressBook{

PersonInfo* infos;
//指针指向的动态空间的长度
int capcity;//容量当前infos指向的动态数组长度,(指的是元素的个数)
int size;
}AddressBook;
typedef struct PersonInfo{//PersonInfo这种类型的变量里面有char类型的name
  //和char类型的phone
  //通讯录每个人的信息
char name[1024];
char phone[1024];
}PersonInfo;
//typedef struct AddressBook{//管理多个联系人
//  PersonInfo infos[200];//personinfo是一种类型类似于int
//  int size;//描述数组中多少个元素已经使用有效空间为（0，size]
// //通讯录总人数 
//}AddressBook;
AddressBook g_address_book;//全局变量作为整个参数的实体
void Realloc(AddressBook* addr_book){

  //手动实现扩容
  assert(addr_book!=NULL);
addr_book->capcity*=2;
//每次扩容扩为原来的2倍,此处扩容多少位用户自定义
//扩容过程中需要把原来的没存释放掉然后才能申请,否则会内存泄漏
//扩大capcity的取值,申请更大内存,把原有的内存中的数据负复制到新内存
//然后释放原来内存
//addr_book->infos=(PersonInfo*)malloc(addr_book->capcity);
PersonInfo*old_infos=addr_book->infos;//用Oldinfos备份
addr_book->infos=(PersonInfo*)malloc(addr_book->capcity);
//申请更大的空间
//数据拷贝到新动态内存
int i=0;
for(;i<addr_book->size;++i){
addr_book->infos[i]=old_infos;
//释放原来内存
free(old_infos);
}
}
void Init(AddressBook*addr_book){
  //对address_book初始化不会影响到实参g_address_book,为了影响实参就得传指针
  //为*address_book;
  assert(addr_book!=NULL);//指针的合法性判断
  //但凡函数传参一定要对函数的有效性进行校验
  //尤其是参数为指针的情况,一点要合法性判断更加规范
 addr_book->size=0;//address_book是AddressBook结构体类型的指针
 //size为有效元素区间就是存入的通信录的人的个数
 addr_book->capcity=10;//初始化定动态数组多大
 addr_book->infos=(PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capcity);
 //按元素分配动态空间
}
void AddPersonInfo(AddressBook*addr_book){
  assert(addr_book!=NULL);
  if(addr_book->size>=addr_book->capcity)
    //当size大于addr_book,就需要扩容
   printf("当前通讯录已近满进行扩容") ;
  Realloc(addr_book);
 // if(addr_book->size>=PERSON_INFO_MAX_SIZE){
 // printf("通讯录已近满!\n");
  return ;
  }
  //每次都把这个新的联系人放到有效数组的最后一个元素上,
  //第一个下标为0第二个联系人下标为1,size就可以表示新插入联系人的下标
 PersonInfo *p=&addr_book->infos[addr_book->size];//把对应元素的指针取出来 
 //方便代码编写,此时size为要插入的人的下标
 printf("插入一个联系人!\n");
 printf("请输入新增联系人的姓名:");
// scanf("%s",p.name);此处不能取一个结构体变量只能取结构体指针,
// 如果取结构体变量这个P相当于数组中对应元素的拷贝这里创建了新的结构体
// PersonInfo *p也包含2K长度的内存后续的修改只是对PersonInfo临时变量结构体修改
// 而没有对addr_book->infos[addr_book->size]也就是数组中的指定元素造成影响
// 也就是如果取的结构体变量该变量相当于数组中对应元素的副本此时
// 修改结构体变量只是对其副本进行修改没有影响到原来的数组;类似于形参拷贝
 scanf("%s",p->name);
 //如果没有PersonInfo*p=&addr_book->infos[addr_book->size]
 //变成了scanf("%s",addr_book->infos[addr_book->size].name);
 //将指针取出来就可以直接对指针进行操作
 printf("请输入新增电话\n");
 scanf("%s",p->phone);
 //新增完成后需要更新size
 ++addr_book->size;
 printf("插入联系人成功\n");
}
void DelPersonInfo(AddressBook*addr_book){
assert(addr_book!=NULL);
//根据用户下标进行删除
//把最后一个元素的序号贴到要删除的元素的序号上然后size--
printf("删除联系人\n");
printf("请输入要删除人的序号:");
int id=0;
scanf("%d",&id);
if(id<0||id>=addr_book->size){
  printf("您输入的序号有错误删除失败\n");
 return;
}
PersonInfo* p=&addr_book->infos[id];
printf("您要删除的人为[%d] %s,确认请输入Y:",id,p->name);
char cmd[1024]={0};
scanf("%s",cmd);
if(strcmp(cmd,"Y")!=0){
  printf("删除操作已近取消!\n");
  return;
}
//把最后一个元素复制到指定删除的位置上
PersonInfo* from=&addr_book->infos[addr_book->size-1];
//size-1就是最后一个元素的下标
PersonInfo* to =p;
//结构体赋值
*to=*from;
//结构体之间是可以这样赋值的结构体不能用{}赋值,但是结构体可以用
//一个其他的结构体变量进行赋值意思是把from结构体里面所有的内容
//都依次拷贝到to结构体里没必要strcpy(name);直接*操作
--addr_book->size;
printf("删除成功!\n");
}
void modifyPersonInfo(AddressBook*addr_book){
assert(addr_book!=NULL);
printf("修改联系人!\n");
printf("请输入要修改的联系人的序号:");
int id=0;
scanf("%d",&id);
if(id<0||id>=addr_book->size){
  printf("输入的序号有错误!\n");
  return;
}
PersonInfo* p=&addr_book->infos[id];
printf("请输入要修改的姓名:");
//增加一个确认功能
char input[1024]={0};
scanf("%s",input);
if(strcmp(input,"#")!=0){
  //#用于跳过当前的选项
  strcpy(p->name,input);
}
//scanf("%s",p->name);
printf("请输入要修改的电话:");
//scanf("%s",p->phone);
//也加了判断
scanf("%s",input);
if(strcmp(input,"#")!=0){
  strcpy(p->phone,input);
}
printf("修改成功!\n");
}
void findPersonInfo(AddressBook*addr_book){
assert(addr_book!=NULL);
printf("开始进行查找!\n");
int i=0;
printf("请输入要查找的姓名:");
char name[1024]={0};
scanf("%s",name);
int count=0;
for(;i<addr_book->size;i++){
  PersonInfo* p =&addr_book->infos[i];
  if(strcmp(name,p->name)==0){
printf("[%d] %s\t%s\n",i,p->name,p->phone);
//   break;//查找到了但是不能用break,姓名有可能有重复的应该尽可能找到所有的 
++count;
  }
}

printf("查找完毕!共找到%d条记录\n",count);


}
void sortPersonInfo(AddressBook*addr_book){



}
void printallPersonInfo(AddressBook*addr_book){
assert(addr_book!=NULL);
printf("显示所有人\n");
int i ;
for(i=0;i<addr_book->size;i++){
  PersonInfo *p=&addr_book->infos[i];
  //此时为PersonInfo p=&addr_book->infos[i];此时只是打印不涉及修改
  //原数组中的元素,
  printf("[%d] %s\t%s\n",i,p->name,p->phone);
}
printf("总共显示了%d条数据\n",addr_book->size);
}
void clearnallPersonInfo(AddressBook*addr_book){
assert(addr_book!=NULL);
printf("清空所有记录!\n");
printf("请确定您要清空所有的记录吗?输入Y表示确认\n");
char cmd[1024]={0};
scanf("%s",cmd);
if(strcmp(cmd,"Y")!=0){
printf("清空操作已经取消!\n");
return;
}
addr_book->size=0;
printf("清空操作成功!\n");
}
int Menu(){
printf("-----------------------\n");
printf("1.新增-----------------\n");
printf("2.删除-----------------\n");
printf("3.修改-----------------\n");
printf("4.查找-----------------\n");
printf("5.排序-----------------\n");
printf("6.显示全部-------------\n");
printf("7.清空全部-------------\n");
printf("0.退出-----------------\n");
printf("-----------------------\n");
printf("请输入你的选择:");
int choice=0;
scanf("%d",&choice);
return choice;

}
int main(){
Init (&g_address_book);
typedef void (*pfunc_t)(AddressBook*);//定义函数指针数组里面
//每一个元素都是一个函数指针包涵各函数
  pfunc_t table[]={
AddPersonInfo,
DelPersonInfo,
modifyPersonInfo,
findPersonInfo,
sortPersonInfo,
printallPersonInfo,
clearnallPersonInfo
};
while(1){
  int choice=Menu();
if(choice==0){
printf("goodbye\n");
break;
}//用表驱动
if(choice<0||choice>(int)(sizeof(table)/sizeof(table[0]))){
  //强转成int去掉警告
printf("输入有误\n");
continue;
}
  table[choice-1](&g_address_book);//表驱动
  }
return 0;
}
// int choice=Menu();
// if(choice==0){
//   printf("goodbye\n");
//   break;
// }
// else if(choice<0||choice>7){
//   printf("输入有误\n");
//   continue;
// }
// else if(choice==1){
//   AddPersonInfo(&g_address_book);
// }
//else if(choice==2){
//  DelPersonInfo (&g_address_book);
//}
//else if(choice==3){
//  modifyPersonInfo(&g_address_book);
//}
//else if(choice==4){
//  findPersonInfo(&g_address_book);
//}
//else if(choice==5){
//  sortPersonInfo(&g_address_book);
//}
//else if(choice==6){
//  printallPersonInfo(&g_address_book);
//}
//else if(choice==7){
//  clearnallPersonInfo(&g_address_book);
//}
//}
//return 0;
//}
