#include <iostream>
#include <ostream>
#include "Vec3.hpp"

template <typename TYPE = float > class Mat3
{
public:
  Mat3<TYPE>(TYPE x00 = 1.0, TYPE x01 = 0.0, TYPE x02 = 0.0,
             TYPE y10 = 0.0, TYPE y11 = 1.0, TYPE y12 = 0.0,
             TYPE z20 = 0.0, TYPE z21 = 0.0, TYPE z22 = 1.0);
  Mat3<TYPE>(const Mat3<TYPE>& mat3);
  Mat3<TYPE> operator+(Mat3& mat3);
  Mat3<TYPE> operator-(Mat3& mat3);
  Mat3<TYPE> operator*(const float k);
  Mat3<TYPE> operator*(Mat3& mat3);
  Vec3<TYPE> operator*(Vec3<TYPE>& vec3);
  void setElement(int i, TYPE var){element[i] = var;}
  void setElement(int i,int j, TYPE var){element[i*3 + j] = var;}
  void addElement(int i,int j, TYPE var){element[i*3 + j] += var;}
  TYPE getElement(int i) const {return element[i];}
  TYPE getElement(int i, int j) const {return element[i*3 + j];}
  void setCol(int i, Vec3<TYPE>& vec3);
  Mat3<TYPE> transpose();
  TYPE* data(){return &(element[0]);}

private:
  TYPE element[9];
};

template <typename TYPE>
Mat3<TYPE> operator*(const float k,Mat3<TYPE>& mat3)
{
  Mat3<TYPE> res;
  for (size_t i = 0; i < 9; i++)
  {
    res.setElement(i,mat3.getElement(i) * k);
  }
  return res;
}


template <typename TYPE>
void Mat3<TYPE>::setCol(int i, Vec3<TYPE>& vec3)
{
  for (size_t k = 0; k < 3; k++)
  {
    setElement(k,i, vec3.getElement(k));
  }
}


template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Mat3<TYPE>& mat3)
{
  for (size_t i = 0; i < 7; i+=3)
  {
    Stream << "["<<mat3.getElement(i) << ";" << mat3.getElement(i+1) <<";"<<  mat3.getElement(i+2) <<"]" << std::endl;
  }
  return Stream;
}


template <typename TYPE>
Mat3<TYPE>::Mat3(TYPE x00, TYPE x01, TYPE x02,
                 TYPE y10, TYPE y11, TYPE y12,
                 TYPE z20, TYPE z21, TYPE z22)
{
  element[0] = x00; element[1] = x01; element[2] = x02;
  element[3] = y10; element[4] = y11; element[5] = y12;
  element[6] = z20; element[7] = z21; element[8] = z22;
}


template <typename TYPE>
Mat3<TYPE>::Mat3(const Mat3<TYPE> & mat3)
{
  for (size_t i = 0; i < 9; i++)
  {
    this->setElement(i,mat3.getElement(i));
  }
}


template <typename TYPE>
Mat3<TYPE> Mat3<TYPE>::operator+( Mat3& mat3)
{
  Mat3<TYPE> res;
  for (size_t i = 0; i < 9; i++)
  {
    res.setElement(i,mat3.getElement(i) + this->getElement(i));
  }
  return res;
}


template <typename TYPE>
Mat3<TYPE> Mat3<TYPE>::operator-( Mat3& mat3)
{
  Mat3<TYPE> res;
  for (size_t i = 0; i < 9; i++)
  {
    res.setElement(i,mat3.getElement(i) - this->getElement(i));
  }
  return res;
}



template <typename TYPE>
Mat3<TYPE> Mat3<TYPE>::operator*(const float k)
{
  Mat3<TYPE> res;
  for (size_t i = 0; i < 9; i++)
  {
    res.setElement(i,this->getElement(i) * k);
  }
  return res;
}


template <typename TYPE>
Vec3<TYPE> Mat3<TYPE>::operator*(Vec3<TYPE>& vec3)
{
  Vec3<TYPE> res;
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      res.addElement(i,this->getElement(i,j) * vec3.getElement(j));
    }
  }
  return res;
}

template <typename TYPE>
Mat3<TYPE> Mat3<TYPE>::operator*(Mat3& mat3)
{
  Mat3<TYPE> res;
  TYPE var = (TYPE)0;

  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      for (size_t k = 0; k < 3; k++)
      {
        var = var + this->getElement(i,k) * mat3.getElement(j,k);
      }
      res.setElement(i,j,var);
      var = (TYPE)0;
    }

  }
  return res;

}



template<typename TYPE>
Mat3<TYPE> Mat3<TYPE>::transpose()
{
  Mat3<TYPE> tmp;

  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      tmp.setElement(j,i, this->getElement(i,j));
    }
  }

  tmp.setElement(0,1,this->getElement(1,0));
  tmp.setElement(0,2,this->getElement(2,0));
  tmp.setElement(1,2,this->getElement(2,1));
  *this = tmp;
  return *this;
}
