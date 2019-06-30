#include<iostream>
using namespace std;
template<class T>
class SmartPtr
{
  public:
    SmartPtr(T* ptr)
      :_ptr(ptr)
    {}

    ~SmartPtr()
    {
      cout << "delete:" <<_ptr << endl;
      delete _ptr;
    }

    T& operator*()
    {
      return *_ptr;
    }

    T* operator->()
    {
      return _ptr;
    }

    T* get()
    {
      return _ptr;
    }
  private:
    T* _ptr;
};

void Div(double a, double b)
{
  if (b == 0)
  {
    invalid_argument err("除数等于0");
    throw err;
  }
  else
  {
    cout << a/b << endl;
  }
}

struct A
{
  int _a1;
  int _a2;
};

void Func()
{
  SmartPtr<int> sp(new int); // 托管
  int* p = sp.get();
  *p = 10;
  cout << *p << endl;
  *sp = 10;
  sp.operator*() = 20;
  cout << *sp << endl;

  SmartPtr<A> spa(new A);
  cout << spa->_a1 << endl;
  cout << spa.operator->()->_a1 << endl;
  cout << spa->_a2 << endl;

  double x1, x2;
  cin >> x1 >> x2;
  Div(x1, x2);
}


void test()
{
  try{
    Func();
  }
  catch (exception& e)
  {
    e.what();
  }
  return 0;
}

// 智能指针的深浅拷贝
int main()
{
  SmartPtr<int> sp1(new int);
  SmartPtr<int> sp2(sp1);
  int* p1 = new int;
  int* p2 = p1;

  return 0;
}

