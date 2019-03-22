#include "Slist.h"
int main(){
  SList slist;
  slist.first=NULL;
  SListpushfront(&slist,1);
  SListpushback(&slist,2);
}
