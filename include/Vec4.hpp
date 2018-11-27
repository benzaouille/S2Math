#pragma once
#include<iostream>
#include<ostream>


//Class fille Vec4..
template <typename TYPE = float> class Vec4
{
public:
  Vec4<TYPE>(TYPE x = 0.0,TYPE y = 0.0,TYPE z = 0.0,TYPE w = 0.0);
  Vec4<TYPE>(const Vec4<TYPE> & Vec4);
  Vec4<TYPE> operator+(Vec4& Vec4);
  Vec4<TYPE> operator-(Vec4& Vec4);
  Vec4<TYPE> operator*(const float k);
  Vec4<TYPE> operator*(Vec4& Vec4);

  //setter et getter...
  TYPE x() const {return _data[0];}
  TYPE y() const {return _data[1];}
  TYPE z() const {return _data[2];}
  TYPE w() const {return _data[3];}

  void Setx(TYPE x){_data[0] = x;}
  void Sety(TYPE y){_data[1] = y;}
  void Setz(TYPE z){_data[2] = z;}
  void Setw(TYPE w){_data[3] = w;}
  void setElement(int i, TYPE var){_data[i] = var;}
  void addElement(int i, TYPE var){_data[i] = _data[i] + var;}
  TYPE getElement(int i) const {return _data[i];}
  
  TYPE* data(){return &(_data[0]);}

  //operation sur des vecteur...
  TYPE dot(const Vec4& Vec4);

private :
  TYPE _data[4];
};

template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Vec4<TYPE>& vec4)
{
    Stream << "["<<vec4.x() << " ; " << vec4.y() << " ; " << vec4.z()<<  " ; " << vec4.w()<< "]" << std::endl;
    return Stream;
}


template <typename TYPE>
Vec4<TYPE>::Vec4(TYPE x,TYPE y,TYPE z,TYPE w)
{
  Setx(x); Sety(y); Setz(z); Setw(w);
}


template <typename TYPE>
Vec4<TYPE>::Vec4(const Vec4<TYPE> & vec4)
{
  this->Setx(vec4.x()); this->Sety(vec4.y()); this->Setz(vec4.z()); this->Setw(vec4.w());
}


template <typename TYPE>
Vec4<TYPE> Vec4<TYPE>::operator+( Vec4& vec4)
{
  Vec4<TYPE> res(this->x() + vec4.x(), this->y() + vec4.y(), this->z() + vec4.z(), this->w() + vec4.w());
  return res;
}

template <typename TYPE>
Vec4<TYPE> Vec4<TYPE>::operator-(Vec4& vec4)
{
  Vec4<TYPE> res(this->x() - vec4.x(), this->y() - vec4.y(), this->z() - vec4.z(), this->w() - vec4.w());
  return res;
}


template <typename TYPE>
Vec4<TYPE> Vec4<TYPE>::operator*(const float k)
{
  Vec4<TYPE> res(this->x() * k, this->y() * k, this->z() * k, this->w() * k);
  return res;
}
