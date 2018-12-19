#include<stdio.h>
#include <string.h>
int main(){
void sort(char*[]);
int i;
char str[4][6];
char *p[4];
for(i=0;i<4;i++){
  p[i]=str[i];
}
printf("请输入四个字符串\n");
for(i=0;i<4;i++){
scanf("%s\n",p[i]);
}
sort(p);
for(i=0;i<4;i++){
  printf("%s\n",p[i]);

}
  return 0;
}
void sort(char*s[]){
//要算斜杠0
int i,j;
char *temp;
for(i=0;i<3;i++){
  for(j=0;j<3-i;j++){
    if(strcmp(*(s+j),*(s+j+1))>0){
      temp=*(s+j);
      *(s+j)=*(s+j+1);
      *(s+j+1)=temp;
    }
  }
}
}
