#include<stdio.h>
#include <string.h>
int main(){
void sorc(char sd[][6]);
  int i;
  char sd[4][6]; 
  printf("请输入字母\n");
    for(i=0;i<4;i++){
scanf("%s\n",sd[i]);
}
sorc(sd);
printf("现在这个字符串为\n");
for(i=0;i<4;i++){
 printf("%s\n",sd[i]);
}
 return 0;
}
void sorc(char s[4][6]){
int i,j;
char *p,temp[4];
p=temp;
for(i=0;i<3;i++){
for(j=0;j<3-i;j++){
  if(strcmp(s[j],s[j+1])>0){
strcpy(p,s[j]);
strcpy(s[j],s[j+1]);
strcpy(s[j+1],p);

 
 }
}
}
}
