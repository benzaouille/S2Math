#pragma once
#include <iostream>
#include <ostream>
#include "Vec4.hpp"

template <typename TYPE = float > class Mat4
{
public:
  Mat4<TYPE>(TYPE x00 = 1.0, TYPE x01 = 0.0, TYPE x02 = 0.0, TYPE x03 = 0.0,
             TYPE y10 = 0.0, TYPE y11 = 1.0, TYPE y12 = 0.0, TYPE y13 = 0.0,
             TYPE z20 = 0.0, TYPE z21 = 0.0, TYPE z22 = 1.0, TYPE z23 = 0.0,
             TYPE w30 = 0.0, TYPE w31 = 0.0, TYPE w32 = 0.0, TYPE w33 = 1.0);
  Mat4<TYPE>(const Mat4<TYPE>& mat4);
  Mat4<TYPE> operator+(Mat4& mat4);
  Mat4<TYPE> operator-(Mat4& mat4);
  Mat4<TYPE> operator*(const float k);
  Mat4<TYPE> operator*(Mat4& mat4);
  Vec4<TYPE> operator*(Vec4<TYPE>& vec4);
  void setElement(int i, TYPE var){element[i] = var;}
  void setElement(int i,int j, TYPE var){element[i*4 + j] = var;}
  void addElement(int i,int j, TYPE var){element[i*4 + j] += var;}
  TYPE getElement(int i) const {return element[i];}
  TYPE getElement(int i, int j) const {return element[i*4 + j];}
  void setCol(int i, Vec4<TYPE>& vec4);
  void setCol(int i, Vec3<TYPE>& vec3);
  Mat4<TYPE> transpose();
  TYPE* data(){return &(element[0]);}

private:
  TYPE element[16];
};

template <typename TYPE>
Mat4<TYPE> operator*(const float k,Mat4<TYPE>& mat4)
{
  Mat4<TYPE> res;
  for (size_t i = 0; i < 16; i++)
  {
    res.setElement(i,mat4.getElement(i) * k);
  }
  return res;
}



template <typename TYPE>
void Mat4<TYPE>::setCol(int i, Vec4<TYPE>& vec4)
{
  for (size_t k = 0; k < 4; k++)
  {
    setElement(k,i, vec4.getElement(k));
  }
}


template <typename TYPE>
void Mat4<TYPE>::setCol(int i, Vec3<TYPE>& vec3)
{
  for (size_t k = 0; k < 3; k++)
  {
    setElement(k,i, vec3.getElement(k));
  }
}

template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Mat4<TYPE>& mat4)
{
  for (size_t i = 0; i < 13; i+=4)
  {
    Stream << "["<<mat4.getElement(i) << ";" << mat4.getElement(i+1) <<";"<<  mat4.getElement(i+2) << ";"<<  mat4.getElement(i+3) <<"]" << std::endl;
  }
  return Stream;
}
template <typename TYPE>
Mat4<TYPE>::Mat4(TYPE x00, TYPE x01, TYPE x02, TYPE x03,
                 TYPE y10, TYPE y11, TYPE y12, TYPE y13,
                 TYPE z20, TYPE z21, TYPE z22, TYPE z23,
                 TYPE w30, TYPE w31, TYPE w32, TYPE w33)
{
  element[0] = x00; element[1] = x01; element[2] = x02; element[3] = x03;
  element[4] = y10; element[5] = y11; element[6] = y12; element[7] = y13;
  element[8] = z20; element[9] = z21; element[10] = z22; element[11] = z23;
  element[12] = w30; element[13] = w31; element[14] = w32; element[15] = w33;
}


template <typename TYPE>
Mat4<TYPE>::Mat4(const Mat4<TYPE> & mat4)
{
  for (size_t i = 0; i < 16; i++)
  {
    this->setElement(i,mat4.getElement(i));
  }
}


template <typename TYPE>
Mat4<TYPE> Mat4<TYPE>::operator+( Mat4& mat4)
{
  Mat4<TYPE> res;
  for (size_t i = 0; i < 16; i++)
  {
    res.setElement(i,mat4.getElement(i) + this->getElement(i));
  }
  return res;
}


template <typename TYPE>
Mat4<TYPE> Mat4<TYPE>::operator-( Mat4& mat4)
{
  Mat4<TYPE> res;
  for (size_t i = 0; i < 16; i++)
  {
    res.setElement(i,mat4.getElement(i) - this->getElement(i));
  }
  return res;
}



template <typename TYPE>
Mat4<TYPE> Mat4<TYPE>::operator*(const float k)
{
  Mat4<TYPE> res;
  for (size_t i = 0; i < 16; i++)
  {
    res.setElement(i,this->getElement(i) * k);
  }
  return res;
}


template <typename TYPE>
Vec4<TYPE> Mat4<TYPE>::operator*(Vec4<TYPE>& vec4)
{
  Vec4<TYPE> res;
  for (size_t i = 0; i < 4; i++)
  {
    for (size_t j = 0; j < 4; j++)
    {
      res.addElement(i,this->getElement(i,j) * vec4.getElement(j));
    }
  }
  return res;
}

template <typename TYPE>
Mat4<TYPE> Mat4<TYPE>::operator*(Mat4& mat4)
{
  Mat4<TYPE> res;
  TYPE var = (TYPE)0;

  for (size_t i = 0; i < 4; i++)
  {
    for (size_t j = 0; j < 4; j++)
    {
      for (size_t k = 0; k < 4; k++)
      {
        var = var + this->getElement(i,k) * mat4.getElement(k,j);
      }
      res.setElement(i,j,var);
      var = (TYPE)0;
    }

  }
  return res;

}

template<typename TYPE>
Mat4<TYPE> Mat4<TYPE>::transpose()
{
  Mat4<TYPE> tmp;

  for (size_t i = 0; i < 4; i++)
  {
    for (size_t j = 0; j < 4; j++)
    {
      tmp.setElement(j,i, this->getElement(i,j));
    }
  }

  tmp.setElement(0,1,this->getElement(1,0));
  tmp.setElement(0,2,this->getElement(2,0));
  tmp.setElement(0,3,this->getElement(3,0));
  tmp.setElement(1,2,this->getElement(2,1));
  tmp.setElement(1,3,this->getElement(3,1));
  tmp.setElement(2,3,this->getElement(3,2));

  *this = tmp;
  return *this;
}
