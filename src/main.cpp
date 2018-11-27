#include<iostream>
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "Mat2.hpp"
#include "Mat3.hpp"
#include "Mat4.hpp"
#include "Transformation.hpp"

using namespace Transformation;

int main(int argc, char** argv)
{
  Vec2<float>  vec1(2,3);
  Vec2<float>  vec2(1,1);

  Vec3<float> vec3(2,3,4);
  Vec3<float> vec4(1,1,1);

  Vec4<float> vec5(2,3,4,5);
  Vec4<float> vec6(1,1,1,1);

  Mat2<float> mat1(1.0f,2.0f,
                   3.0f,4.0f);
  Mat2<float> mat2;

  Mat3<float> mat3(1.0f,2.0f,3.0f,
                   4.0f,5.0f,6.0f,
                   7.0f,8.0f,9.0f);
  Mat3<float> mat4;

  Mat4<float> mat5(-1.0f,0.0f,0.0f,0.0f,
                   0.0f,1.0f,0.0f,0.0f,
                   0.0f,0.0f,-1.0f,0.0f,
                   0.0f,0.0f,0.0f,1.0f);

  Mat4<float> mat6(1.0f,0.0f,0.0f,0.0f,
                   0.0f,1.0f,0.0f,0.0f,
                   0.0f,0.0f,1.0f,2.0f,
                   0.0f,0.0f,0.0f,1.0f);

  Translation<float> trans(vec3);


  std::cout << mat1 << std::endl;
  std::cout << mat1.transpose() << std::endl;

  std::cout << mat3 << std::endl;
  std::cout << mat3.transpose() << std::endl;
  std::cout << mat5 * mat6 << std::endl;
  std::cout << (mat5 * mat6 ).transpose()<< std::endl;

  std::cout << trans.getTranslation() << std::endl;

  return 1;
}
