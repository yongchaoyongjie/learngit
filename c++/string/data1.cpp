#include<iostream>
using std::cout;
using std::endl;
class Date{
  public:
    inline int GetmonthDay(int year,int month)const 
    {
static int montharray[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
if(month==2&&((year%4==0)&&year%100!=0)&&(year%400!=0)){
  return 29;//是闰年
}
return montharray[month];
    }
Date(int year=1900,int month=1,int day=1){
  if(year>=1900&&month>0&&month<13&&day>0&&day<=GetmonthDay(year,month)){
    _year=year;
    _month=month;
    _day=day;
  }
  else{
    cout<<"非法日期"<<endl;
  }
}
void Print(){
  cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}
bool operator>(Date const &d );
bool operator>=(Date const &d );
bool operator<(Date const &d );
bool operator<=(Date const &d );
bool operator!=(Date const &d );
bool operator==(Date const &d );
Date operator++();//前置++
Date operator++(int);//前置++
Date operator--();//后置++
Date operator--(int);//后置++
Date operator+(int day) const;
Date operator-(int day)const;
Date operator+=(int day);
Date operator-=(int day);
int operator -(const Date&day)const;
private:
int _year;
int _month;
int _day;
};
bool Date::operator>(Date const &d ){
  if(_year>d._year){
return true;
  }
  else if (_year==d._year){
    if(_month>d._month){
      return true;
    }
    else if (_month==d._month){
      if(_day>d._day){
        return true;
      }
    }
  }
  return false;
}
bool Date::operator>=(Date const &d ){
  return * this>d||*this==d;
}
bool Date::operator<(Date const &d ){
  if(_year<d._year){
return true;
  }
  else if (_year==d._year){
    if(_month<d._month){
      return true;
    }
    else if (_month==d._month){
      if(_day<d._day){
        return true;
      }
    }
  }
  return false;
}
bool Date::operator<=(Date const &d ){
return *this<d||*this==d;
}
bool Date::operator!=(Date const &d ){
 return !(*this==d);
}
bool Date::operator==(Date const &d ){
  return _year==d._year&&_month==d._month&&_day==d._day;
}
Date Date::operator++(){//前置++
  *this+=1;
  return *this;
}
Date Date::operator++(int){
  //前置++
  Date ret(*this);//拷贝构造
  *this+=1;
  return ret;
}
Date& Date::operator--(){//前置++
*this-=1;
return *this;
}
Date Date::operator--(int){//后置++
  Date ret(*this);
  *this-=1;
  return ret;
}
Date Date::operator+(int day) const{
Date ret=*this;
ret+=day;
return *this;
}
Date Date::operator-(int day)const{
Date ret(*this);
ret-=day;
return *this;
}
Date& Date::operator+=(int day){
  if(day<0){
   return  *this-=-day;
  }
  _day+=day;
  while(_day>GetmonthDay(_year,_month)){
_day-=GetmonthDay(_year,_month);
_month++;
if(_month==13){
  _year++;
  _month=1;
}
  }  
return *this;
}
Date& Date::operator-=(int day){
  if(day<0){
    return *this +=-day;
  }
  _day-=day;
  while(_day<=0){
    --_month;
    if(_month==0){
      _month=12;
      --_year;
    }
    _day+=GetmonthDay(_year,_month);
  }
  return *this;
}
Date Date::operator-(int day)const{
Date ret(*this);
ret-=day;
return ret;
}

