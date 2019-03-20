#include "seqlist.h"
#include "20190318.c"
void test1(){
Seqlist seqlist;
SeqlistInit(&seqlist,10);
Seqlistpushfront(&seqlist,1);
Seqlistpushfront(&seqlist,2);
Seqlistpushfront(&seqlist,3);
Seqlistpushfront(&seqlist,4);
Seqlistpushfront(&seqlist,5);
Seqlistprint(&seqlist);
Seqlistpushback(&seqlist,100);
Seqlistpushback(&seqlist,200);
Seqlistpushback(&seqlist,300);
Seqlistpushback(&seqlist,400);
Seqlistpushback(&seqlist,500);
Seqlistprint(&seqlist);
}
int main(){
test1();

}
