#pragma once 
#include <stdlib.h>
typedef struct RNode{
  int value;
  struct RNode*random;
  struct RNode*next;
}RNode;
//将一个链表复制一份包括其中关系
//分开三步走1只复制结点中的next和value,让新结点更在老结点后面
//2在处理random的复制
//3把链表拆分成两个
RNode*copy(RNode*head){
  RNode*oldnode=head;
  while(oldnode!=NULL){//两个链表连接一起
    RNode*newnode=(RNode*)malloc(sizeof(RNode));
 newnode->value=oldnode->value;  
 RNode*oldnext=oldnode->next;//保存就是old的next
newnode->next=oldnext;
oldnode->next=newnode;//然后现在的old的next变成了新的Node
//newnode=oldnode->next;//是newnode->next所以不对
oldnode=oldnext;
  }
  //处理random复制
  oldnode=head;
  while(oldnode!=NULL){
    RNode*newnode=oldnode->next;
if(oldnode->random==NULL){
  newnode->random=NULL;
}else{
  newnode->random=oldnode->next->random;//这样就确定将开始radom结果的映射关系
//映射到新的链表
}
oldnode=newnode->next;
  }
//第三部把链表拆开
oldnode=head;
RNode*newhead=head->next;
while(oldnode!=NULL){
  RNode*newnode=oldnode->next;
  oldnode->next=newnode->next;
  if(newnode->next!=NULL){
    newnode->next=newnode->next->next;
  }
  oldnode=oldnode->next;//old走到下一个,循环继续
}
return newhead;
}
//双向链表以及循环链表
typedef struct Node{
  int val;
  Node*next;
  Node*prev;
}Node;
void DlistInit(Node**p){
  Node*node=(Node*)malloc(sizeof(Node));
  node->next=node;
  node->prev=node;
  *p=node;
}
void Dlistpushfront(Node*head,Node*node){
  //头插
  //单链表头插是将头给覆盖了但是双向链表的头插是在头和第一个结点之间插入
  node->next=head->next;
  node->prev=head;
  head->next->prev=node;
  head->next=node;
}
void Dlistpushback(Node*head,Node*node){
node->next=head;
node->prev=head->prev;
head->prev->next=node;
head->prev=node;
}
void Dlistinsertafter(Node*node,Node* pos){
 node->next=pos->next;//将头插的head变成pos就好了
 node->prev=pos;
 pos->next->prev=node;
pos->next=node;
}
void Dlistinserbefore(Node*node,Node*pos){
node->next=pos;
node->prev=pos->next;
pos->prev->next=node;
pos->prev=node;
}

void test(){
  Node*head;
  DlistInit(&head);
}
