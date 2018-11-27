#pragma once
#include<iostream>
#include<ostream>


//Class fille Vec2..
template <typename TYPE = float> class Vec2
{
public:

  Vec2<TYPE>(TYPE x = 0.0,TYPE y = 0.0);
  Vec2<TYPE>(const Vec2<TYPE> & vec2);
  Vec2<TYPE> operator+(Vec2& vec2);
  Vec2<TYPE> operator-(Vec2& vec2);
  Vec2<TYPE> operator*(const float k);
  Vec2<TYPE> operator*(Vec2& vec2);

  //setter et getter...
  TYPE x() const {return _data[0];}
  TYPE y() const {return _data[1];}

  void Setx(TYPE x){_data[0] = x;}
  void Sety(TYPE y){_data[1] = y;}
  void setElement(int i, TYPE var){_data[i] = var;}
  void addElement(int i, TYPE var){_data[i] = _data[i] + var;}
  TYPE getElement(int i) const {return _data[i];}

  TYPE* data(){return &(_data[0]);}

  //operation sur des vecteur...
  TYPE dot(const Vec2& vec2);

private :
  TYPE _data[2];
};



template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Vec2<TYPE>& vec2)
{
    Stream << "["<< vec2.x() << ";" << vec2.y() << "]" << std::endl;
    return Stream;
}




template <typename TYPE>
Vec2<TYPE>::Vec2(TYPE x,TYPE y)
{
  Setx(x); Sety(y);
}


template <typename TYPE>
Vec2<TYPE>::Vec2(const Vec2<TYPE> & vec2)
{
  this->Setx(vec2.x()); this->Sety(vec2.y());
}


template <typename TYPE>
Vec2<TYPE> Vec2<TYPE>::operator+( Vec2& vec2)
{
  Vec2<TYPE> res(this->x() + vec2.x(),this->y() + vec2.y());
  return res;
}

template <typename TYPE>
Vec2<TYPE> Vec2<TYPE>::operator-(Vec2& vec2)
{

  Vec2<TYPE>  res(this->x() - vec2.x(),this->y() - vec2.y());
  return res;
}


template <typename TYPE>
Vec2<TYPE> Vec2<TYPE>::operator*(const float k)
{
  Vec2<TYPE> res(this->x() * k,this->y() * k);
  return res;
}
