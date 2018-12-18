#include <stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE (100)
typedef int DataType;
typedef struct Seqlist {
  DataType arr[MAX_SIZE];
int size;
} SeqlistR;
void SeqlistInit(SeqlistR *pseq){
assert(pseq!=NULL);
pseq->size=0;
}
void Seqlistposhback(SeqlistR *pseq,DataType data){//尾插法
assert(pseq!=NULL);
if(pseq->size==MAX_SIZE){
  printf("满了\n");
  return ;
}
pseq->arr[pseq->size]=data;
pseq->size+=1;
}
void Seqlistpushfront(SeqlistR *pseq ,DataType data){
//头插 法
int i;
assert(pseq!=NULL);
if(pseq->size==MAX_SIZE){
  printf("满了\n");
  return;
}
///法2数据坐标
for(i=pseq->size-1;i>=0;i--){
  pseq->arr[i+1]=pseq->arr[i];
}
///法一空间坐标
///for(i=pseq->size;i>0;i--){
//binpseq->arr[i]=pseq->arr[i-1];
//bin}
pseq->arr[0]=data;
pseq->size+=1;

}
//删除表三种方法从头尾巴和中间删除
//1尾巴删除
void seqlsitpopback(SeqlistR *pseq){

assert(pseq!=NULL);//保证表存在
assert(pseq->size!=0);//保证顺序表不能为空
pseq->size--;
}
void Seqlistpopfront(SeqlistR *pseq){
assert(pseq!=NULL);//保证表存在
assert(pseq->size!=0);//保证顺序表不能为空
//法1空间坐标删除
int i;
//for(i=0;i<(pseq->size-1);i++){

//pseq->arr[i]=pseq->arr[i+1];

//}
//数据坐删除
for(i=1;i<(pseq->size);i++){
 pseq->arr[i-1]=pseq->arr[i];

}
pseq->size-=1;
}
//中间删除
void Seqlisterase(SeqlistR *pseq ,int pos){
  int i;
assert(pseq!=NULL);
assert(pseq->size!=0);
assert(pos>=0&&pos<pseq->size);
for (i=pos;i<=pseq->size-2;i++){
pseq->arr[i]=pseq->arr[i+1];

}
pseq->size-=1;
}
//查找
int  Seqlistfind(SeqlistR *pseq,DataType data){
 int i;
  for(i=0;i<pseq->size;i++){
    if(data==pseq->arr[i]){
      return i;
    }
  }
return -1 ;
}
//void Seqlistremove(Seqlist *pseq,DataType data ){
//int pos=Seqlistfind (pseq,data);
//if(pos==-1){
 // return -1;//没找到
///}
//}
void Seqlistprint(const SeqlistR *pseq){
int i;
  for(i=0;i<pseq->size;i++)
  {
    printf("%d\n",pseq->arr[i]);
  }
}
void test (){
  SeqlistR Seqlist;
  SeqlistInit(&Seqlist);
    assert(Seqlist.size==0);//希望表尾空
Seqlistposhback(&Seqlist,1);
Seqlistposhback(&Seqlist,2);
Seqlistposhback(&Seqlist,3);
Seqlistposhback(&Seqlist,4);
Seqlistprint(&Seqlist);
//Seqlistpushfront(&Seqlist,11); 
//Seqlistpushfront(&Seqlist,12);
//Seqlistpushfront(&Seqlist,13);
//Seqlistpushfront(&Seqlist,14);
//Seqlistprint(&Seqlist);
//seqlsitpopback(&Seqlist);
//Seqlistprint(&Seqlist);
Seqlistpopfront(&Seqlist );
Seqlistfind(&Seqlist,3);
Seqlistprint(&Seqlist);
}
int main(){
test ();
return 0;
}
