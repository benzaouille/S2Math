#pragma once
#include<iostream>
#include<ostream>


//Class fille Vec3..
template <typename TYPE = float> class Vec3
{
public:

  Vec3<TYPE>(TYPE x = 0.0,TYPE y = 0.0,TYPE z = 0.0);
  Vec3<TYPE>(const Vec3<TYPE> & vec3);
  Vec3<TYPE> operator+(Vec3& vec3);
  Vec3<TYPE> operator-(Vec3& vec3);
  Vec3<TYPE> operator*(const float k);
  Vec3<TYPE> operator*(Vec3& vec3);

  //setter et getter...
  TYPE x() const {return _data[0];}
  TYPE y() const {return _data[1];}
  TYPE z() const {return _data[2];}

  void Setx(TYPE x){_data[0] = x;}
  void Sety(TYPE y){_data[1] = y;}
  void Setz(TYPE z){_data[2] = z;}
  void setElement(int i, TYPE var){_data[i] = var;}
  void addElement(int i, TYPE var){_data[i] = _data[i] + var;}
  TYPE getElement(int i) const {return _data[i];}
  TYPE* data(){return &(_data[0]);}

  //operation sur des vecteur...
  TYPE dot(const Vec3& vec3);

private :
  TYPE _data[3];
};


template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Vec3<TYPE>& vec3)
{
    Stream << "["<<vec3.x() << " ; " << vec3.y() << " ; " << vec3.z()<<"]" << std::endl;
    return Stream;
}


template <typename TYPE>
Vec3<TYPE>::Vec3(TYPE x,TYPE y,TYPE z)
{
  Setx(x); Sety(y); Setz(z);
}


template <typename TYPE>
Vec3<TYPE>::Vec3(const Vec3<TYPE> & vec3)
{
  this->Setx(vec3.x()); this->Sety(vec3.y()); this->Setz(vec3.z());
}


template <typename TYPE>
Vec3<TYPE> Vec3<TYPE>::operator+( Vec3& vec3)
{
  Vec3<TYPE> res(this->x() + vec3.x(), this->y() + vec3.y(), this->z() + vec3.z());
  return res;
}

template <typename TYPE>
Vec3<TYPE> Vec3<TYPE>::operator-(Vec3& vec3)
{
  Vec3<TYPE> res(this->x() - vec3.x(), this->y() - vec3.y(), this->z() - vec3.z());
  return res;
}


template <typename TYPE>
Vec3<TYPE> Vec3<TYPE>::operator*(const float k)
{
  Vec3<TYPE> res(this->x() * k, this->y() * k, this->z() * k);
  return res;
}
