#include<istream>
#include<pthread.h>
#include <queue>
class BlockQueue{
  private:
int capty;
std::queue<int>_list;
pthread_mutex_t _constumermutex;
pthread_cond_t _consumercond;
pthread_cond_t _productcond;
  public:

};
