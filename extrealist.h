#pragma once 
#include <stdlib.h>
typedef int SListDataType;
typedef  struct Node{
  struct Node *next;
  SListDataType value;
}Node;

typedef struct SList{
  Node*first;
}SList;
//让一个链表进行翻转输入1--2--3--4--null变成输出4--3--2--1--null
//头插
struct ListNode{
  int val;
  struct ListNode*next;
};
struct ListNode*reverselist(struct ListNode*head){
struct ListNode*result=NULL;
struct ListNode*c=head;
//思路让原来这个链表的第一个结点的下一个结点变成新链表的第一个结点
//4--null变成新链表的第一个结点就是Null变成新链表的第一个结点所以用头插
//更新新链表的第一个结点 
//头插
//c刚开始0xcc(1,0xff)0xff(2,0xdd)0xdd(3,null)c=0xcc,next=0xff,c->next=result 
//oxcc(1,null),result=c,所以result=0xcc;result 刚开始为null
while(c!=NULL){
struct ListNode*next=c->next;//保存这个点的位置
c->next=result;//头插s->first=node;s->first=node->next尾插c=c->next,c->next=Node
result=c;
c=next;
}
return result;
}
struct ListNode*removeElements(struct ListNode*head,int v){
//特殊情况链表为空
  if(head==NULL){
    return head;
 }
struct ListNode *c=head;
while(c->next!=NULL){
  if(c->next->val==v){
    struct ListNode*next=c->next->next;
free(c->next);
c->next=next;
  }else{
    //值不等
    c=c->next;
  }
}
}
//void ListNode*removeElement
//合并两个链表
ListNode*mergetwolist(struct ListNode*l1,struct ListNode*l2){
//判断特殊情况
//1链表1为 空
  if(l1==NULL){
    return l2;
  }
  if(l2==NULL){
    return l2;
  }
struct ListNode *c1=l1;//c1,c2为遍历l1和l2的指针
struct ListNode *c2=l2;
struct ListNode*result=NULL;//结果链表上的指针
struct ListNode*last=NULL;//剩余链表上的指针
if(l1==NULL){//last为空
  return l2;
}
if(l2==NULL){//last为空特殊情况,两个都为空return为null不需要考虑
  return l1;
  }
while(c1!=NULL&&c2!=NULL){
  if(c1->val<=c2->val){//c1尾插到结果链表上去
    //循环走完c1和c2有一个为空,两个链表有一个链表的结点被取完了
    //所以有两个链表一个结果链表一个剩余链表,结果链表和剩余链表都有序
    //而且剩余链表的最后一个比结果链表的最后一个都大直接接起来就可以有序了
    if(result==NULL){//
      result=last=c1;
    }else{//如果是空链表的情况及原来一个节点都没有
      //last为空
     last->next=c1;//尾插//c1接到最后一个链表后面就可以了
     last=c1;//更新一下
    }
    c1=c1->next;//继续往后走
  }
  else{
    if(result==NULL){//l2>l1
result=last=c2;
    }else{
      last->next=c2;
      last=c2;
    }
    c2=c2->next;
  }
}
if(c1!=NULL){//c1不为空剩余c1把c1链表接到结果链表了,就是剩余链表为c1
  last->next=c1;
}
if(c2!=NULL){//c2不为空c1为空剩余链表为c2
  last->next=c2;
}
return result;
}
//头插
//head 是第一个结点把node结点头插到head链表上
void pushfront(Node*head,Node*node){
node->next=head;
head=node;
}
//头删 不考虑链表为空
void popfront(Node*head){
//头删要找到第二个结点
Node*second=head->next;
free(head);
head=second;

}
//尾巴插
//找到链表的最后一个节点
static Node*findlastnode(Node*head){
//怎么找到最后一个节点必须要用指针
Node*cur=head;
while(cur->next!=NULL){
cur=cur->next;
}
return cur;
}
void pushback(Node*head,Node*node){
//1链表中没有结点和链表中只由一个节点
node->next=NULL;
if(head==NULL){
head=node;
}
else{
//找到最后一个节点
Node*last=findlastnode(head);
last->next=node;
}
}
//尾巴删除
//找到倒数第二个结点
static Node* findlastsecond(Node*head){
Node*cur=head;
while(cur->next->next!=NULL){
cur=cur->next;
}
return cur;
}
//尾删不考虑为空的情况
void popback(Node*head){
//两种情况1只有一个结点2一个节点以上
  if(head->next==NULL){
    //一个结点
    free(head);
    head=NULL;
  }
  else{
//一个节点 以上
Node*lastsecond=findlastnode(head);
free(lastsecond->next);
lastsecond->next=NULL;//倒数第二个结点->next为空在删除掉倒数第一个结点以后
  }
}
Node*removeall(Node*head,int v){
Node*first=NULL;//结果链表的第一个结点
Node*last=NULL;//结果链表的最后一个结点
Node*cur=head;
while(cur!=NULL){
//遍历整个链表如果这个值没有则尾插到末尾
  if(cur->value!=NULL){
    if(head==NULL){
      first=last=cur;
    }
    else{
      last->next=cur;
      cur=last;
    }
  }
  cur=cur->next;
}
}
Node*removeall1(Node*head,int v){
  Node*node=head;
  Node*result=NULL;
  Node*last=NULL;//结果链表的最后一个节点
  while(node!=NULL){
    Node*nextl=node->next;
    if(node->value!=v){
      node->next=NULL;
      if(last==NULL){
result=node;
last=node;
      }else{
last->next=node;//更新最后一个结点
last=node;
      }
    }
node=nextl;
  }
  return result;
}
Node*revers(Node*head){
  Node*result=NULL;
  Node*node=head;
  while(node!=NULL){
Node*nextl=node->next;
node->next=result;//头插法
result=node;
node=nextl;
  }
 return result; 
}
//将两个链表合并成一个新的有序链表并返回,新链表是通过拼接给定的两个链表的
//所有节点组成的
//比如输入1-2-4,,,1-3-4
//输出1-1-2-3-4-4
//左边遍历左边的链表右边遍历右边的链表,结果链表谁小谁有资格进结果链表
//走到结果链表是尾插
//struct ListNode*mergetwolist(struct ListNode*l1,struct ListNode *l2){
////同时遍历两个链表并比较
//struct ListNode *c1=l1;
//struct ListNode *c2=l2;
//while(c1!=NULL&&c2!=NULL){
//}}
//编写代码,以给定值为x为基准将链表分割为两部分,所有小于x的结点排在大于或等于
//x的结点之前以5为例子
//3-5-2-9-7-4-1
//3-2-4-1-5-9-7
ListNode*partition(ListNode* phead,int x){
  //一个小于x的结果链表
  //一个大于等于x的结果链表
  //循环变量整个链表的所有节点
  //根据和x关系.尾插到不同的链表中把两个 链表连接起来
  ListNode*big=NULL;
  ListNode*small=NULL;
  ListNode*smalllast=NULL;//小于x的结果链表
  ListNode *biglast=NULL;//大于x的结链表
  ListNode*node=phead;//用node来遍历
  while(node!=NULL){
node=node->next;
if(node->val<x){
  if(small==NULL){
    small=smalllast=node;
  }else{
    smalllast->next=node;
    smalllast=node;
  }
}else{
  if(big==NULL){
    big=biglast=node;
  }else{
    biglast->next=node;
    biglast=node;
  }
}
node=node->next;
  }
if(smalllast!=NULL){
  smalllast->next=big;//将两个表连接起来
}
if(biglast!=NULL){
  biglast->next=NULL;//
  
}
if(smalllast!=NULL){
  return small;//比它小的都不存在
}else{
  return big;
}
//1-4-2-3-null,5-9-7-的next期待为空原来指的是3
}
//找到倒数第k个结点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
//前后指针的问题
//定义两个指针让前面的先走k步然后后面那个指针开始走
ListNode*front=pListHead;
ListNode*back=pListHead;
int i;
for(i=0;i<k&&front!=NULL;i++){
  front=front->next;
}
if(i<k){
  return NULL;
}
while(front!=NULL){
  front=front->next;
  back=back->next;
}
return back;
}

