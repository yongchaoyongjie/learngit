//几种排序
//遍历
#include <stdio.h>
#include <stdlib.h>
typedef int Ssize_t;
ssize_t tavalsearch(int array[],Ssize_t size,int value){
  int i;
  for(i=0;i<size;i++){
    if(array[i]==value){
      return i;
    }
  }
return -1;
}
void bubblesort(int array[],Ssize_t size){
int i;
int j;
for(i=0;i<=size-1;i++){
  //冒泡循环的第一次完成最后那个数确定为最大冒泡第二次完成确定最后两个数为最大
  //直到进行到size-1所有的数都是从小到大排列
bool sorted=true;
for(j=0;j<=size-2-i;j++){
  //j第一次到size-2,第二次size-3,第i次size-2-i
  if(array[j]>array[j+1]){
int temp;
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
  }
  sorted=false;
}
if(sorted) {
  break;
}
}
}
Ssize_t binarysearch(int array[],Ssize_t size,int value){
  //[0,size-1],左闭右闭
Ssize_t left=0;
Ssize_t right=size-1;
while(right>=left){
Ssize_t mid=(right+left)/2;
if(array[mid]==value){
  return mid;
}
else if (value<array[mid]){
right=mid-1;
}
else{
  left=mid+1;
}
}
return -1;
} 
Ssize_t binarysearch1(int array[],Ssize_t size,int value){
  //[0,size)左闭右开
 Ssize_t left=0;             
 Ssize_t right=size-1;
 while(right>left){
 Ssize_t mid=(right+left)/2;
 if(array[mid]==value){
   return mid;
 }
 else if (value<array[mid]){
   right=mid;
     }
 else{
   left=mid+1;  
 }
 }
return -1; 
 }
