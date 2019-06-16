#include <iostream>
#include<list>
#include<deque>
using std::cout;
using std::endl;
using std::deque;
using std::list;
template<class T,class Contain=deque<int>>
class Queue{
  public:
    void Push(const T &x){
_con.push_back(x);
    }
    void Pop(){
_con.pop_front();
    }
    size_t Size(){
return  _con.size();
    }
    bool Empty(){
      return _con.empty();
    }
    const T &Front(){
        return _con.front();
    }
    const T &Back(){
        return _con.back();
    }
  private:
    Contain _con;
};
void test(){
  Queue<int,deque<int>>q;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  while(q.Empty()){
    cout<<q.Front()<<endl;
  }
}
template<class T,class Contain=list<int>>
class Queue1{
  public:
    void Push(const T &x){
_con.push_back(x);
    }
    void Pop(){
_con.pop_front();
    }
    size_t Size(){
return  _con.size();
    }
    bool Empty(){
      return _con.empty();
    }
    const T &Front(){
        return _con.front();
    }
    const T &Back(){
        return _con.back();
    }
  private:
    Contain _con;
};
void test1(){
  Queue<int,list<int>>q;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  while(q.Empty()){
    cout<<q.Front()<<endl;
  }
}
