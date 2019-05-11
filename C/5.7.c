#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  //给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
  //你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
  //示例:
  //给定 nums = [2, 7, 11, 15], target = 9
  //因为 nums[0] + nums[1] = 2 + 7 = 9
  //所以返回 [0, 1]
  static a[2]={0};
  for(int i=0;i<numsSize-1;i++){
    for(int j=1;j<numsSize;j++){
      if(nums[i]+nums[j]==target){
        a[0]=i;
        a[1]=j;
        return a;

      }

    }

  }
  return 0;
}

//两个数123--321 (32位)
int reverse(int x){
  int b;
  long y=0;
  if(x>-10&&x<10){
    return x;

  }
  for(y=0;x!=0;x=x/10){
    y*=10;
    y+=y%10;
  }

  if(y<=2147483647&&y>=-2147483647)
    return y;
  return 0;
}
//实现使其能将字符串转换成整数。丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。在任何情况下，若函数不能进行有效的转换时，请返回 0

//记住字符转数字就是'9'-'0'
int myAtoi1(char * str){
  int ret=0;
  int t=0;
  int i=0;
  while(i!=strlen(str)){
    if(str[i]== ' ') {
      continue;
    }
    else if(str[i]='+'){
      i++;
      while(str[i]>='0'&&str[i]<='9'){
        t = str[i++] - '0';
        ret = ret * 10 + t;
      }
      return ret;
    }
    else if(str[i]='-'){
      i++;
      while(str[i]>='0'&&str[i]<='9'){
        t=str[i]-'0';
        ret=ret*10+t;
      }
      return -ret;
    }
    else{
      return 0;
    }
  }
  return 0;
}



