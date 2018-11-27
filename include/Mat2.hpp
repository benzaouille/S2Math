#include <iostream>
#include <ostream>
#include "Vec2.hpp"

template <typename TYPE = float > class Mat2
{
public:
  Mat2<TYPE>(TYPE x00 = 1.0, TYPE x01 = 0.0,
             TYPE y10 = 0.0, TYPE y11 = 1.0);
  Mat2<TYPE>(const Mat2<TYPE>& mat2);
  Mat2<TYPE> operator+(Mat2& mat2);
  Mat2<TYPE> operator-(Mat2& mat2);
  Mat2<TYPE> operator*(const float k);
  Mat2<TYPE> operator*(Mat2& mat2);
  Vec2<TYPE> operator*(Vec2<TYPE>& vec2);
  void setElement(int i, TYPE var){element[i] = var;}
  void setElement(int i,int j, TYPE var){element[i*2 + j] = var;}
  void addElement(int i,int j, TYPE var){element[i*2 + j] += var;}
  TYPE getElement(int i) const {return element[i];}
  TYPE getElement(int i, int j) const {return element[i*2 + j];}
  void setCol(int i, Vec2<TYPE>& vec2);
  Mat2<TYPE> transpose();
  TYPE* data(){return &(element[0]);}

private:
  TYPE element[4];
};

template <typename TYPE>
Mat2<TYPE> operator*(const float k,Mat2<TYPE>& mat2)
{
  Mat2<TYPE> res;
  for (size_t i = 0; i < 4; i++)
  {
    res.setElement(i,mat2.getElement(i) * k);
  }
  return res;
}


template <typename TYPE>
void Mat2<TYPE>::setCol(int i, Vec2<TYPE>& vec2)
{
  for (size_t k = 0; k < 2; k++)
  {
    setElement(k,i, vec2.getElement(k));
  }
}

template <typename TYPE>
std::ostream& operator <<(std::ostream& Stream, const Mat2<TYPE>& mat2)
{
  for (size_t i = 0; i < 3; i+=2)
  {
    Stream << "["<<mat2.getElement(i) << ";" << mat2.getElement(i+1) << "]" << std::endl;
  }
  return Stream;
}
template <typename TYPE>
Mat2<TYPE>::Mat2(TYPE x00, TYPE x01,
                 TYPE y10, TYPE y11)
{
  element[0] = x00; element[1] = x01;
  element[2] = y10; element[3] = y11;

}


template <typename TYPE>
Mat2<TYPE>::Mat2(const Mat2<TYPE> & mat2)
{
  for (size_t i = 0; i < 4; i++)
  {
    this->setElement(i,mat2.getElement(i));
  }
}


template <typename TYPE>
Mat2<TYPE> Mat2<TYPE>::operator+( Mat2& mat2)
{
  Mat2<TYPE> res;
  for (size_t i = 0; i < 4; i++)
  {
    res.setElement(i,mat2.getElement(i) + this->getElement(i));
  }
  return res;
}


template <typename TYPE>
Mat2<TYPE> Mat2<TYPE>::operator-( Mat2& mat2)
{
  Mat2<TYPE> res;
  for (size_t i = 0; i < 4; i++)
  {
    res.setElement(i,mat2.getElement(i) - this->getElement(i));
  }
  return res;
}



template <typename TYPE>
Mat2<TYPE> Mat2<TYPE>::operator*(const float k)
{
  Mat2<TYPE> res;
  for (size_t i = 0; i < 4; i++)
  {
    res.setElement(i,this->getElement(i) * k);
  }
  return res;
}


template <typename TYPE>
Vec2<TYPE> Mat2<TYPE>::operator*(Vec2<TYPE>& vec2)
{
  Vec2<TYPE> res;
  for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      res.addElement(i,this->getElement(i,j) * vec2.getElement(j));
    }
  }
  return res;
}

template <typename TYPE>
Mat2<TYPE> Mat2<TYPE>::operator*(Mat2& mat2)
{
  Mat2<TYPE> res;
  TYPE var = (TYPE)0;

  /*for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      for (size_t idx = 0; idx < 2; idx++)
      {
        for (size_t jdx = 0; jdx < 2; jdx++)
        {
          var = var + this->getElement(i,j) * mat2.getElement(j,i);
          std::cout << "i j " << i << " " <<j<< " " << this->getElement(idx,jdx) * mat2.getElement(jdx,idx)<<std::endl;
        }
        res.setElement(i,j,var);
        var = (TYPE)0;
      }
    }
  }
  return res;*/


  for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      for (size_t k = 0; k < 2; k++)
      {
        var = var + this->getElement(i,k) * mat2.getElement(j,k);
      }
      res.setElement(i,j,var);
      var = (TYPE)0;
    }

  }
  return res;
}



template<typename TYPE>
Mat2<TYPE> Mat2<TYPE>::transpose()
{
  Mat2<TYPE> tmp;

  for (size_t i = 0; i < 2; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      tmp.setElement(j,i, this->getElement(i,j));
    }
  }

  tmp.setElement(0,1,this->getElement(1,0));// a voir si cela fonctionne...
  *this = tmp;
  return *this;
}
