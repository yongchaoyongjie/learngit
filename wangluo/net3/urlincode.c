#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define BUFF_MAX 1024
#define  S_HEX(x) (((x)<='9')?((x)-'0'):(((x)<='F')?((x)-'A'+10):((x)-'a'+10))
    char*urlencode(char*ur1){
    static char buff[BUFF_MAX]={0};
    char *tmp=ur1;
    int len =0;
    char *hex="0123456789abcdef";
    if(ur1==NULL){
    printf("url is null\n");
    return NULL;
    }
    memset(buff,0x00,BUFF_MAX);
    while((*tmp)!='\0'){
    if(isalnum(*tmp)){//数据不是结尾而且不是特殊字符
    buff[len++]=*tmp;
    }else{//是特殊字符
    buff[len++]='%';
    buff[len++]=hex[((*tmp)>>4)&&0x0f];//得到高4位-->得到字符(前四位)
    buff[len++]=hex[(*tmp)&&0x0f];//得到第四位
    }
    tmp++;
    }
    return buff;
    }
char*urldecode(char*ur1){
    static char buff[BUFF_MAX]={0};
    char *tmp=ur1;
    int len =0;
    if(ur1==NULL){
    printf("ur1 is null\n");
    return NULL;
    }
    memset(buff,0x00,BUFF_MAX);
    while((*tmp)!='\0'){
      if((*tmp)=='%'){
        buff[len++]=(char)(S_HEX(*(tmp+1))*16+S_HEX(*(tmp+2)));
        //遇到%则tmp+1位置就是第一个数字tmp+2就是第二个数字(转换成16进制数字)
        //2字符转换为2数字-->2字符-0字符  s_hex转换为16进制数字*16转换为高4位
        
tmp+=2;
      }
    else{
      buff[len++]=*tmp;
    }
    tmp++;}
}
