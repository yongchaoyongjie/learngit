#include "seqlist.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
//初始化
void SeqlistInit(Seqlist*seqlist,int capacity){
  assert(seqlist!=NULL);
seqlist->array=(SLDateType*)malloc(sizeof(SLDateType)*capacity);
seqlist->capacity=capacity;
seqlist->size=0;
}
//销毁链表
void SeqlistDestroy(Seqlist*seqlist){
  //释放存储空间
  //把字段初始化为初值
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  free (seqlist->array);
  //锦上添花
  seqlist->array=0;
  seqlist->size=seqlist->capacity=0;
}
//链表的扩容
void CheckCapacity(Seqlist* seqlist){
  if (seqlist->size<seqlist->capacity){
    return ;
  }
//需要扩容的情况
//申请新内存
int newcapacity=seqlist->capacity;
SLDateType* newarray=(SLDateType*)malloc(sizeof(SLDateType)*newcapacity);
//copy老数据到新数据
int i;
for( i=0;i<=seqlist->size;i++){
  newarray[i]=seqlist->array[i];
}
//释放旧的空间把新空间绑定到顺序链表结构体
free(seqlist->array);
seqlist->array=newarray;
//更新容量
seqlist->capacity=newcapacity;
}
//头插法
void Seqlistpushfront(Seqlist*seqlist,SLDateType v){
//分两种情况
//1.按照空间下标插入头插法的坐标为[1,size]
CheckCapacity(seqlist);
int i;
for(i=seqlist->size;i>=1;i--){
seqlist->array[i-1]=seqlist->array[i];
#if 0
//2按照数据坐标插入头插法的坐标为[0,size-1]
for(int i=seqlist->size;i>=0;i++){
  seqlist->array[i]=seqlist->array[i+1];
}
#endif
seqlist->array[i]=v;
seqlist->size++;
}
}
//尾插法
void Seqlistpushback(Seqlist*seqlist,SLDateType v){
CheckCapacity(seqlist);
seqlist->array[seqlist->size]=v;
seqlist->size++;
}
//中间插入
void Seqlistinsert(Seqlist*seqlist,int pos,SLDateType v){
//两种方法依据数据下标和空间下标
//法1空间坐标法[pose,size]
CheckCapacity(seqlist);
int i;
for(i=seqlist->size;i>pos;i--){
  assert(pos>=0&&pos<=seqlist->size);
seqlist->array[i]=seqlist->array[i-1];
seqlist->array[i]=v;
seqlist->size++;
}
}
//头删除
void Seqlistpopfront(Seqlist*seqlist){
//头删除,两种方法根据数据下标和空间下标,切记空间在数据的前面
//所以数组下标在没有删除之前为0-size-1,删除后成了0-size-2
//所以空间坐标在没有删除之前是1-size头插法删除之后变成了1-size-1
//空间下标为[0,size-2]
//数据下标为[1,size-1]
assert(seqlist!=NULL);
assert(seqlist->size>0);
int i;
for(i=0;seqlist->size-2>=i;i++){
seqlist->array[i]=seqlist->array[i+1];
#if 0
int i;
for(i=1;seqlist->size-1>=i;i++){
  seqlist->array[i-1]=seqlist->array[i];
}
#endif
seqlist->size--;//删除尾部数的下标位置不变
}
}
//尾巴删除
void Seqlistpoback(Seqlist*seqlist){
assert(seqlist!=NULL);
assert(seqlist->size>0);
seqlist->size--;
}
//中间删除
void Seqlisterase(Seqlist*seqlist,int pos){
//中间删除告诉的为数组下标1:数据坐标[pos,size-2],
assert(seqlist!=NULL);
assert(seqlist->size>0);
assert(pos>=0&&pos<=seqlist->size-2);
int i;
for(i=pos;i<=seqlist->size-2;i++){
  seqlist->array[i]=seqlist->array[i+1];//下标为i+1变成了i坐标
  seqlist->size--;
}
}
//修改,将下标为pos的值修改为v
void Seqlistmodify(Seqlist*seqlist,int pos,SLDateType v){
seqlist->array[pos]=v;
}
//查找只找一个
//返回第一个v的下标,没有则返回-1
int Seqlistfind(Seqlist*seqlist,SLDateType v){
  int i;
  for(i=0;i<=seqlist->size-1;i++){
   if(seqlist->array[i]==v){
     return i;
  }
  }
return -1;
}
//找到值并移除,第一个
void Seqlistremove(Seqlist*seqlist,SLDateType v){
assert(seqlist!=NULL);
assert(seqlist->size>0);
int pos=Seqlistfind(seqlist,v);
if(pos==-1){
return ;//没有找到
}
  Seqlisterase(seqlist,pos);
}
//查找remove相同的全部
void Seqlistremoveall(Seqlist*seqlist,SLDateType v){
  //思路,让i遍历,然后j也 移动,j找到第一个停止,然后i继续移动
int i,j;
for(i=0,j=0;i<seqlist->size;i++){
  if(seqlist->array[i]!=v){
    seqlist->array[j]=seqlist->array[i];
    j++;
  }
}
seqlist->size=j;
}
static int Seqlistprint(const Seqlist* seqlist){
  int i;
  for(i=0;i<=seqlist->size-1;i++){
    printf("%d",seqlist->array[i]);
  }
printf("\n");
}
