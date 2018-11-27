#pragma once
#include<iostream>
#include"Mat4.hpp"

namespace Transformation
{
  template<typename TYPE = float>
  class Translation
  {
    public:
      Translation<TYPE>(TYPE x,TYPE y,TYPE z);
      Translation<TYPE>(Vec3<TYPE>& col);
      void updateTranslation(TYPE x,TYPE y,TYPE z);
      void updateTranslation(Vec3<TYPE>& col);
      Mat4<TYPE> getTranslation(){return _translation;}
    private:
      Mat4<TYPE> _translation;
  };
};

template<typename TYPE>
Transformation::Translation<TYPE>::Translation(TYPE x,TYPE y,TYPE z)
{
  Vec3<TYPE> col(TYPE x,TYPE y,TYPE z);
  _translation.setCol(3,col);
}

template<typename TYPE>
Transformation::Translation<TYPE>::Translation(Vec3<TYPE>& col)
{
  _translation.setCol(3,col);
}

template<typename TYPE>
void Transformation::Translation<TYPE>::updateTranslation(TYPE x,TYPE y,TYPE z)
{
  Vec3<TYPE> col(TYPE x,TYPE y,TYPE z);
  _translation.setCol(3,col);
}

template<typename TYPE>
void Transformation::Translation<TYPE>::updateTranslation(Vec3<TYPE>& col)
{
  _translation.setCol(3,col);
}
