#include <iostream>
#include <Eigen/Dense>

/*
    逐元素运算
            Matrix类可以通过调用对应成员函数实现逐元素运算，此时返回值类型为Matrix类：

    mat1.cwiseMin(mat2)                 mat1.cwiseMin(scalar)
    mat1.cwiseMax(mat2)                 mat1.cwiseMax(scalar)
    mat1.cwiseAbs2()
    mat1.cwiseAbs()
    mat1.cwiseSqrt()
    mat1.cwiseInverse()
    mat1.cwiseProduct(mat2)
    mat1.cwiseQuotient(mat2)
    mat1.cwiseEqual(mat2)               mat1.cwiseEqual(scalar)
    mat1.cwiseNotEqual(mat2)
    也可以将Matrix类转换为Array类后调用对应成员函数实现逐元素运算，此时返回值类型为Array类：

    mat1.array().min(mat2.array())      mat1.array().min(scalar)
    mat1.array().max(mat2.array())      mat1.array().max(scalar)
    mat1.array().abs2()
    mat1.array().abs()
    mat1.array().sqrt()
    mat1.array().inverse()
    mat1.array() * mat2.array()
    mat1.array() / mat2.array()
    mat1.array() == mat2.array()        mat1.array() == scalar
    mat1.array() != mat2.array()
 */


/*
    mat1.cwiseMin(mat2)  // 对应 mat1 和 mat2 逐元素取最小值
    mat1.cwiseMax(mat2)  // 对应 mat1 和 mat2 逐元素取最大值
    mat1.cwiseMin(scalar)  // 每个元素与 scalar 比较，取较小值
    mat1.cwiseMax(scalar)  // 每个元素与 scalar 比较，取较大值

    mat1.cwiseAbs()   // 逐元素取绝对值
    mat1.cwiseAbs2()  // 逐元素平方
    mat1.cwiseSqrt()  // 逐元素开方
    mat1.cwiseInverse()  // 逐元素求倒数（1.0 / mat1）

    mat1.cwiseProduct(mat2)   // 逐元素乘法（对应位置相乘）
    mat1.cwiseQuotient(mat2)  // 逐元素除法（对应位置相除）

    mat1.cwiseEqual(mat2)  // 逐元素是否相等，返回布尔矩阵
    mat1.cwiseNotEqual(mat2)  // 逐元素是否不等，返回布尔矩阵
*/


void demo01()
{
    using namespace Eigen;

    Eigen::Matrix3f mat1, mat2;
    mat1 << 1, -2, 3,
            4, -5, 6,
            7, -8, 9;

    mat2 << 9, 8, 7,
            6, 5, 4,
            3, 2, 1;

    float scalar = 2.0;

    std::cout << "mat1:\n" << mat1 << "\n\n";
    std::cout << "mat2:\n" << mat2 << "\n\n";

    // 逐元素最小/最大值
    std::cout << "逐元素最小值 (mat1, mat2):\n" << mat1.cwiseMin(mat2) << "\n\n";
    std::cout << "逐元素最大值 (mat1, mat2):\n" << mat1.cwiseMax(mat2) << "\n\n";
    std::cout << "逐元素最小值 (mat1, scalar):\n" << mat1.cwiseMin(scalar) << "\n\n";
    std::cout << "逐元素最大值 (mat1, scalar):\n" << mat1.cwiseMax(scalar) << "\n\n";

    // 逐元素绝对值、平方、平方根
    std::cout << "逐元素绝对值:\n" << mat1.cwiseAbs() << "\n\n";
    std::cout << "逐元素平方:\n" << mat1.cwiseAbs2() << "\n\n";
    std::cout << "逐元素平方根:\n" << mat1.cwiseSqrt() << "\n\n";

    // 逐元素倒数
    std::cout << "逐元素倒数:\n" << mat1.cwiseInverse() << "\n\n";

    // 逐元素乘法和除法
    std::cout << "逐元素乘法 (mat1 .* mat2):\n" << mat1.cwiseProduct(mat2) << "\n\n";
    std::cout << "逐元素除法 (mat1 ./ mat2):\n" << mat1.cwiseQuotient(mat2) << "\n\n";

    // 逐元素相等、不等判断
    std::cout << "逐元素相等 (mat1 == mat2):\n" << (mat1.cwiseEqual(mat2)) << "\n\n";
    std::cout << "逐元素不等 (mat1 != mat2):\n" << (mat1.cwiseNotEqual(mat2)) << "\n\n";

    // **转换为 Array 进行逐元素运算**
    std::cout << "转换为 Array 后的最小值 (mat1, mat2):\n" << mat1.array().min(mat2.array()) << "\n\n";
    std::cout << "转换为 Array 后的最大值 (mat1, scalar):\n" << mat1.array().max(scalar) << "\n\n";
    std::cout << "转换为 Array 后的平方:\n" << mat1.array().abs2() << "\n\n";
    std::cout << "转换为 Array 后的平方根:\n" << mat1.array().sqrt() << "\n\n";
    std::cout << "转换为 Array 后的倒数:\n" << mat1.array().inverse() << "\n\n";
    std::cout << "转换为 Array 后的逐元素乘法:\n" << mat1.array() * mat2.array() << "\n\n";
    std::cout << "转换为 Array 后的逐元素除法:\n" << mat1.array() / mat2.array() << "\n\n";
    std::cout << "转换为 Array 后的逐元素相等:\n" << (mat1.array() == mat2.array()) << "\n\n";
    std::cout << "转换为 Array 后的逐元素不等:\n" << (mat1.array() != mat2.array()) << "\n\n";

}

// Array类
// 逐元素运算
// 包括算术运算符、比较运算符、常用数学函数等：

/*
    array1.abs2()
    array1.abs()                  abs(array1)
    array1.sqrt()                 sqrt(array1)
    array1.log()                  log(array1)
    array1.log10()                log10(array1)
    array1.exp()                  exp(array1)
    array1.pow(array2)            pow(array1,array2)
    array1.pow(scalar)            pow(array1,scalar)
                                  pow(scalar,array2)
    array1.square()
    array1.cube()
    array1.inverse()

    array1.sin()                  sin(array1)
    array1.cos()                  cos(array1)
    array1.tan()                  tan(array1)
    array1.asin()                 asin(array1)
    array1.acos()                 acos(array1)
    array1.atan()                 atan(array1)
    array1.sinh()                 sinh(array1)
    array1.cosh()                 cosh(array1)
    array1.tanh()                 tanh(array1)
    array1.arg()                  arg(array1)

    array1.floor()                floor(array1)
    array1.ceil()                 ceil(array1)
    array1.round()                round(aray1)

    array1.isFinite()             isfinite(array1)
    array1.isInf()                isinf(array1)
    array1.isNaN()                isnan(array1)
 * */

void demo02()
{
    Eigen::Array3f array1;
    Eigen::Array3f array2;
    float scalar = 2.0;

    array1 << -1.0, 0.5, 4.0;
    array2 << 2.0, 3.0, 0.5;

    std::cout << "array1:\n" << array1 << "\n\n";
    std::cout << "array2:\n" << array2 << "\n\n";

    // 绝对值、平方、立方
    std::cout << "abs(array1):\n" << array1.abs() << "\n\n";
    std::cout << "array1.abs2():\n" << array1.abs2() << "\n\n";
    std::cout << "array1.square():\n" << array1.square() << "\n\n";
    std::cout << "array1.cube():\n" << array1.cube() << "\n\n";

    // 开平方、倒数
    std::cout << "sqrt(array1):\n" << array1.sqrt() << "\n\n";
    std::cout << "array1.inverse():\n" << array1.inverse() << "\n\n";

    // 指数和对数运算
    std::cout << "log(array1):\n" << array1.log() << "\n\n";
    std::cout << "log10(array1):\n" << array1.log10() << "\n\n";
    std::cout << "exp(array1):\n" << array1.exp() << "\n\n";

    // 幂运算
    std::cout << "pow(array1, array2):\n" << array1.pow(array2) << "\n\n";
    std::cout << "pow(array1, scalar):\n" << array1.pow(scalar) << "\n\n";
    std::cout << "pow(scalar, array2):\n" << scalar * array2 << "\n\n";

    // 三角函数
    std::cout << "sin(array1):\n" << array1.sin() << "\n\n";
    std::cout << "cos(array1):\n" << array1.cos() << "\n\n";
    std::cout << "tan(array1):\n" << array1.tan() << "\n\n";
    std::cout << "asin(array1):\n" << array1.asin() << "\n\n";
    std::cout << "acos(array1):\n" << array1.acos() << "\n\n";
    std::cout << "atan(array1):\n" << array1.atan() << "\n\n";

    // 双曲函数
    std::cout << "sinh(array1):\n" << array1.sinh() << "\n\n";
    std::cout << "cosh(array1):\n" << array1.cosh() << "\n\n";
    std::cout << "tanh(array1):\n" << array1.tanh() << "\n\n";

    // 取整操作
    std::cout << "floor(array1):\n" << array1.floor() << "\n\n";
    std::cout << "ceil(array1):\n" << array1.ceil() << "\n\n";
    std::cout << "round(array1):\n" << array1.round() << "\n\n";

    // 数值检查
    std::cout << "isFinite(array1):\n" << array1.isFinite() << "\n\n";
    std::cout << "isInf(array1):\n" << array1.isInf() << "\n\n";
    std::cout << "isNaN(array1):\n" << array1.isNaN() << "\n\n";

}


