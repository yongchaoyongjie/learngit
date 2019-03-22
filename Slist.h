#pragma once
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;//定义int 为SListDataType
typedef struct Node{//定义一个结构体---结点
struct Node *next;//下一个结点的地址Node*,定义指向单链表中结点的指针
SListDataType value;//值
}Node;
typedef struct SList{//定义一个单链表
Node*first;//第一个结点的地址
}SList;
//初始化/销毁
void SListInit(SList*slist){
slist->first=NULL;
}
//头插,始终保证下一个结点指向头结点
void SListpushfront(SList*slist,SListDataType v){
//1申请新的结点
Node*node=(Node*)malloc(sizeof(Node));
node->value=v;
//更改链表关系
slist->first=node->next;//新结点的下一个地址指向头结点
slist->first=node;//新结点变成第一个结点
}
//头删除
void SListpopfront(SList*slist){
//判断保证链表不为空情况
assert(slist->first!=NULL);
//然后将原来第二个结点的地址变成第一个结点的地址
//第二个结点变成第一个结点
Node* second=slist->first->next;
slist->first=second;
}
//尾插
void SListpushback(SList*slist,SListDataType v){
Node*node=(Node*)malloc(sizeof(Node));
node->value=v;
node->next=NULL;//始终保证结点的下一个地址为空
//保存s->first地址
if(slist->first==NULL){//空列表做尾插
slist->first=node;//
}
else{
Node*c=slist->first;
//结点指针遍历
while(c->next!=NULL){
c=c->next;
//表示修改指针c的位置把c指向原来结点的下一个结点
//c->next=c;表示c的下一个结点还是p如果链表只有c一个节点则表示为
//循环链表
}
//循环结束c->next一定为null,也就是c是最后一个结点
c->next=node;
}
}
void SListpopback(SList*slist){
  assert(slist->first!=NULL);//链表不为空
  if(slist->first->next==NULL){
    //链表只有一个节点
free(slist->first);
slist->first=NULL;
return ;
}
//如果链表有很多数找到倒数第二个结点
Node*lastsecond;
//while(lastsecond->next->next!=NULL){
//lastsecond=slist->first;
//lastsecond=lastsecond->next;
//}
for(lastsecond=slist->first;lastsecond->next->next!=NULL;
    lastsecond=lastsecond->next);
free(lastsecond->next);
lastsecond->next=NULL;
}
Node* findSlist(SList*slist,SListDataType v){
  for(Node*c=slist->first;c->next->next!=NULL;c=c->next){
    if(c->value==v){
      return c;
    }
  }
  return NULL;
}
void removeSlist(SList*slist,SListDataType v){
//特殊情况
//1链表为空
  if(slist->first==NULL){
    return ;
}
//2要移除的数字刚好为第一个结点上 
//记录原来第二个结点释放第一个结点,原来第二个结点升级为第一个结点
if(slist->first->value==v){
Node*second=slist->first->next;
free(slist->first);
slist->first=second;
}
else{
//正常情况,让一个指针遍历即可
Node* c=slist->first;
while(c->next!=NULL){
  if(c->next->value==v){
Node*next=c->next;//是记下要删除的值的位置然后c->next->next
c->next=c->next->next;
free(c->next);
return ;
  }
  c=c->next;
}
}
}
void removeallslist(SList*slist,SListDataType v){
//特殊情况判断链表为空
  if(slist->first==NULL){
    return ;
  }
//正常情况但是除去第一个数是否相同的状况没有判断
//申请一个结点指针从开始遍历找到则删除
Node*c=slist->first;
while(c->next!=NULL){
  if(c->next->value==v){
    Node*next=c->next;
    c->next=c->next->next;
    free(c->next);
  }else{
c=c->next;
  }
}
//单独排查第一个为要删除的值的情况
if(slist->first->value==v){
Node*first=slist->first;
slist->first=slist->first->next;
free(slist->first);
}
}
