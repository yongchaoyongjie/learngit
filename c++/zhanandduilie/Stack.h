#include<iostream>
#include<deque>
using std::deque;
using std::cout;
using std::endl;
template<class T, class Contain=deque<int>>
//用deque实现一个栈
class Stack{
  public:
    void Push(const T &x) {
_con.push_back(x);
    }   
    void Pop(){
      _con.pop_back();
    }
    size_t Size()const{
      return _con.size();
    }
    bool Empty(){
      return _con.empty();
    }
    T&Top(){
      return _con.back();
    }
const    T&Top() const
    {
      return _con.back();
    }

  private:
    Contain _con;
};
void test(){
Stack<int,deque<int>> s;
s.Push(1);
s.Push(2);
s.Push(3);
s.Push(4);
while(s.Empty()){
cout<<s.Top()<<endl;
}
}
