#include <stdio.h>
#include <assert.h>
//时间复杂
typedef struct heap{
  int tree[100];
  int size;
}heap;
//堆为逻辑上的完全二叉树
//任取一个节点要求根的值>左右孩子的值
void heapinit(heap*ph,int array[],int size);
void heappush();
void heappop();
void adjustdown(int tree[],int size,int rootidex){
//判断是不是叶子,是叶子返回
//怎么判断rootidex是不是叶子-->没有左右孩子->完全二叉树-->没有左孩子就没有右
//-->孩子-->判断有没有左孩子-->(不是rootidx->left==null),根据rootidex 
//找到左孩子的下标,看左孩子下标是否越界就可以了;
//因为堆存在数组里,判断的标准就是左孩子的下标是否越界
int leftidex=2*rootidex+1;
int rightidex=2*rootidex+2;
//数组越界
if(leftidex>=size){
  //是叶子,结束,叶子就是最下面的那个
  return ;
}
//不是叶子
int minidx=leftidex;
//不是叶子找到最小孩子下标拿最小孩子的值和根的值进行比较
//如果有右孩子,比较左右的值,找到最小的否则选左孩子(没有右孩子)
//如果根的值最小调整结束,直接返回
//交换和最小孩子的值,继续对刚才最小孩子的小标进行调整
if(rightidex<size&&tree[rightidex]<tree[leftidex]){//什么时候等于右孩子
  //必须有右孩子
  //条件不能反c语言短路的特点如果前面条件不满足不会走后面
 minidx=rightidex;//最小的为右孩子
}
//最小孩子下标就是minidx
if(tree[rootidex]<=tree[leftidex]){
  //最小的是根,满足根的性质停止
  return ;
}
//不满足交换
int t=tree[minidx];
tree[minidx]=tree[rootidex];
tree[rootidex]=t;
//如果发生了交换则下面的树的堆性质可能被破坏了,继续调整
adjustdown(tree,size,minidx);
}
void adjustdown1(int tree[],int size,int rootidex){
  //如果是叶子直接返回
  //如果不是叶子找到最小的孩子的下标
  //拿最小孩子的值和要调整的根的值进行 比较如果根的值比较小
  //调整结束直接返回
  //否则交换根的值和最小孩子的值继续对刚才最小的孩子的下标进行调
}
//建堆把一个完全无序的随机分布数组变成满足堆的性质
//
void createheap(int tree[],int size){
  //为什么需要倒着调整向下调整的前提是有限制,必须左右子树都已经是堆
  //才可以向下调整
//最后一个节点下标为size-1最后一个非叶子结点就是最后一个节点的双亲
//parent=(child-1)/2;所以为(size-1-1)/2;
int i=0;
  for(i=(size-2)/2;i>=0;i++){
    adjustdown(tree,size,i);
  }
}
void heapinit(){
  assert(size<=100);
  memcpy();
  createheap();
}
int heappop(heap*ph,int v){
  //每次出的是
  //下标为0 的拿出来,size-1放到arry[0],对其进行向下调整
  int v=ph->array[0];
ph->array[0]=ph->array[size-1];
  ph->size--;
  adjustdown(ph->array,ph->size,0);
  return v;
}
void adjustup(int tree[],int size,int child){//向上调整
  if(child==0){
    return ;
  }
  int parent=(child-1)/2;
  if(tree[child]>=tree[parent]){
    return ;
  }
  int t=tree[child];
  tree[child]=tree[parent];
  tree[parent]=t;
  adjustup(tree,size,child);
}
void heappush(){
  //插入到最后,逐渐向上升,只要和双亲进行比较就可以了
  //1当前array[i]>=array[parent];
  //
}
void test(){
  int array[]={6,9,13,7,1,8,2,45};
  int size;
  createheap(array,size);
}
