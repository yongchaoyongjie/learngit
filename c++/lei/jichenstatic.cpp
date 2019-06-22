#include <iostream>
#include<string>
using namespace std;
class Person
{
  public :
    Person () {++ _count ;}
  protected :
    string _name ; // 姓名
  public :
    static int _count; // 统计人的个数。

};
int Person :: _count = 0;
class Student : public Person
{
  protected :
    int _stuNum ; // 学号

};
class Graduate : public Student
{
  protected :
    string _seminarCourse ; // 研究科目

};
void test()
{
  Student s1 ;
  Student s2 ;
  Student s3 ;
  Graduate s4 ;
  cout <<" 人数 :"<< Person ::_count << endl;
  Student ::_count = 0;
  cout <<" 人数 :"<< Person ::_count << endl;
}
int main(){
test();
return 0;
}
