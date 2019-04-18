//快排比他小的在左边比他大的在右边

//归并:
#include <stdio.h>
#include <stdlib.h>
//快排:时间复杂度:
//最好=平均O(n*logN)
//最坏
//基准值选嘴边上作为基准值,当数组本身就是有序或者无序时最坏
//情况发生(单支树)
//一选基准值有三种方式:
//1选最边上(左边/右边)
//2随机(降低最坏情况的发生)
//3三数取中法(最边上的两个,中间的那个,然后取值为三个数的中间那个作为基
//准值)只要把基准值和最左边交换就可以了
//二:遍历整个区间,把小的放左边大的放右边
//1hover
//2挖坑
//3前后下标
//三分治算法直到size==0无序排序或者size==1已经有序
//四时间复杂度:最好(nlogn)平均也是,最坏 n^2
//空间复杂度:最好o(long(n)),平均一样,最坏n
//void quicksort(int arry[],int low,int high){
//int pivot= partition_1(arry,low,high);//把大的放左小的放右
// quicksort(arry,low,pivot-1);//分成3部分小,
// //[privot,privot]有序
// quicksort(arry,pivot+1,high);//大
//}
void swap(int arry[],int i,int j){
  int t=arry[i];
  arry[i]=arry[j];
  arry[j]=t;
}
//对数组 中[low,high],的返回区间左分组
//基准值是arry[low]
//小的放在基准值左边大的放在右边
int partition_1(int arry[],int low,int high){
  int begin=low;
  int end=high;
  int pivot=arry[low];//基准值
  //(begin,end)的区间是没被比较过的数据
  while(begin<end){
    //重点:如果基准值在边需要从右边开始走
    //区间中所有的值都要被基准值比较过
    while(begin<end&&arry[end]>=pivot){
      end--;
      }
    if(begin==end){
      break;
    }
    while(begin<end&&arry[begin]<=pivot){
      begin++;
      }
   swap(arry,begin,end) ;
  }
  swap(arry,end,begin);
  return begin;
}
int partition_2(int arry[],int low,int high){
  int begin=low;
  int end=high;
  int pivot=arry[low];//基准值
  //(begin,end)的区间是没被比较过的数据
  while(begin<end){
    while(begin<end&&arry[end]>=pivot){
      end--;
      }
    arry[begin]=arry[end];//end是坑下标
    while(begin<end&&arry[begin]<=pivot){
      begin++;
      }
    arry[end]=arry[begin];//赋值后begin变成坑了
  }
  arry[begin]=pivot;//相遇循环结束基准值填到坑里
  return begin;
}
//前后下标法
int partition_3(int arry[],int low,int high){
int d=low+1;//从基准值+1开始走
int i=low+1;
int privot=arry[low];
while(i<=high){
  if((arry[i])>=privot){
    i++;
  }
  else{
    swap(arry,d,i);
    d++;
   // i++;
  }
  i++;
}
  swap(arry,d-1,low);
  return d-1;
}
void quicksort(int arry[],int low,int high){
int pivot= partition_1(arry,low,high);//把大的放左小的放右
 quicksort(arry,low,pivot-1);//分成3部分小,
 //[privot,privot]有序
 quicksort(arry,pivot+1,high);//大
}
void printfqucklysort(int arry[],int size){
int i=0;
for(;i<size;i++){
  printf("%d",arry[i]);
}
printf("\n");
}

void quicksort1(int arry[],int size){
  
}
//归并排序
// 1.把整个数组平均分成左右两部分
// 2.分治算法
// 先对左边的区间进行归并排序
// 右边的区间进行归并排序
// 直到size=0或者size=1
//3.合并两个有序数组左闭右开
//时间复杂度:n*logn
//空间复杂度:n
//可以做外部排序
//磁盘排序,数据量的排序--多路归并

void merge(int arry[],int left,int mid,int right,int extra[] ){
int i=left;
int j=mid;
int k=left;
while(i<mid&&j<right){
  if(arry[i]<=arry[j]){
    extra[k++]=extra[i++];
  }else{
    extra[k++]=extra[j++];
  }
}
while(i<mid){
  extra[k++]=arry[i++];
}
while(j<right){
  extra[k++]=arry[j++];

}
int x;
for(x=left;x<right;x++){
arry[x]= extra[x];
}
}
void _mergesort(int arry[],int left,int right,int extra[]){
  if(right==left+1){
    return ;//[3,4)
  }
  if(right<=left){
    return;
  }
  int mid=left+(right-left)/2;
_mergesort(arry,left,mid,extra);
_mergesort(arry,mid,right,extra);
merge(arry,left,mid,right,extra);
}

void mergesort(int arry[],int size){
  int *extra=(int *)malloc(sizeof(int)*size);
 _mergesort (arry,0,size,extra);
 free(extra);
}
void test(){
  int arry[]={9,5,4,6,7,3,2,4,12,6};
  int size=(sizeof(arry)/sizeof(int));
    printfqucklysort(arry,size);
    mergesort(arry,size);
    printfqucklysort(arry,size);
}
int main(){
test();
return 0;
  
}
