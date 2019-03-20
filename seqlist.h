#pragma once
//动态数据列表
typedef int SLDateType;
typedef struct Seqlist{
SLDateType*array;
int size;
int capacity;//容量
} Seqlist;
//初始化和销毁
void SeqlistInit(Seqlist*seqlist,int capacity);
void SeqlistDestroy(Seqlist*seqlist);
//核实是否需要扩容
void CheckCapacity(Seqlist*seqlist);

//增删改查
//头插
void Seqlistpushfront(Seqlist*seqlist,SLDateType v);
//尾插
void Seqlistpushback(Seqlist*seqlist,SLDateType v);
//按照pos下标进行插入,也就是中间插入
void  Seqlistinsert(Seqlist*seqlist,int pos,SLDateType v);
//头删除
void Seqlistpopfront(Seqlist*seqlist);
//中间删除
void Seqlisterase(Seqlist*seqlist,int pos);
//修改
void Seqlistmodify(Seqlist*seqlist,int pos,SLDateType v);
int Seqlistfind(Seqlist*seqlist,SLDateType v);
void Seqlistremove(Seqlist*seqlist,SLDateType v);
void Seqlistremoveall(Seqlist*seqlist,SLDateType v);
