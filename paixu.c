#include <stdio.h>
#include <stdlib.h>
void swap(int arrry[],int i,int j){
int t=arrry[i];
arrry[i]=arrry[j];
arrry[j]=t;
}
//七大排序(针对所有情况都能排序)
//不给说明为从小到大
//5(a) 3 1 4 5(b)排序后为:1 3 4 5(a) 5(b),排序完保证前面的在前面
//稳定性:多次排序注重稳定性
//内部排序:数据元素放在内存中排序
//外部排序:
//常见的排序算法:(1)插入排序:1.直接插入排序2.希尔排序
//(2)选择排序1.选择排序2.堆排序
//(3)交换排序:1.冒泡2快速排序
//(4)归并排序:归并排序
//插入排序
//手中牌有序,来了一个牌插入,一次解决一个数据直到所有的数据都有序逐步,最外部是
//n张牌(前半部分有序中间插入)
//最外层循环是一次处理一张牌循环了N次
void insertsort(int arry[],int size) {
  int i=0,j=0;
  for(i=0;i<size;i++){//外部一个循环内部出一个数
    //比较的位置为[0,i-1]
    int key=arry[i];//保存i的位置的值
    for(j=i-1;j>=0;j--){//j一开始为-1是有序的,-1退出
      if(arry[j]<=key){//不需要换
      //比如1和9比大j+1和j换然后继续1和3比还是互换,然后到首部j=-1停止
      //然后把key放到arry[j+1]的位置
        break;
      }else{
      arry[j+1]=arry[j];//前面大于后面则前后换位置
    }
    }
arry[j+1]=key;
  }
}
void printarry(int arry[],int size){
  int i=0;
  for(;i<size;i++){
    printf("%d",arry[i]);
  }
  printf("\n");
}
void test(){
  int arry[]={3,9,1,4,7,5,2,8,0,10,9};
  int size=sizeof(arry)/sizeof(int);
  printarry(arry,size);
  insertsort(arry,size);
  printarry(arry,size);
}
int main(){
 test() ;
  return 0;
}
void insertsort1(int arry[],int size){
  //一次处理一个数,所需要循环size次
  //严格意义上size-1 就够了
  //有序为[0,i-1]要处理[i],无序[i+1,size-1]
int i=0;
  for(;i<size;i++){
    //遍历整个有序区间[0,i-1]查找合适的位置
   int j=i;
   for(j=0;j<i-1&&arry[j]<=arry[i];j++){}//循环都没有找到比它大
     //的插入的位置就是i,把数据arry[i]插进去
     //倒着找for(j=i-1;j>=0&&arry[j]>arry[i],j--)
     if(j!=i){//当i=j什么都不干daozhe if(j+1!=i)
       //看做把arry[i]插入到[0,i-1]的顺序表里
       ////插入的下标是j
       int key=arry[i];
       int k=0;
       for(k=i;k>j;k--){//插入式从后往前搬数据,k为空间下标,搬到数据的位置
arry[k]=arry[k-1];
       }
       arry[j]=key;//用key保存之前的数据然后在放在下标否则
       //下标为i的值则会被替换//fanzhe arry[j+1]=k;
     }
   
  }
}
//优化
void insertsort2(int arry[],int size){
  int i=0;
  for(;i<size;i++){
    int key=arry[i];
    int j;
    for(j=i-1;j>=0&&arry[j]>key;j--){
      arry[j+1]=arry[j];
    }
    arry[j+1]=key;//一边找合适位置一边往后搬
  }
}
void insertsortwithgap(int arry[],int size,int gap){
  int i=0;
  for(;i<size;i++){
    int key=arry[i];
    int j;
    for(j=i-gap;j>=0&&arry[j]>key;j-=gap){
      arry[j+gap]=arry[j];
    }
    arry[j+gap]=key;
  }
}
//时间复杂度:
//最好:o(n)
//最坏o(n^2),减少了最坏情况出现的概率
//平均o(n^1.2-1.3)
//空间复杂度:o(1)
//稳定性:不稳定(无法保证相同的数被分到一个组里分到不同组很难保证谁在前在后)
void shellsort(int arry[],int size){
int gap=size;
while(1){
  gap=(gap/2);
  gap=gap/3+1;
  insertsortwithgap(arry,size,gap);
  if(gap==1){
    break;
  }
}
}
//选择排序:1直接排序2堆排序
//把数组看成两部分
//时间复杂度:数据不敏感的(不因为有序就变化也不因为无序增多)
//最好最坏都是o(n^2);
//空间复杂度o(1)
//稳定性:不稳定,9 3  5  5  (无法保证前面一定比后面大遇到相等的情况就不稳定了k)
void selectsort(int arry[],int size){
  int i=0;
  for(;i<size;i++){
    //无序:[0,size-1-i],知道无序便可推出有序 
    //有序[size-1-i+1]-->有序为[size-i,size-1]
    int maxidx=0;
    //查找整个无序区间的最大值的下标
    int j=0;
    for(;j<=size-1-1;j++){//将这个替换成堆查找就是堆排序
      if(arry[j]>arry[maxidx]){
        maxidx=j;
      }
    }
    //maxidx记录着无序区间部分最大的数的下标
    //和无序区间的最后一个位置的数进行交换
swap(arry,maxidx,size-i-i);//最大值交换是和无序区间的最后 一个下标交换  
  }
}
void heapify(int arry[],int size,int index){//向下调整
//1判断是不是叶zi
int left=2*index+1;
int right=2*index+2;
if(left>=size){
  return ;
}
//2找到最大的孩子
//1)没有右孩子
//2)有右孩子情况1>左孩子大2>右孩子大
//3最大的孩子和根比较,如果根比较大退出
//4交换并继续调整
int max=left;//假设最大为左边
if(right<size&&arry[right]>arry[left]){
  //最大为右边
  max=right;
}
if(arry[index]<=arry[max]){
  return ;
}
swap(arry,size,index);//都是下标,交换完继续调整
heapify(arry,size,max);
}
void createheap(int arry[],int size){
//从最好一个非叶子结点,一直到0,不断向下调整
int i=0;
for(i=(size-2)/2;i>=0;i--){
heapify(arry,size,i);
}
}
//堆排序
void heapsort(int arry[],int size){
//排升序建大堆
createheap(arry,size);
int i=0;
for(;i<size;i++){
  //一次处理一个数
  //[0,size-1-i]无序
  //有序[size-i,size-1]
  //交换最大的数和无序区间的最后一个数
  swap(arry,0,size-1-i);
  //堆的性质被破坏,只有根的地方被破坏
  //要调整的是剩余无序部分的长度size-1-i
  heapify(arry,size-1-i,0);
}
}
//冒泡时间复杂度最坏情况o(n^2)
//最坏o(n)
//平局情况o(n^2)
//空间复杂度为o(1)
//稳定性:稳定不会把相同的数往后挤
void bubblesort(int arry[],int size){
  int i=0;
  for(;i<size;i++){
    int issorted=1;
    //有序[size-i,size-1]
    //无序[0,size-1-i]
    int j=0;
    for(;j<size-1-i;j++){//为什么不是<=size-1-i;j走到最后一个区间j+1则出去了越界
      if(arry[j]>arry[j+1]){
      swap(arry,j,j+1);
      issorted=0;//发生交换issorted等于0
      }
    }
    if(issorted==1){
      break;//有序了
    }
  }
}
//利用二分查找实现插入排序
void insertsortbs(int arry[],int size){
int i=0;
for(;i<size;i++){
  //[0,i-1]有序
  //[i,size-1]无序
  int left=0;
  int right=i-1;
  //[left,right]
  while(left<=right){//最后结果为left=3,right=2[0,3]mid=1;
    int mid=left+(right-left)/2;
    if(arry[mid]==arry[i]){
      //怎么保证稳定
      left=mid+1;
    }
    else if (arry[mid]<arry[i]){
      left=mid+1;
    }
    else{
      right=mid-1;
    }
  }
  int k=0;
  //left是要插入位置的下标
  int key=arry[i];
  for(k=i;k>left;k--){
    arry[k]=arry[k-1];
  }
  arry[left]=key;
}
}
//选择排序(依次选择两个数)
void selectsortop(int arry[],int size){//一次解决两个数
  int begin=1;
  int end=size-1;
  //[o,begin]有序,最小的数
  //[begin,end]无序
  //[end+1,size-1]有序最大的数
  while(begin>=end){
    int min=begin;
    int max=begin;
    int i=0;
    for(i=begin;i<=end;i++){
      if(arry[i]>arry[max]){
        max=i;
      }
      if(arry[i]>arry[min]){
        min=i;
    }
  }
    //最小的数放到无序区间的最开始
    //最大的数放到无序区间的最末尾
    swap(arry,min,begin);
    if(max==begin){//找到最大数的下标和begin下标为同一个导致第一次交换后最大数
    //被移走了
      max=min;
    }
    swap(arry,max,end);
    begin++;
    end--;
}
}
void test1(){
  int arry[]={9,4,3,7,2,5,8,8,7,1,3};
  int size=sizeof(arry)/sizeof(int);
 printarry(arry,size) ;
}
