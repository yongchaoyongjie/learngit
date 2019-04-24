#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
struct Node*next;
int value;
}Node;
//定义单链表
typedef struct Slist{
  Node*first;
}Slist;
//链表的初始化
void Slistinit(Slist*slist){
slist->first=NULL;
}
//只要插入必定申请空间新结点
//头插,保证下一个节点指向头结点
void Slistpushfront(Slist*slist,int v){
  //特殊情况处理链表为空
 assert(slist->first!=NULL) ;
//三大步:1申请新结点2更改链表关系3地址指向头
Node*node=(Node*)malloc(sizeof(Node));
node->value=v;
node->next=slist->first;
slist->first=node;
}
void Slistpopfront(Slist*slist){
  //第二个结点变成头结点
  assert(slist->first!=NULL);
  //特殊情况处理
  Node*node=slist->first->next;
  slist->first=node;
}
void Slistpushback(Slist*slist,int v){
//尾插申请新结点使新结点变成尾结点指向空
Node*node=(Node*)malloc(sizeof(Node));
node->value=v;
//特殊情况处理
//没有结点的情况
if(slist->first==NULL){
  slist->first=node;
}
else{
Node*c=slist->first;
while(c->next!=NULL){
  //尾插
  c=c->next;//c的下一个结点
}
 c->next=node; 
}
}
void Slistpopback(Slist*slist){
//尾删除
assert(slist->first!=NULL);
if(slist->first->next==NULL){
  //链表只有一个节点
  free(slist->first);
  slist->first=NULL;
}
  Node*node=slist->first;
  while(node->next->next!=NULL){
    node=node->next;
  }
  free(node->next);
  node->next=NULL;
}
Node*findslist(Slist*slist,int v){
  Node*c=slist->first;
  while(c->next->next!=NULL){
    c=c->next;
    if(c->value==v){
      return c;
    }
  }
  return NULL;
}
void slistinsertafter(Slist*slist,Node*pose,int v){
  Node*node=(Node*)malloc(sizeof(Node));
  node->value=v;
  //头插
node->next=pose->next;
pose->next=node;
}
void slisteraseafter(Slist*slist,Node*pos){
Node*c=pos->next->next;
free(pos->next);
pos->next=c;
}
void removeslist(Slist*slist,int v){
  //链表为空
  if(slist->first==NULL){
    return;
  }
  //链表的第一个结点为要移除的值
  if(slist->first->value==v){
    Node*second=slist->first->next;
    free(slist->first);
  slist->first=second;
  }
  else{
    //正常情况
    Node*c=slist->first;
    while(c->next!=NULL){
      if(c->next->value==v){
//要删除的点
Node*nextl=c->next;
c->next=c->next->next;
free(nextl);
      }
      c=c->next;
    }
  }
}
void removeallslist(Slist*slist,int v){
  if(slist->first==NULL){
    return ;
  }
  Node*c=slist->first;
  while(c->next!=NULL){
    Node*nextl=c->next;
    if(c->next->value==v){
      c->next=c->next->next;
      free(nextl);
    }else{
      c=c->next;//继续向后走
    }
  }
  if(slist->first->value==v){
//刚好是第一个头删
Node*second=slist->first;
slist->first=slist->first->next;
free(second);
  }
  return ;
}
//让一个链表进行翻转输入1-2-3-4-null 输出4-3-2-1-NULL 
typedef struct Listnode{
  int val;
  struct Listnode*next;
}listnode;
listnode*reverselist(listnode*head){
//头插--让原来链表的第一个节点的下一个结点变成新链表的第一个结点
//结果链表和旧的链表
listnode*result=NULL;
listnode*c=head;
while(c!=NULL){
  listnode*node=c->next;
  //定义一个指针保存c->next的地址
  //头插
  c->next=result;
  result=c;
  c=node;
}
return result;
}
listnode*removeElements(listnode*head,int v){
  if(head==NULL){
    return head;
  }
  listnode*node=head;
  while(node->next!=NULL){
//尾删
    if(node->next->val==v){
listnode*nel=node->next->next;
free(node->next);
node->next=nel;
    }else{//不等继续向下走
      node=node->next;
    }
  }
  return NULL;
}
//将两个有序链表合并成一个新链表
listnode*mergetwilist(listnode*l1,listnode*l2){
  //特殊情况处理
  if(l1==NULL) {
return l2;
  }
  if(l2==NULL){
    return l1;
  }
  //需要4个指针,12遍历l1和L2然后还有一个结果链表指针和剩余链表的指针
  listnode*c1=l1;
  listnode*c2=l2;
  listnode*result=NULL;
  listnode*tail=NULL;
  while(c1!=NULL&&c2!=NULL){
    if(c1->val<=c2->val){
      if(result==NULL){
       //开始合c1小,把c1放在结果链表而且用的尾插
       result=tail=c1;
      }else{
        tail->next=c1;
        tail=c1;
      }
c1=c1->next;//c1继续走到下一个
    }else{//c2<c1,c2先放到结果链表
      if(result==NULL){
        result=tail=c2;
      }else{
        tail->next=c2;
        tail=c2;
      }
      c2=c2->next;
    }
  }
  if(c1!=NULL){//c1没走完有c2走完
    tail->next=c1;
  }
  if(c2!=NULL){//c2M没有走完
    tail->next=c2;
    //tail=c2;可以不加
  }
  return result;
}
//法二递归
listnode*mergetwilist2(listnode*l1,listnode*l2){
  if(l1==NULL){
    return l2;
  }
  if(l2==NULL){
    return l1;
  }
  if(l1->val<=l2->val){
    l1->next=mergetwilist2(l1->next,l2);
    return l1;
  }else{
l2->next=mergetwilist2(l1,l2->next);
return l2;
  }
}
//输入一个链表找到倒数第K个结点
listnode*findKthtotal(listnode*phead,unsigned int k){
//前后指针,前面先走K后面那个在开始走
listnode*front=phead;
listnode*back=phead;
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
//一个排序的链表中,存在重复的结点,删除所有重复的结点并返回头指针
listnode*delectall(listnode*phead){
  if(phead==NULL){
    return NULL;
  }
  //如果是头结点要删除则创建一个假的头结点
  listnode*fake=(listnode*)malloc(sizeof(listnode));
  fake->next=phead;
  listnode*prev=fake;
  listnode*p1=phead;
  listnode*p2=phead->next;
  while(p2!=NULL){
    if(p1->val!=p2->val){
      //不相等都同时走
      prev=p1;
      p1=p2;
      p2=p2->next;
    }else{
      //相等了
      while(p2!=NULL&&p2->val==p1->val) {
        p2=p2->next;
      }
      listnode*cur=p1;
      while(cur!=p2){
        listnode*nextl=cur->next;
        free(cur);
      }
      prev->next=p2;
      p1=p2;
      if(p2!=NULL){
        p2=p2->next;
      }
    }
    phead=fake->next;
    free(fake);
    return phead;
  }
}
//判断一个链表是否有环
bool hascycle(listnode*head){
  if(head==NULL){
    return NULL;
  }
  listnode*fast=head;
  listnode*slow=head;
  while(fast!=NULL&&fast->next!=NULL){
    fast=head->next->next;
    slow=head->next;
  
  if(fast==slow){
    break;
  }
}
return false;
}

